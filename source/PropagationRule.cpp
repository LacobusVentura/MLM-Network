/*!
	\file PropagationRule.cpp
	\brief Implementation of a Propagation Rule
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include <string>
#include <vector>
#include <algorithm>

#include "PropagationRule.hpp"
#include "PropagationStep.hpp"

namespace MLM
{

	PropagationRule::PropagationRule( void ) :
		m_id(-1)
	{
	}


	PropagationRule::PropagationRule( int id ) :
		m_id(id)
	{
	}
	
	
	PropagationRule::PropagationRule( int id, std::string name ) :
		m_id(id),
		m_name(name)
	{
	}


	PropagationRule::PropagationRule( const PropagationRule &obj ) :
		m_id(obj.m_id),
		m_name(obj.m_name),
		m_description(obj.m_description),
		m_steps(obj.m_steps)
	{
	}
			

	PropagationRule::~PropagationRule( void )
	{
	}
	

	PropagationRule& PropagationRule::operator=( const PropagationRule& obj )
	{
		m_id = obj.m_id;
		m_name = obj.m_name;
		m_description = obj.m_description;
		m_steps = obj.m_steps;
		
		return *this;
	}


	int PropagationRule::id( void ) const
	{
		return m_id;
	}


	void PropagationRule::id( int id )
	{
		m_id = id;
	}


	std::string PropagationRule::name( void ) const
	{
		return m_name;
	}


	void PropagationRule::name( const std::string& name  )
	{
		m_name = name;
	}


	std::string PropagationRule::description( void ) const
	{
		return m_description;
	}


	void PropagationRule::description( const std::string& desc )
	{
		m_description = desc;
	}


	std::vector<PropagationStep> PropagationRule::stepList( void ) const
	{
 		return m_steps;
	}


	void PropagationRule::stepList( const std::vector<PropagationStep>& lst )
	{
		m_steps = lst;
	}

}

/* $Id: PropagationRule.cpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
