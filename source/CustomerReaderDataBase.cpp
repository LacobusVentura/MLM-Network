/*!
	\file CustomerReaderDataBase.cpp
	\brief Network Reader Object Implementation (DataBase)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include "Exception.hpp"
#include "Serializable.hpp"
#include "Network.hpp"
#include "DataBaseStatement.hpp"
#include "CustomerReaderDataBase.hpp"

namespace MLM
{

	CustomerReaderDataBase::CustomerReaderDataBase( DataBaseConnection & conn ) :
		m_conn( conn )
	{
	}


	CustomerReaderDataBase::~CustomerReaderDataBase( void )
	{
	}


	void CustomerReaderDataBase::readObject( Serializable * s )
	{
		Customer & cstmr = dynamic_cast<Customer&>(*s);
		DataBaseStatement * stmnt = NULL;
		
		if( cstmr.id() < 0 )
			throwex( RunTimeException("Invalid Customer Id") );
		
		if( cstmr.network() < 0 )
			throwex( RunTimeException("Invalid Customer Network Id") );

		stmnt = m_conn.prepare( "SELECT "
								"	id_invitation, "
								"	n_invitation_depth, "
								"	id_overflow, "
								"	n_overflow_depth, "
								"	vl_score, "
								"	st_active, "
								"	tm_creation "
								"FROM "
								"	tb_customer "
								"WHERE "
								"	id_network = @id_network AND "
								"	id = @id;" );

		stmnt->setAttribute( "@id", cstmr.id() );
		stmnt->setAttribute( "@id_network", cstmr.network() );

		if( !stmnt->fetch() )
		{
			delete stmnt;
			throwex( DataBaseException("Customer not found in DataBase") );
		}

		cstmr.invitationParent( stmnt->getIntColumn( "id_invitation" ) );
		cstmr.invitationDepth( stmnt->getIntColumn( "n_invitation_depth" ) );
		cstmr.overflowParent( stmnt->getIntColumn( "id_overflow" ) );
		cstmr.overflowDepth( stmnt->getIntColumn( "n_overflow_depth" ) );
		cstmr.score( stmnt->getDoubleColumn( "vl_score" ) );
		cstmr.active( stmnt->getIntColumn( "st_active" ) ? true : false );
		cstmr.creation( stmnt->getInt64Column( "tm_creation" ) );

		cstmr.resetModified();
	}

}

/* $Id: CustomerReaderDataBase.cpp 366 2017-03-30 00:42:37Z tiago.ventura $ */
