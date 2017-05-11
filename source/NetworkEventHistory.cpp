/*!
	\file NetworkEventHistory.cpp
	\brief Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/


#include <vector>

#include "Serializable.hpp"
#include "NetworkEvents.hpp"
#include "NetworkEventHistory.hpp"


namespace MLM
{
	NetworkEventHistory::NetworkEventHistory( void )
	{
	}


	NetworkEventHistory::~NetworkEventHistory( void )
	{
		destroy();
	}


	void NetworkEventHistory::addEvent( NetworkEvent * evnt )
	{
		m_events.push_back( evnt->copy() );
		setModified();
	}


	void NetworkEventHistory::reset( void )
	{
		destroy();
		resetModified();
	}


	int NetworkEventHistory::count( void ) const
	{
		return m_events.size();
	}


	std::vector<NetworkEvent*> NetworkEventHistory::events( void ) const
	{
		return m_events;
	}

	
	void NetworkEventHistory::destroy( void )
	{
		for( std::size_t i = 0; i < m_events.size(); i++ )
			delete m_events[i];

		m_events.clear();
	}

}

/* $Id: NetworkEventHistory.cpp 443 2017-05-05 01:35:27Z tiago.ventura $ */
