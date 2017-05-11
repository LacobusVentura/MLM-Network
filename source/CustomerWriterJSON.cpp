/*!
	\file CustomerWriterJSON.cpp
	\brief Customer Writer Object Interface (JSON Output)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include "Exception.hpp"
#include "Serializable.hpp"
#include "Network.hpp"
#include "CustomerWriterJSON.hpp"


namespace MLM
{

	CustomerWriterJSON::CustomerWriterJSON( std::ostream& os ) :
		m_ostream( os )
	{
	}


	CustomerWriterJSON::~CustomerWriterJSON( void )
	{
	}


	void CustomerWriterJSON::writeObject( const Serializable * s )
	{
		const Customer & cstmr = dynamic_cast<const Customer&>( *s );

		m_ostream << "{ \"id_network\" : " << cstmr.network() << ",\"id\" : " << cstmr.id() << ", \"score\" : " << cstmr.score() << " }" << std::endl;
	}
}

/* $Id: CustomerWriterJSON.cpp 439 2017-05-04 19:50:36Z tiago.ventura $ */
