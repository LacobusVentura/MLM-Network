/*!
	\file Customer.cpp
	\brief Customer Object Implementation
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include <iostream>

#include "Exception.hpp"
#include "Customer.hpp"
#include "Network.hpp"

namespace MLM
{

	Customer::Customer( void ) :
		TreeNode<Customer>(),
		m_id(-1),
		m_score(0.0),
		m_active(false),
		m_creation(-1),
		m_id_network(-1),
		m_id_invitation_parent(-1),
		m_id_overflow_parent(-1),
		m_invitation_depth(-1),
		m_overflow_depth(-1)
	{
	}


	Customer::Customer( int id ) :
		TreeNode<Customer>(),
		m_id(id),
		m_score(0.0),
		m_active(false),
		m_creation(-1),
		m_id_network(-1),
		m_id_invitation_parent(-1),
		m_id_overflow_parent(-1),
		m_invitation_depth(-1),
		m_overflow_depth(-1)
	{
	}


	Customer::Customer( const Customer &obj ) :
		TreeNode<Customer>(obj),
		m_id(obj.m_id),
		m_score(obj.m_score),
		m_active(obj.m_active),
		m_creation(obj.m_creation),
		m_id_network(obj.m_id_network),
		m_id_invitation_parent(obj.m_id_invitation_parent),
		m_id_overflow_parent(obj.m_id_overflow_parent),
		m_invitation_depth(obj.m_invitation_depth),
		m_overflow_depth(obj.m_overflow_depth)
	{
	}


	Customer::~Customer( void )
	{
	}


	Customer& Customer::operator=( const Customer& obj )
	{
		m_id = obj.m_id;
		m_score = obj.m_score;
		m_active = obj.m_active;
		m_creation = obj.m_creation;
		m_id_network = obj.m_id_network;
		m_id_invitation_parent = obj.m_id_invitation_parent;
		m_id_overflow_parent = obj.m_id_overflow_parent;
		m_invitation_depth = obj.m_invitation_depth;
		m_overflow_depth = obj.m_overflow_depth;
		return *this;
	}


	bool Customer::operator==(const Customer & other) const
	{
		return (this->m_id == other.m_id);
	}


	bool Customer::operator!=(const Customer & other) const
	{
		return (this->m_id != other.m_id);
	}


	int Customer::id( void ) const
	{
		return m_id;
	}


	void Customer::id( int id )
	{
		m_id = id;
		setModified();
	}


	int Customer::network( void ) const
	{
		return m_id_network;
	}


	void Customer::network( int id )
	{
		m_id_network = id;
		setModified();
	}


	int Customer::invitationParent( void ) const
	{
		return m_id_invitation_parent;
	}


	void Customer::invitationParent( int id )
	{
		m_id_invitation_parent = id;
		setModified();
	}


	int Customer::overflowParent( void ) const
	{
		return m_id_overflow_parent;
	}


	void Customer::overflowParent( int id )
	{
		m_id_overflow_parent = id;
		setModified();
	}


	int Customer::invitationDepth( void ) const
	{
		return m_invitation_depth;
	}


	void Customer::invitationDepth( int n )
	{
		m_invitation_depth = n;
		setModified();
	}


	int Customer::overflowDepth( void ) const
	{
		return m_overflow_depth;
	}


	void Customer::overflowDepth( int n )
	{
		m_overflow_depth = n;
		setModified();
	}


	bool Customer::active( void ) const
	{
		return m_active;
	}


	void Customer::active( bool active )
	{
		m_active = active;
		setModified();
	}


	void Customer::activate( void )
	{
		m_active = true;
		setModified();
	}


	void Customer::deactivate( void )
	{
		m_active = false;
		setModified();
	}


	double Customer::score( void ) const
	{
		return m_score;
	}


	void Customer::score( double s )
	{
		m_score = s;
		setModified();
	}

	std::time_t Customer::creation( void ) const
	{
		return m_creation;
	}


	void Customer::creation( std::time_t ts )
	{
		m_creation = ts;
		setModified();
	}


	void Customer::scoreSubtract( double s )
	{
		double newscore = m_score - s;

		if( newscore < 0.0 )
			throwex( UnderFlowException( "Not enough score to subtract." ) );

		m_score = newscore;
		setModified();
	}


	void Customer::scoreAdd( double s )
	{
		m_score += s;
		setModified();
	}


	std::ostream& operator<<( std::ostream& os, const Customer& obj )
	{
		os  << "cstmr[ net=" << obj.network()
			<< ", id=" << obj.m_id
			<< ", invitation=" << obj.invitationParent()
			<< ", idepth=" << obj.invitationDepth()
			<< ", overflow=" << obj.overflowParent()
			<< ", odepth=" << obj.overflowDepth()
			<< ", score=" << obj.m_score
			<< ", active=" << obj.m_active
			<< " ]";

		return os;
	}
}

/* $Id */
