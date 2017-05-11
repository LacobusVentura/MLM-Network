/*!
	\file NetworkWriterDataBase.cpp
	\brief Network Writer Object Interface (SQLite3 Database)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/


#include "DebugLogger.hpp"
#include "Exception.hpp"
#include "Serializable.hpp"
#include "Network.hpp"
#include "NetworkWriterDataBase.hpp"
#include "CustomerWriterDataBase.hpp"
#include "DataBaseStatement.hpp"


namespace MLM
{

	NetworkWriterDataBase::NetworkWriterDataBase( DataBaseConnection& conn ) :
		m_conn( conn )
	{
	}


	NetworkWriterDataBase::~NetworkWriterDataBase( void )
	{
	}


	void NetworkWriterDataBase::writeObject( const Serializable * s )
	{
		const Network & net = dynamic_cast<const Network&>( *s );

		if( net.id() < 0 )
			throwex( RunTimeException("Invalid Network Id") );

		if( !net.isModified() )
			return;

		CustomerWriterDataBase cstmrwr( m_conn );
		DataBaseStatement * stmnt = NULL;
		int affected = 0;

		m_conn.beginTransaction();

		stmnt = m_conn.prepare( "UPDATE tb_network SET name = @name, description = @desc WHERE id = @id;" );

		stmnt->setAttribute( "@name", net.name() );
		stmnt->setAttribute( "@desc", net.description() );
		stmnt->setAttribute( "@id", net.id() );

		affected = stmnt->execute();

		delete stmnt;

		if( affected <= 0 )
		{
			stmnt = m_conn.prepare( "INSERT INTO tb_network ( id, name, description ) VALUES ( @id, @name, @desc );" );

			stmnt->setAttribute( "@id", net.id() );
			stmnt->setAttribute( "@name", net.name() );
			stmnt->setAttribute( "@desc", net.description() );

			affected = stmnt->execute();

			delete stmnt;
		}

		if( affected <= 0 )
		{
			m_conn.rollbackTransaction();
			throwex( DataBaseException( "Can't Write Network Object Into DataBase." ) );
		}

		std::vector<Customer*> bal = net.balancedTree().nodeList();

		for( std::size_t i = 0; i < bal.size(); i++ )
			if( bal[i]->isModified() )
				bal[i]->writeTo( &cstmrwr );


		std::stringstream ss;

		ss << "DELETE FROM tb_customer WHERE id_network = " << net.id() << " AND id NOT IN ( ";

		for( std::size_t i = 0; i < bal.size(); i++ )
		{
			if( i > 0 )
				ss << ", ";

			ss << bal[i]->id();
		}

		ss << " );";

		affected = m_conn.execute( ss.str() );

		m_conn.commitTransaction();
	}
}

/* $Id: NetworkWriterDataBase.cpp 370 2017-03-30 21:30:15Z tiago.ventura $ */
