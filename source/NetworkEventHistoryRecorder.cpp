/*!
	\file NetworkEventHistoryRecorder.cpp
	\brief Network Event REcorder Object Implementation
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/


#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
#include <ctime>

#include "DebugLogger.hpp"
#include "Exception.hpp"
#include "NetworkEvents.hpp"
#include "NetworkEventHistoryRecorder.hpp"

namespace MLM
{

	NetworkEventHistoryRecorder::NetworkEventHistoryRecorder( NetworkEventHistory & hist ) :
		m_network_event_history(hist)
	{
		
	}


	NetworkEventHistoryRecorder::~NetworkEventHistoryRecorder( void )
	{
	}


	void NetworkEventHistoryRecorder::onSetRootCustomer( NetworkSetRootCustomerEvent & e )
	{
		m_network_event_history.addEvent( &e );
	}


	void NetworkEventHistoryRecorder::onAddCustomer( NetworkAddCustomerEvent & e )
	{
		m_network_event_history.addEvent( &e );
	}


	void NetworkEventHistoryRecorder::onRearrangeCustomer( NetworkRearrangeCustomerEvent & e )
	{
		m_network_event_history.addEvent( &e );
	}


	void NetworkEventHistoryRecorder::onRemoveCustomer( NetworkRemoveCustomerEvent & e )
	{
		m_network_event_history.addEvent( &e );
	}


	void NetworkEventHistoryRecorder::onPropagate( NetworkPropagateEvent & e )
	{
		m_network_event_history.addEvent( &e );
	}


	void NetworkEventHistoryRecorder::onChangeCustomerScore( NetworkChangeCustomerScoreEvent & e )
	{
		m_network_event_history.addEvent( &e );
	}


	void NetworkEventHistoryRecorder::onIncreaseCustomerScore( NetworkIncreaseCustomerScoreEvent & e )
	{
		m_network_event_history.addEvent( &e );
	}


	void NetworkEventHistoryRecorder::onDecreaseCustomerScore( NetworkDecreaseCustomerScoreEvent & e )
	{
		m_network_event_history.addEvent( &e );
	}


	void NetworkEventHistoryRecorder::onActivateCustomer( NetworkActivateCustomerEvent & e )
	{
		m_network_event_history.addEvent( &e );
	}


	void NetworkEventHistoryRecorder::onDeactivateCustomer( NetworkDeactivateCustomerEvent & e )
	{
		m_network_event_history.addEvent( &e );
	}

}

/* $Id: NetworkEventHistoryRecorder.cpp 443 2017-05-05 01:35:27Z tiago.ventura $ */
