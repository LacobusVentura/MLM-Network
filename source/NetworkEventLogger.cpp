/*!
	\file NetworkEventLogger.cpp
	\brief Network Event Logger Object Implementation
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
#include "NetworkEventLogger.hpp"

namespace MLM
{

	NetworkEventLogger::NetworkEventLogger( void ) :
		m_console( DebugLogger::getConsoleInstance() )
	{
	}


	NetworkEventLogger::~NetworkEventLogger( void )
	{
	}


	void NetworkEventLogger::onSetRootCustomer( NetworkSetRootCustomerEvent & e )
	{
		std::ostringstream oss;
		oss << "NetworkSetRootCustomerEvent: " << e.customer();
		m_console.notice( oss.str() );
	}


	void NetworkEventLogger::onAddCustomer( NetworkAddCustomerEvent & e )
	{
		std::ostringstream oss;
		oss << "NetworkAddCustomerEvent: " << e.customer();
		m_console.notice( oss.str() );
	}


	void NetworkEventLogger::onRearrangeCustomer( NetworkRearrangeCustomerEvent & e )
	{
		std::ostringstream oss;
		oss << "NetworkRearrangeCustomerEvent: " << e.customer();
		m_console.notice( oss.str() );
	}


	void NetworkEventLogger::onRemoveCustomer( NetworkRemoveCustomerEvent & e )
	{
		std::ostringstream oss;
		oss << "NetworkRemoveCustomerEvent: " << e.customer();
		m_console.notice( oss.str() );
	}


	void NetworkEventLogger::onPropagate( NetworkPropagateEvent & e )
	{
		std::ostringstream oss;
		std::vector<Customer> vec = e.affected();

		oss << "NetworkPropagateEvent: " << e.customer() << " score=" << e.score() << " affected=( ";

		for( std::size_t i = 0; i < vec.size(); i++ )
			oss << (( i > 0 ) ? ", " : "") << (vec[i]).id();

		oss << " )";

		m_console.notice( oss.str() );
	}


	void NetworkEventLogger::onChangeCustomerScore( NetworkChangeCustomerScoreEvent & e )
	{
		std::ostringstream oss;
		oss << "NetworkChangeCustomerScoreEvent: " << e.customer();
		m_console.notice( oss.str() );
	}


	void NetworkEventLogger::onIncreaseCustomerScore( NetworkIncreaseCustomerScoreEvent & e )
	{
		std::ostringstream oss;
		oss << "NetworkIncreaseCustomerScoreEvent: " << e.customer();
		m_console.notice( oss.str() );
	}


	void NetworkEventLogger::onDecreaseCustomerScore( NetworkDecreaseCustomerScoreEvent & e )
	{
		std::ostringstream oss;
		oss << "NetworkDecreaseCustomerScoreEvent: " << e.customer();
		m_console.notice( oss.str() );
	}


	void NetworkEventLogger::onActivateCustomer( NetworkActivateCustomerEvent & e )
	{
		std::ostringstream oss;
		oss << "NetworkActivateCustomerEvent: " << e.customer();
		m_console.notice( oss.str() );
	}


	void NetworkEventLogger::onDeactivateCustomer( NetworkDeactivateCustomerEvent & e )
	{
		std::ostringstream oss;
		oss << "NetworkDeactivateCustomerEvent: " << e.customer();
		m_console.notice( oss.str() );
	}

}

/* $Id: NetworkEventLogger.cpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
