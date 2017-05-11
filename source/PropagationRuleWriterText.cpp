/*!
	\file PropagationRuleWriterText.cpp.cpp
	\brief Propagation Rule Writer Object Implementation (Text Format)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

#include "Exception.hpp"
#include "Writer.hpp"
#include "Serializable.hpp"
#include "PropagationRule.hpp"
#include "PropagationRuleWriterText.hpp"

namespace MLM
{

	PropagationRuleWriterText::PropagationRuleWriterText( std::ostream& os ) :
		m_ostream( os )
	{
	}


	PropagationRuleWriterText::~PropagationRuleWriterText( void )
	{
	}


	void PropagationRuleWriterText::writeObject( const Serializable * s )
	{
		const PropagationRule & rule = dynamic_cast<const PropagationRule&>( *s );

		std::vector<PropagationStep> steps = rule.stepList();

		m_ostream << std::endl << "PROPAGATION RULE INFO" << std::endl << std::endl;
		
		m_ostream << "	ID: " << rule.id() << std::endl;
		m_ostream << "	Name: " << rule.name() << std::endl;
		m_ostream << "	Description: " << rule.description() << std::endl;
		m_ostream << "	Steps Count: " << steps.size() << std::endl << std::endl;

		m_ostream << "	Details: " << std::endl;

		for( std::size_t i = 0; i < steps.size(); i++ )
		{
			PropagationStep & step = steps[i];
			m_ostream << "		* seq=" << step.sequence() << ", value=" << step.percentage() << "%, min=" << step.minInvitations() << std::endl;
		}
	}
}

/* $Id: PropagationRuleWriterText.cpp 441 2017-05-05 01:34:20Z tiago.ventura $ */
