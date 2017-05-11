/*!
	\file NetworkEventHistoryWriterJSON.hpp
	\brief Network Event History Writer Object Interface (JSON Format)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __NETWORKEVENTHISTORYWRITERJSON_HPP__
#define __NETWORKEVENTHISTORYWRITERJSON_HPP__

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

#include "Exception.hpp"
#include "Writer.hpp"
#include "Serializable.hpp"

namespace MLM
{
	class NetworkEventHistoryWriterJSON : public Writer
	{
		public:

			NetworkEventHistoryWriterJSON( std::ostream& os );
			virtual ~NetworkEventHistoryWriterJSON( void );

			void writeObject( const Serializable * s );

		private:

			std::ostream& m_ostream;
	};
}

#endif

/* $Id: NetworkEventHistoryWriterJSON.hpp 447 2017-05-05 10:52:07Z tiago.ventura $ */
