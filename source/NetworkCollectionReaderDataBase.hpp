/*!
	\file NetworkCollectionReaderDataBase.hpp
	\brief Network Collection Reader Object Interface (DataBase Reader)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __NETWORKCOLLECTIONREADERDATABASE_HPP__
#define __NETWORKCOLLECTIONREADERDATABASE_HPP__

#include "Reader.hpp"
#include "Serializable.hpp"
#include "DataBaseConnection.hpp"

namespace MLM
{

	class NetworkCollectionReaderDataBase : public Reader
	{

		public:

			NetworkCollectionReaderDataBase( DataBaseConnection & m_conn );
			virtual ~NetworkCollectionReaderDataBase( void );

			void readObject( Serializable * s );

		private:

			DataBaseConnection & m_conn;
			
	};
	
}

#endif

/* $Id: NetworkCollectionReaderDataBase.hpp 433 2017-05-03 22:27:32Z tiago.ventura $ */
