/*!
	\file PropagationStep.cpp
	\brief PropagationStep Implementation
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include "PropagationStep.hpp"

namespace MLM
{

	PropagationStep::PropagationStep( void ) :
		m_id_rule(-1),
		m_sequence(-1),
		m_percentage(0.0),
		m_invitations(0)
	{
	}


	PropagationStep::PropagationStep( int id_rule, int seq ) :
		m_id_rule(id_rule),
		m_sequence(seq),
		m_percentage(0.0),
		m_invitations(0)
	{
	}


	PropagationStep::PropagationStep( int id_rule, int seq, double val, int min ) :
		m_id_rule(id_rule),
		m_sequence(seq),
		m_percentage(val),
		m_invitations(min)
	{
	}


	PropagationStep::PropagationStep( const PropagationStep &other ) :
		m_id_rule(other.m_id_rule),
		m_sequence(other.m_sequence),
		m_percentage(other.m_percentage),
		m_invitations(other.m_invitations)
	{
	}


	PropagationStep::~PropagationStep( void )
	{
	}


	PropagationStep& PropagationStep::operator=( const PropagationStep& other )
	{
		m_id_rule = other.m_id_rule;
		m_sequence = other.m_sequence;
		m_percentage = other.m_percentage;
		m_invitations = other.m_invitations;

		return *this;
	}


	bool PropagationStep::operator<(const PropagationStep &other) const
	{
		return (m_sequence < other.m_sequence);
	}


	bool PropagationStep::operator>(const PropagationStep &other) const
	{
		return (m_sequence > other.m_sequence);
	}


	int PropagationStep::idRule( void ) const
	{
		return m_id_rule;
	}


	void PropagationStep::idRule( int id )
	{
		m_id_rule = id;
	}


	void PropagationStep::sequence( int seq )
	{
		m_sequence = seq;
	}


	int PropagationStep::sequence( void ) const
	{
		return m_sequence;
	}


	double PropagationStep::percentage( void ) const
	{
		return m_percentage;
	}


	void PropagationStep::percentage( double val )
	{
		m_percentage = val;
	}


	int PropagationStep::minInvitations( void ) const
	{
		return m_invitations;
	}


	void PropagationStep::minInvitations( int n )
	{
		m_invitations = n;
	}

}

/* $Id: PropagationStep.cpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
