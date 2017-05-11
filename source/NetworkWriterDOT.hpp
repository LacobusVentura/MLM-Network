/*!
	\file NetworkWriterDOT.hpp
	\brief Network Writer Object Interface (GraphViz/DOT Format)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __NETWORKWRITERDOT_HPP__
#define __NETWORKWRITERDOT_HPP__

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

#include "Writer.hpp"
#include "Serializable.hpp"

namespace MLM
{
	class NetworkWriterDOT : public Writer
	{
		public:

			NetworkWriterDOT( const std::string& filename );
			NetworkWriterDOT( std::ostream& os );
			virtual ~NetworkWriterDOT( void );

			void writeObject( const Serializable * s );


		private:

			std::ofstream m_ofstream;
			std::ostream& m_ostream;
	};
}

#endif

/* $Id: NetworkWriterDOT.hpp 383 2017-04-06 14:00:13Z tiago.ventura $ */
