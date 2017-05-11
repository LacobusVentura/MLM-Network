/*!
	\file NetworkReaderDataBase.cpp
	\brief Network Reader Object Implementation (DataBase)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include "DebugLogger.hpp"
#include "Exception.hpp"
#include "Serializable.hpp"
#include "Network.hpp"
#include "NetworkReaderDataBase.hpp"
#include "CustomerReaderDataBase.hpp"
#include "DataBaseStatement.hpp"
#include "DataBaseColumn.hpp"

namespace MLM
{

	NetworkReaderDataBase::NetworkReaderDataBase( DataBaseConnection & conn ) :
		m_conn( conn )
	{
	}


	NetworkReaderDataBase::~NetworkReaderDataBase( void )
	{
	}


	void NetworkReaderDataBase::readObject( Serializable * s )
	{
		Network & net = dynamic_cast<Network&>(*s);

		DataBaseStatement * stmnt = NULL;

		CustomerReaderDataBase cstmrrd( m_conn );

		Tree<Customer> & invtree = net.m_invitations;
		Tree<Customer> & baltree = net.m_balanced;

		stmnt = m_conn.prepare( "SELECT "
								"	name, "
								"	description, "
								"	tm_creation "
								"FROM "
								"	tb_network "
								"WHERE "
								"	id = @id;" );

		stmnt->setAttribute( "@id", net.id() );

		if( !stmnt->fetch() )
		{
			delete stmnt;

			std::stringstream ss;
			ss << "Network id=" << net.id() << " not found in database.";

			throwex( DataBaseException( ss.str() ) );
		}

		net.name( stmnt->getTextColumn( "name" ) );
		net.description( stmnt->getTextColumn( "description" ) );
		net.creation( stmnt->getInt64Column( "tm_creation" ) );

		delete stmnt;
		
		net.m_inactive_customer_count = 0;
		
		stmnt = m_conn.prepare( "SELECT "
								"	id, "
								"	id_invitation, "
								"	n_invitation_depth "
								"FROM "
								"	tb_customer "
								"WHERE "
								"	id_network = @id "
								"ORDER BY "
								"	n_invitation_depth, "
								"	tm_creation, "
								"	id;" );

		stmnt->setAttribute( "@id", net.id() );

		while( stmnt->fetch() )
		{
			if( !invtree.root() )
			{
				Customer & cstmr = invtree.root( Customer( stmnt->getIntColumn( "id" ) ) );

				cstmr.network( net.id() );
				cstmr.readFrom( &cstmrrd );
			}
			else
			{
				Customer * prnt = invtree.search( Customer( stmnt->getIntColumn( "id_invitation" ) ) );

				if( !prnt )
				{
					baltree.clear();
					invtree.clear();
					delete stmnt;

					throwex( NullPointerException("Erro Reading Invitation Tree From Data Base.") );
				}

				Customer & cstmr = prnt->addChild( Customer( stmnt->getIntColumn( "id" ) ) );

				cstmr.network( net.id() );
				cstmr.readFrom( &cstmrrd );
			}
		}

		delete stmnt;

		stmnt = m_conn.prepare( "SELECT "
								"	id, "
								"	id_overflow, "
								"	n_overflow_depth "
								"FROM "
								"	tb_customer "
								"WHERE "
								"	id_network = @id "
								"ORDER BY "
								"	n_overflow_depth, "
								"	tm_creation, "
								"	id;" );

		stmnt->setAttribute( "@id", net.id() );

		while( stmnt->fetch() )
		{
			if( !baltree.root() )
			{
				Customer & cstmr = baltree.root( Customer( stmnt->getIntColumn( "id" ) ) );

				cstmr.network( net.id() );
				cstmr.readFrom( &cstmrrd );

				if( !cstmr.active() )
					net.m_inactive_customer_count++;
			}
			else
			{
				Customer * prnt = baltree.search( Customer( stmnt->getIntColumn( "id_overflow" ) ) );

				if( !prnt )
				{
					baltree.clear();
					invtree.clear();
					delete stmnt;

					throwex( NullPointerException("Erro Reading Balanced Tree From Data Base.") );
				}

				Customer & cstmr = prnt->addChild( Customer( stmnt->getIntColumn( "id" ) ) );

				cstmr.network( net.id() );
				cstmr.readFrom( &cstmrrd );

				if( !cstmr.active() )
					net.m_inactive_customer_count++;
			}
		}

		delete stmnt;

		if( baltree.nodeCount() != invtree.nodeCount() )
		{
			baltree.clear();
			invtree.clear();

			throwex( NullPointerException("Malformed Trees in Data Base.") );
		}
		
		net.m_customer_count = baltree.nodeCount();

		net.resetModified();
	}

}

/* $Id: NetworkReaderDataBase.cpp 428 2017-05-03 01:34:14Z tiago.ventura $ */
