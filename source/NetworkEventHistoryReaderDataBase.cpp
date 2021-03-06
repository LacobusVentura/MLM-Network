/*!
	\file NetworkEventHistoryReaderDataBase.cpp
	\brief Network Event History Reader Object Implementation (Data Base Serialization)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>

#include "Exception.hpp"
#include "Reader.hpp"
#include "Serializable.hpp"
#include "NetworkEvents.hpp"
#include "NetworkEventHistory.hpp"
#include "DataBaseConnection.hpp"

#include "NetworkEventHistoryReaderDataBase.hpp"

namespace MLM
{

	NetworkEventHistoryReaderDataBase::NetworkEventHistoryReaderDataBase( DataBaseConnection & conn  ) :
		m_conn( conn )
	{
	}


	NetworkEventHistoryReaderDataBase::~NetworkEventHistoryReaderDataBase( void )
	{
	}


	void NetworkEventHistoryReaderDataBase::readObject( const Serializable * s )
	{
		const NetworkEventHistory & hist = dynamic_cast< const NetworkEventHistory& >( *s );

		std::vector<NetworkEvent*> evntlst = hist.events();

		for( std::size_t i = 0; i < evntlst.size(); i++ )
		{
			NetworkEvent * base = evntlst[i];

			if( NetworkSetRootCustomerEvent * evnt = dynamic_cast<NetworkSetRootCustomerEvent*>(base) )
			{
				(void) evnt;
			}
			else if( NetworkRearrangeCustomerEvent * evnt = dynamic_cast<NetworkRearrangeCustomerEvent*>(base) )
			{
				(void) evnt;
			}
			else if( NetworkAddCustomerEvent * evnt = dynamic_cast<NetworkAddCustomerEvent*>(base) )
			{
				(void) evnt;
			}
			else if( NetworkRemoveCustomerEvent * evnt = dynamic_cast<NetworkRemoveCustomerEvent*>(base) )
			{
				(void) evnt;
			}
			else if( NetworkPropagateEvent * evnt = dynamic_cast<NetworkPropagateEvent*>(base) )
			{
				(void) evnt;
			}
			else if( NetworkIncreaseCustomerScoreEvent* evnt = dynamic_cast<NetworkIncreaseCustomerScoreEvent*>(base) )
			{
				(void) evnt;
			}
			else if( NetworkDecreaseCustomerScoreEvent * evnt = dynamic_cast<NetworkDecreaseCustomerScoreEvent*>(base) )
			{
				(void) evnt;
			}
			else if( NetworkActivateCustomerEvent * evnt = dynamic_cast<NetworkActivateCustomerEvent*>(base) )
			{
				(void) evnt;
			}
			else if( NetworkDeactivateCustomerEvent * evnt = dynamic_cast<NetworkDeactivateCustomerEvent*>(base) )
			{
				(void) evnt;
			}
			else
			{
				throwex( NullPointerException("Unknown Derived Network Event Object.") );
			}
		}
	}
}

/* $Id: NetworkEventHistoryReaderDataBase.cpp 443 2017-05-05 01:35:27Z tiago.ventura $ */
