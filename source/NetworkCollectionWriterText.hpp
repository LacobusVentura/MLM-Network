/*!
	\file NetworkCollectionWriterText.hpp
	\brief Network Collection Writer Object Interface (Text Format)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __NETWORKCOLLECTIONWRITERTEXT_HPP__
#define __NETWORKCOLLECTIONWRITERTEXT_HPP__

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

#include "Writer.hpp"
#include "Serializable.hpp"

namespace MLM
{
	class NetworkCollectionWriterText : public Writer
	{
		public:

			NetworkCollectionWriterText( std::ostream& os );
			virtual ~NetworkCollectionWriterText( void );

			void writeObject( const Serializable * s );

		private:

			std::ostream& m_ostream;
	};
}

#endif

/* $Id: NetworkCollectionWriterText.hpp 439 2017-05-04 19:50:36Z tiago.ventura $ */
