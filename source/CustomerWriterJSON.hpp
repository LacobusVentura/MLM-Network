/*!
	\file CustomerWriterJSON.hpp
	\brief Network Writer Object Interface (JSON Output)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __CUSTOMERWRITERJSON_HPP__
#define __CUSTOMERWRITERJSON_HPP__

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

#include "Writer.hpp"
#include "Serializable.hpp"
#include "DataBaseConnection.hpp"

namespace MLM
{
	class CustomerWriterJSON : public Writer
	{
		public:

			CustomerWriterJSON( std::ostream& os );
			virtual ~CustomerWriterJSON( void );

			void writeObject( const Serializable * s );

		private:

			std::ostream& m_ostream;

	};
}

#endif

/* $Id: CustomerWriterJSON.hpp 439 2017-05-04 19:50:36Z tiago.ventura $ */
