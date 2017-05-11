/*!
	\file NetworkWriterText.hpp
	\brief Network Writer Object Interface (Text Format)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __NETWORKWRITERTEXT_HPP__
#define __NETWORKWRITERTEXT_HPP__

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

#include "Writer.hpp"
#include "Serializable.hpp"

namespace MLM
{
	class NetworkWriterText : public Writer
	{
		public:

			NetworkWriterText( std::ostream& os );
			virtual ~NetworkWriterText( void );

			void fullInfo( bool state ) { m_full_info = state; }

			void writeObject( const Serializable * s );


		private:

			bool m_full_info;
			std::ostream& m_ostream;
	};
}

#endif

/* $Id: NetworkWriterText.hpp 439 2017-05-04 19:50:36Z tiago.ventura $ */
