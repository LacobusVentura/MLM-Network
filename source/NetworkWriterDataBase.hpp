/*!
	\file NetworkWriterDataBase.hpp
	\brief Network Writer Object Interface (Database)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __NETWORKWRITERDATABASE_HPP__
#define __NETWORKWRITERDATABASE_HPP__

#include "Writer.hpp"
#include "Serializable.hpp"
#include "DataBaseConnection.hpp"

namespace MLM
{
	class NetworkWriterDataBase : public Writer
	{
		public:

			NetworkWriterDataBase( DataBaseConnection& conn );
			virtual ~NetworkWriterDataBase( void );

			void writeObject( const Serializable * s );

		private:

			DataBaseConnection & m_conn;

	};
}

#endif

/* $Id: NetworkWriterDataBase.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
