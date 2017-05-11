/*!
	\file PropagationRuleWriterJSON.cpp
	\brief Propagation Rule Writer Object Implementation (JSON Format)
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
#include "PropagationRuleWriterJSON.hpp"

namespace MLM
{

	PropagationRuleWriterJSON::PropagationRuleWriterJSON( std::ostream& os ) :
		m_ostream( os )
	{
	}


	PropagationRuleWriterJSON::~PropagationRuleWriterJSON( void )
	{
	}


	void PropagationRuleWriterJSON::writeObject( const Serializable * s )
	{
		const PropagationRule & rule = dynamic_cast<const PropagationRule&>( *s );

		std::vector<PropagationStep> steps = rule.stepList();

		for( std::size_t i = 0; i < steps.size(); i++ )
		{
			PropagationStep & step = steps[i];
			(void) step;
		}
	}
}

/* $Id: PropagationRuleWriterJSON.cpp 439 2017-05-04 19:50:36Z tiago.ventura $ */
