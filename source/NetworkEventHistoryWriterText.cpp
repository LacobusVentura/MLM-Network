/*!
	\file NetworkEventHistoryWriterText.cpp
	\brief Network Event History Writer Object Implementation (Text Format)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>

#include "Exception.hpp"
#include "Writer.hpp"
#include "Serializable.hpp"
#include "NetworkEvents.hpp"
#include "NetworkEventHistory.hpp"
#include "NetworkEventHistoryWriterText.hpp"

namespace MLM
{

	NetworkEventHistoryWriterText::NetworkEventHistoryWriterText( std::ostream& os ) :
		m_ofstream(),
		m_ostream( os )
	{
	}


	NetworkEventHistoryWriterText::~NetworkEventHistoryWriterText( void )
	{
	}


	void NetworkEventHistoryWriterText::writeObject( const Serializable * s )
	{
		const NetworkEventHistory & hist = dynamic_cast< const NetworkEventHistory& >( *s );

		static int seq = 0;

		std::vector<NetworkEvent*> evntlst = hist.events();

		for( std::size_t i = 0; i < evntlst.size(); i++ )
		{
			NetworkEvent * base = evntlst[i];

			if( NetworkSetRootCustomerEvent * evnt = dynamic_cast<NetworkSetRootCustomerEvent*>(base) )
			{
				m_ostream << "[NetworkSetRootCustomerEvent] Network=" << evnt->network().id() << " Customer=" << evnt->customer().id() << std::endl;
			}
			else if( NetworkRearrangeCustomerEvent * evnt = dynamic_cast<NetworkRearrangeCustomerEvent*>(base) )
			{
				m_ostream << "[NetworkRearrangeCustomerEvent] Network=" << evnt->network().id() << " Customer=" << evnt->customer().id() << std::endl;
			}
			else if( NetworkAddCustomerEvent * evnt = dynamic_cast<NetworkAddCustomerEvent*>(base) )
			{
				m_ostream << "[NetworkAddCustomerEvent] Network=" << evnt->network().id() << " Customer=" << evnt->customer().id() << std::endl;
			}
			else if( NetworkRemoveCustomerEvent * evnt = dynamic_cast<NetworkRemoveCustomerEvent*>(base) )
			{
				m_ostream << "[NetworkRemoveCustomerEvent] Network=" << evnt->network().id() << " Customer=" << evnt->customer().id() << std::endl;
			}
			else if( NetworkPropagateEvent * evnt = dynamic_cast<NetworkPropagateEvent*>(base) )
			{
				m_ostream << "[NetworkPropagateEvent] Network=" << evnt->network().id() << " Customer=" << evnt->customer().id() << std::endl;
			}
			else if( NetworkIncreaseCustomerScoreEvent* evnt = dynamic_cast<NetworkIncreaseCustomerScoreEvent*>(base) )
			{
				m_ostream << "[NetworkIncreaseCustomerScoreEvent] Network=" << evnt->network().id() << " Customer=" << evnt->customer().id() << std::endl;
			}
			else if( NetworkDecreaseCustomerScoreEvent * evnt = dynamic_cast<NetworkDecreaseCustomerScoreEvent*>(base) )
			{
				m_ostream << "[NetworkDecreaseCustomerScoreEvent] Network=" << evnt->network().id() << " Customer=" << evnt->customer().id() << std::endl;
			}
			else if( NetworkActivateCustomerEvent * evnt = dynamic_cast<NetworkActivateCustomerEvent*>(base) )
			{
				m_ostream << "[NetworkActivateCustomerEvent] Network=" << evnt->network().id() << " Customer=" << evnt->customer().id() << std::endl;
			}
			else if( NetworkDeactivateCustomerEvent * evnt = dynamic_cast<NetworkDeactivateCustomerEvent*>(base) )
			{
				m_ostream << "[NetworkDeactivateCustomerEvent] Network=" << evnt->network().id() << " Customer=" << evnt->customer().id() << std::endl;
			}
			else
			{
				throwex( NullPointerException("Unknown Derived Network Event Object.") );
			}

			seq++;

		}
	}
}

/* $Id: NetworkEventHistoryWriterText.cpp 447 2017-05-05 10:52:07Z tiago.ventura $ */
