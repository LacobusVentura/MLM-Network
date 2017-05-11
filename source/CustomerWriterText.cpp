/*!
	\file CustomerWriterText.cpp
	\brief Customer Writer Object Interface (Text Output)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include "Exception.hpp"
#include "Serializable.hpp"
#include "Network.hpp"
#include "CustomerWriterText.hpp"


namespace MLM
{

	CustomerWriterText::CustomerWriterText( std::ostream& os ) :
		m_ostream( os )
	{
	}


	CustomerWriterText::~CustomerWriterText( void )
	{
	}


	void CustomerWriterText::writeObject( const Serializable * s )
	{
		const Customer & cstmr = dynamic_cast<const Customer&>( *s );

		m_ostream << "Network ID: " << cstmr.network() << std::endl;
		m_ostream << "Customer ID: " << cstmr.id() << std::endl;
		m_ostream << "Score: " << cstmr.score() << std::endl;
	}
}

/* $Id: CustomerWriterText.cpp 439 2017-05-04 19:50:36Z tiago.ventura $ */
