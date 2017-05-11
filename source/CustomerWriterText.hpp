/*!
	\file CustomerWriterText.hpp
	\brief Network Writer Object Interface (Text Output)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __CUSTOMERWRITERTEXT_HPP__
#define __CUSTOMERWRITERTEXT_HPP__

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

#include "Writer.hpp"
#include "Serializable.hpp"
#include "DataBaseConnection.hpp"

namespace MLM
{
	class CustomerWriterText : public Writer
	{
		public:

			CustomerWriterText( std::ostream& os );
			virtual ~CustomerWriterText( void );

			void writeObject( const Serializable * s );

		private:

			std::ostream& m_ostream;

	};
}

#endif

/* $Id: CustomerWriterText.hpp 439 2017-05-04 19:50:36Z tiago.ventura $ */
