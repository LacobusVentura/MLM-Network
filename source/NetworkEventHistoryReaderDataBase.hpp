/*!
	\file NetworkEventHistoryReaderDataBase.hpp
	\brief Network Event History Reader Object Interface (Data Base Serialization)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __NETWORKEVENTHISTORYREADERDATABASE_HPP__
#define __NETWORKEVENTHISTORYREADERDATABASE_HPP__


#include "Reader.hpp"
#include "Serializable.hpp"
#include "DataBaseConnection.hpp"


namespace MLM
{
	class NetworkEventHistoryReaderDataBase : public Reader
	{

		public:

			NetworkEventHistoryReaderDataBase( DataBaseConnection & m_conn );
			virtual ~NetworkEventHistoryReaderDataBase( void );

			void readObject( const Serializable * s );


		private:

			DataBaseConnection & m_conn;

	};
}

#endif

/* $Id: NetworkEventHistoryReaderDataBase.hpp 443 2017-05-05 01:35:27Z tiago.ventura $ */
