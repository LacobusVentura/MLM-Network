/*!
	\file NetworkCollectionWriterText.cpp
	\brief Network Writer Object Implementation (Text Format)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

#include "Exception.hpp"
#include "Writer.hpp"
#include "Serializable.hpp"
#include "NetworkCollection.hpp"
#include "Network.hpp"
#include "NetworkCollectionWriterText.hpp"

namespace MLM
{

	NetworkCollectionWriterText::NetworkCollectionWriterText( std::ostream& os ) :
		m_ostream( os )
	{
	}


	NetworkCollectionWriterText::~NetworkCollectionWriterText( void )
	{
	}


	void NetworkCollectionWriterText::writeObject( const Serializable * s )
	{
		const NetworkCollection & collection = dynamic_cast<const NetworkCollection&>( *s );
		
		m_ostream << std::endl << "NETWORK LIST" << std::endl << std::endl;

		for( int i = 0; i < collection.count(); i++ )
		{
			const Network & net = collection.network(i);

			m_ostream << "		ID: " << net.id() << " - name: " << net.name() << " - description: " << net.description() << " - coefficient: " << net.overflowCoefficient() << std::endl;
		}
	}
}

/* $Id: NetworkCollectionWriterText.cpp 441 2017-05-05 01:34:20Z tiago.ventura $ */
