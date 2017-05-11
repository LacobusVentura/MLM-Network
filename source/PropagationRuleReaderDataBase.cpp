/*!
	\file PropagationRuleReaderDataBase.cpp
	\brief Propagation Rule Reader Object Implementation (DataBase Serialization)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include "DebugLogger.hpp"
#include "Exception.hpp"
#include "Serializable.hpp"
#include "DataBaseConnection.hpp"
#include "DataBaseStatement.hpp"
#include "DataBaseColumn.hpp"
#include "PropagationRule.hpp"

#include "PropagationRuleReaderDataBase.hpp"

namespace MLM
{

	PropagationRuleReaderDataBase::PropagationRuleReaderDataBase( DataBaseConnection& conn ) :
		m_conn( conn )
	{
	}


	PropagationRuleReaderDataBase::~PropagationRuleReaderDataBase( void )
	{
	}


	void PropagationRuleReaderDataBase::readObject( Serializable * s )
	{
		PropagationRule & rule = dynamic_cast<PropagationRule&>(*s);

		DataBaseStatement * stmnt = NULL;
		std::vector<PropagationStep> steps;

		stmnt = m_conn.prepare( "SELECT "
								"	name, "
								"	description "
								"FROM "
								"	tb_propagation_rule "
								"WHERE "
								"	id = @id;" );

		stmnt->setAttribute( "@id", rule.id() );

		if( !stmnt->fetch() )
			throwex( DataBaseException("Propagation Rule not found in database.") );

		rule.name( stmnt->getTextColumn( "name" ) );
		rule.description( stmnt->getTextColumn( "description" ) );

		delete stmnt;

		stmnt = m_conn.prepare( "SELECT "
								"	n_sequence, "
								"	vl_percentage, "
								"	n_minchild "
								"FROM "
								"	tb_propagation_step "
								"WHERE "
								"	id_rule = @id_rule "
								"ORDER BY "
								"	n_sequence ASC;" );

		stmnt->setAttribute( "@id_rule", rule.id() );

		while( stmnt->fetch() )
		{
			PropagationStep stp;

			stp.sequence( stmnt->getIntColumn( "n_sequence" ) );
			stp.percentage( stmnt->getDoubleColumn( "vl_percentage" ) );
			stp.minInvitations( stmnt->getIntColumn( "n_minchild" ) );

			steps.push_back( stp );
		}

		delete stmnt;

		rule.stepList( steps );
	}
}

/* $Id: PropagationRuleReaderDataBase.cpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
