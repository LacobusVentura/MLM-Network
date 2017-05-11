/*!
	\file Network.cpp
	\brief Network Object Implementation
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include <string>
#include <vector>
#include <iomanip>

#include "Exception.hpp"
#include "DebugLogger.hpp"
#include "Serializable.hpp"
#include "PropagationRule.hpp"
#include "PropagationStep.hpp"
#include "Tree.hpp"
#include "Network.hpp"
#include "EventDispatcher.hpp"
#include "NetworkEvents.hpp"

namespace MLM
{

	Network::Network( void ) :
		m_id(-1),
		m_name(""),
		m_description(""),
		m_creation(-1),
		m_coefficient(3),
		m_customer_count(0),
		m_inactive_customer_count(0)
	{
	}


	Network::Network( int id ) :
		m_id(id),
		m_name(""),
		m_description(""),
 		m_creation(-1),
		m_coefficient(3),
		m_customer_count(0),
		m_inactive_customer_count(0)
	{
	}


	Network::Network( const Network &obj ) :
		m_id(obj.m_id),
		m_name(obj.m_name),
		m_description(obj.m_description),
		m_creation(obj.m_creation),
		m_coefficient(obj.m_coefficient),
		m_customer_count(obj.m_customer_count),
		m_inactive_customer_count(obj.m_inactive_customer_count)
	{
	}


	Network::~Network( void )
	{
	}


	Network& Network::operator=( const Network& obj )
	{
		m_id = obj.m_id;
		m_name = obj.m_name;
		m_description = obj.m_description;
		m_creation = obj.m_creation;
		m_coefficient = obj.m_coefficient;
		m_customer_count = obj.m_customer_count;
		m_inactive_customer_count = obj.m_inactive_customer_count;

		return *this;
	}


	void Network::id( int id )
	{
		m_id = id;
		setModified();
	}


	int Network::id( void ) const
	{
		return m_id;
	}


	std::string Network::name( void ) const
	{
		return m_name;
	}


	void Network::name( std::string name )
	{
		m_name = name;
		setModified();
	}


	std::string Network::description( void ) const
	{
		return m_description;
	}


	void Network::description( std::string desc )
	{
		m_description = desc;
		setModified();
	}


	void Network::creation( std::time_t ts )
	{
		m_creation = ts;
		setModified();
	}


	std::time_t Network::creation( void ) const
	{
		return m_creation;
	}


	int Network::overflowCoefficient( void ) const
	{
		return m_coefficient;
	}


	void Network::overflowCoefficient( int k )
	{
		m_coefficient = k;
		setModified();
	}


	void Network::rootCustomer( const Customer& c )
	{
		Customer & nci = m_invitations.root(c);
		Customer & ncb = m_balanced.root(c);

		nci.network( m_id );
		nci.overflowParent( -1 );
		nci.invitationParent( -1 );

		ncb.network( m_id );
		ncb.overflowParent( -1 );
		ncb.invitationParent( -1 );

		m_customer_count = 1;
		m_inactive_customer_count = 1;

		setModified();

		NetworkSetRootCustomerEvent event( *this, ncb );
		dispatchEvent( event );
	}


	Customer * Network::rootCustomer( void ) const
	{
		return m_invitations.root();
	}


	int Network::customerCount( void ) const
	{
		return m_customer_count;
	}


	int Network::activeCustomerCount( void ) const
	{
		return m_inactive_customer_count;
	}


	int Network::inactiveCustomerCount( void ) const
	{
		return m_customer_count - m_inactive_customer_count;
	}


	const Tree<Customer> & Network::invitationsTree( void ) const
	{
		return m_invitations;
	}


	const Tree<Customer> & Network::balancedTree( void ) const
	{
		return m_balanced;
	}


	Customer & Network::addCustomer( const Customer& parent, const Customer& c )
	{
		Customer * bal = m_balanced.search( parent );
		Customer * inv = m_invitations.search( parent );

		if(!bal || !inv)
			throwex( RunTimeException( "Parent Customer does not exists in this Network." ) );

		if(m_balanced.search( c ))
			throwex( RunTimeException( "Customer already exists in this Network." ) );

		if( bal->childCount() < m_coefficient )
		{
			Customer & nci = inv->addChild( c );
			Customer & ncb = bal->addChild( c );

			nci.network( m_id );
			nci.overflowParent( bal->id() );
			nci.invitationParent( inv->id() );
			nci.overflowDepth( bal->depth() );
			nci.invitationDepth( inv->depth() );

			ncb.network( m_id );
			ncb.overflowParent( bal->id() );
			ncb.invitationParent( inv->id() );
			ncb.overflowDepth( bal->depth() );
			ncb.invitationDepth( inv->depth() );

			m_customer_count++;
 			m_inactive_customer_count++;

 			setModified();

			NetworkAddCustomerEvent event( *this, ncb );
			dispatchEvent( event );

 			return *bal;
		}

		int maxdepth = bal->maxDepth();
		std::vector<Customer*> vec;
		std::vector<Customer*> vecaux;

  		for( int depth = 0; depth < maxdepth; depth++ )
		{
			vecaux = bal->depthNodeList( depth );

			for( std::size_t i = 0; i < vecaux.size(); i++ )
				if( vecaux[i]->childCount() < m_coefficient )
					vec.push_back(vecaux[i]);

			if( vec.size() > 0 )
				break;
		}

		int min = m_coefficient;
		Customer * elected = NULL;

		for( std::size_t i = 0; i < vec.size(); i++ )
		{
			int n = vec[i]->childCount();

			if( n < min )
			{
				min = n;
				elected = vec[i];
			}
		}

		if(!elected)
			throwex( NullPointerException( "Customer overflow failed." ) );

		Customer & nci = inv->addChild( c );
		Customer & ncb = elected->addChild( c );

		nci.network( m_id );
		nci.overflowParent( elected->id() );
		nci.invitationParent( inv->id() );
		nci.overflowDepth( elected->depth() );
		nci.invitationDepth( inv->depth() );

		ncb.network( m_id );
		ncb.overflowParent( elected->id() );
		ncb.invitationParent( inv->id() );
		ncb.overflowDepth( elected->depth() );
		ncb.invitationDepth( inv->depth() );

		m_customer_count++;
		m_inactive_customer_count++;

		setModified();

		NetworkAddCustomerEvent event( *this, *elected );
		dispatchEvent( event );

		return *elected;
	}


	std::vector<Customer> Network::propagateScore( const Customer & src, const PropagationRule & rule, double score )
	{
		if( score < 0.0 )
			throwex( IllegalArgumentsException("Can't propagate negative values.") );

		std::vector<Customer> affected;

		Customer * bal = m_balanced.search( src );
		Customer * inv = m_invitations.search( src );

		if(!bal || !inv)
			throwex( RunTimeException( "Source Customer does not exists in this Network." ) );

		std::vector<PropagationStep> steplst = rule.stepList();
		int invitations = inv->childCount();
		Customer * cstmr = bal;

		for( std::size_t nstep = 0; nstep < steplst.size(); nstep++ )
		{
			PropagationStep step = steplst[nstep];

			cstmr = cstmr->parent();

 			if( !cstmr )
				break;

			double value = (score * step.percentage() ) / 100.0;

			if( invitations >= step.minInvitations() )
   				if( cstmr->active() )
					cstmr->scoreAdd( value );

			affected.push_back(*cstmr);

			NetworkIncreaseCustomerScoreEvent event( *this, *cstmr, value );
			dispatchEvent( event );
		}

		NetworkPropagateEvent event( *this, *bal, rule, affected, score );
		dispatchEvent( event );

		return affected;
	}


	void Network::removeCustomer( const Customer& cstmr )
	{
		Customer * bal = m_balanced.search( cstmr );
		Customer * inv = m_invitations.search( cstmr );

		if(!bal || !inv)
			throwex( RunTimeException( "Customer does not exists in this Network." ) );

		if( bal->isLeaf() )
			throwex( RunTimeException( "Customer is not a leaf in the balanced tree." ) );

		if( inv->isLeaf() )
			throwex( RunTimeException( "Customer is not a leaf in the invitations tree." ) );

		TreeNode<Customer>::removeLeafNode( inv );
		TreeNode<Customer>::removeLeafNode( bal );

		m_customer_count--;

		if(!bal->active())
			m_inactive_customer_count--;

		setModified();

		NetworkRemoveCustomerEvent evnt( *this, cstmr );
		dispatchEvent( evnt );
	}


	void Network::customerAddScore( const Customer & cstmr, double score )
	{
		if( score < 0.0 )
			throwex( IllegalArgumentsException("Can't Add negative score values.") );

		Customer * bal = m_balanced.search( cstmr );

		if(!bal)
			throwex( RunTimeException( "Customer does not exists in this Network." ) );

		bal->scoreAdd( score );

		NetworkIncreaseCustomerScoreEvent evnt( *this, *bal, score );
		dispatchEvent( evnt );
	}


	void Network::customerSubtractScore( const Customer & cstmr, double score )
	{
		if( score < 0.0 )
			throwex( IllegalArgumentsException("Can't Subract negative score values.") );

		Customer * bal = m_balanced.search( cstmr );

		if(!bal)
			throwex( RunTimeException( "Customer does not exists in this Network." ) );

		bal->scoreSubtract( score );

		NetworkDecreaseCustomerScoreEvent evnt( *this, *bal, score );
		dispatchEvent( evnt );
	}


	void Network::customerSetScore( const Customer & cstmr, double score )
	{
		if( score < 0.0 )
			throwex( IllegalArgumentsException("Can't Set negative score values.") );

		Customer * bal = m_balanced.search( cstmr );

		if(!bal)
			throwex( RunTimeException( "Customer does not exists in this Network." ) );

		bal->score( score );

		NetworkChangeCustomerScoreEvent evnt( *this, *bal, score );
		dispatchEvent( evnt );
	}


	void Network::customerDeactivate( const Customer & cstmr )
	{
		Customer * bal = m_balanced.search( cstmr );

		if(!bal)
			throwex( RunTimeException( "Customer does not exists in this Network." ) );

		if(!bal->active())
			throwex( RunTimeException( "Customer already inactive in this network." ) );

		bal->deactivate();

		m_inactive_customer_count++;

		setModified();

		NetworkDeactivateCustomerEvent evnt( *this, *bal );
		dispatchEvent( evnt );
	}


	void Network::customerActivate( const Customer & cstmr )
	{
		Customer * bal = m_balanced.search( cstmr );

		if(!bal)
			throwex( RunTimeException( "Customer does not exists in this Network." ) );

		if(bal->active())
			throwex( RunTimeException( "Customer already active in this network." ) );

		bal->activate();

		m_inactive_customer_count--;

		setModified();

		NetworkActivateCustomerEvent evnt( *this, *bal );
		dispatchEvent( evnt );
	}


	Customer * Network::searchCustomer( const Customer & cstmr )
	{
		return m_balanced.search( cstmr );
	}


	std::ostream& operator<<( std::ostream& os, const Network& obj )
	{
		int id = obj.m_id;
		std::string name = obj.m_name;
		int count = obj.m_customer_count;

		os << "net[ id=" << id << ", name=" << name << ", count=" << count << " ]";

		return os;
	}
}

/* $Id: Network.cpp 428 2017-05-03 01:34:14Z tiago.ventura $ */
