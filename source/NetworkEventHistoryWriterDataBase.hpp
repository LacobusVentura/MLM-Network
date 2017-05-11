/*!
	\file NetworkEventHistoryWriterDataBase.hpp
	\brief Network Event History Writer Object Interface (Data Base Serialization)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __NETWORKEVENTHISTORYWRITERDATABASE_HPP__
#define __NETWORKEVENTHISTORYWRITERDATABASE_HPP__


#include "Writer.hpp"
#include "Serializable.hpp"
#include "DataBaseConnection.hpp"


namespace MLM
{
	class NetworkEventHistoryWriterDataBase : public Writer
	{

		public:

			NetworkEventHistoryWriterDataBase( DataBaseConnection & m_conn );
			virtual ~NetworkEventHistoryWriterDataBase( void );

			void writeObject( const Serializable * s );


		private:

			DataBaseConnection & m_conn;

	};
}

#endif

/* $Id: NetworkEventHistoryWriterDataBase.hpp 443 2017-05-05 01:35:27Z tiago.ventura $ */
