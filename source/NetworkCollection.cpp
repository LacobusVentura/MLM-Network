/*!
	\file NetworkCollection.cpp
	\brief Network Collection Object Implementation
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include <vector>

#include "Exception.hpp"
#include "DebugLogger.hpp"
#include "Serializable.hpp"
#include "Network.hpp"

#include "NetworkCollection.hpp"

namespace MLM
{
	NetworkCollection::NetworkCollection( void ) :
		m_collection()
	{
	}
	
	
	NetworkCollection::~NetworkCollection( void )
	{
	}
	
	
	int NetworkCollection::count( void ) const
	{
		return m_collection.size();
	}
	
	
	const Network & NetworkCollection::network( int idx ) const
	{
		return m_collection[ idx ];
	}


	void NetworkCollection::addNetwork( Network & net )
	{
		m_collection.push_back( net );
	}


	void NetworkCollection::clear( void )
	{
		m_collection.clear();
	}

}

/* $Id: NetworkCollection.cpp 438 2017-05-04 17:19:20Z tiago.ventura $ */
