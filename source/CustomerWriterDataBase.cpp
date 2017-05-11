/*!
	\file CustomerWriterDataBase.cpp
	\brief Customer Writer Object Interface (SQLite3 Database)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include "Exception.hpp"
#include "Serializable.hpp"
#include "Network.hpp"
#include "CustomerWriterDataBase.hpp"
#include "DataBaseStatement.hpp"


namespace MLM
{

	CustomerWriterDataBase::CustomerWriterDataBase( DataBaseConnection& conn ) :
		m_conn( conn )
	{
	}


	CustomerWriterDataBase::~CustomerWriterDataBase( void )
	{
	}


	void CustomerWriterDataBase::writeObject( const Serializable * s )
	{
		const Customer & cstmr = dynamic_cast<const Customer&>( *s );
		
		if( cstmr.id() < 0 )
			throwex( RunTimeException("Invalid Customer Id") );

		if( cstmr.network() < 0 )
			throwex( RunTimeException("Invalid Customer Network Id") );

		DataBaseStatement * stmnt = NULL;
		int affected = 0;

		stmnt = m_conn.prepare( "UPDATE "
								"	tb_customer "
								"SET "
								"	id_invitation = @id_invitation, "
								"	id_overflow = @id_overflow, "
								"	n_invitation_depth = @n_invitation_depth, "
								"	n_overflow_depth = @n_overflow_depth, "
								"	vl_score = @vl_score, "
								"	st_active = @st_active "
								"WHERE "
								"	id_network = @id_network AND "
								"	id = @id;" );

		stmnt->setAttribute( "@id_invitation", cstmr.invitationParent() );
		stmnt->setAttribute( "@id_overflow", cstmr.overflowParent() );
		stmnt->setAttribute( "@n_invitation_depth", cstmr.invitationDepth() );
		stmnt->setAttribute( "@n_overflow_depth", cstmr.overflowDepth() );
		stmnt->setAttribute( "@vl_score", cstmr.score() );
		stmnt->setAttribute( "@st_active", cstmr.active() );
		stmnt->setAttribute( "@id_network", cstmr.network() );
		stmnt->setAttribute( "@id", cstmr.id() );

		affected = stmnt->execute();

		delete stmnt;

		if( affected <= 0 )
		{
			stmnt = m_conn.prepare( "INSERT INTO tb_customer "
									"	( id_network, id, id_invitation, id_overflow, n_invitation_depth, n_overflow_depth, vl_score, st_active ) "
									"VALUES "
									"	( @id_network, @id, @id_invitation, @id_overflow, @n_invitation_depth, @n_overflow_depth, @vl_score, @st_active );" );

			stmnt->setAttribute( "@id_network", cstmr.network() );
			stmnt->setAttribute( "@id", cstmr.id() );
			stmnt->setAttribute( "@id_invitation", cstmr.invitationParent() );
			stmnt->setAttribute( "@id_overflow", cstmr.overflowParent() );
			stmnt->setAttribute( "@n_invitation_depth", cstmr.invitationDepth() );
			stmnt->setAttribute( "@n_overflow_depth", cstmr.overflowDepth() );
			stmnt->setAttribute( "@vl_score", cstmr.score() );
			stmnt->setAttribute( "@st_active", cstmr.active() );

			affected = stmnt->execute();

			delete stmnt;
		}

		if( affected <= 0 )
			throwex( DataBaseException( "Can't write Customer Object into DataBase" ) );

		cstmr.resetModified();
	}
}

/* $Id: CustomerWriterDataBase.cpp 428 2017-05-03 01:34:14Z tiago.ventura $ */
