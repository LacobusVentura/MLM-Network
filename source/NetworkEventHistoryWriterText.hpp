/*!
	\file NetworkEventHistoryWriterText.hpp
	\brief Network Event History Writer Object Interface (Text Format)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __NETWORKEVENTHISTORYWRITERTEXT_HPP__
#define __NETWORKEVENTHISTORYWRITERTEXT_HPP__

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

#include "Exception.hpp"
#include "Writer.hpp"
#include "Serializable.hpp"

namespace MLM
{
	class NetworkEventHistoryWriterText : public Writer
	{
		public:

			NetworkEventHistoryWriterText( std::ostream& os = std::cout );
			virtual ~NetworkEventHistoryWriterText( void );

			void writeObject( const Serializable * s );

		private:

			std::ofstream m_ofstream;
			std::ostream& m_ostream;
	};
}

#endif

/* $Id: NetworkEventHistoryWriterText.hpp 447 2017-05-05 10:52:07Z tiago.ventura $ */
