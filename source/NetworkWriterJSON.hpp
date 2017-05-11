/*!
	\file NetworkWriterJSON.hpp
	\brief Network Writer Object Interface (JSON Format)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __NETWORKWRITERJSON_HPP__
#define __NETWORKWRITERJSON_HPP__

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

#include "Writer.hpp"
#include "Serializable.hpp"

namespace MLM
{
	class NetworkWriterJSON : public Writer
	{
		public:

			NetworkWriterJSON( std::ostream& os );
			virtual ~NetworkWriterJSON( void );

			void fullInfo( bool state ) { m_full_info = state; }

			void writeObject( const Serializable * s );

		private:

			bool m_full_info;
			std::ostream& m_ostream;
	};
}

#endif

/* $Id: NetworkWriterJSON.hpp 439 2017-05-04 19:50:36Z tiago.ventura $ */
