/*!
	\file NetworkReaderDataBase.hpp
	\brief Network Reader Object Interface (Text Format)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __NETWORKREADERDATABASE_HPP__
#define __NETWORKREADERDATABASE_HPP__

#include "Reader.hpp"
#include "Serializable.hpp"
#include "Network.hpp"
#include "DataBaseConnection.hpp"

namespace MLM
{

	class NetworkReaderDataBase : public Reader
	{

		public:

			NetworkReaderDataBase( DataBaseConnection & m_conn );
			virtual ~NetworkReaderDataBase( void );

			void readObject( Serializable * s );


		private:

			DataBaseConnection & m_conn;
			
	};
	
}

#endif

/* $Id: NetworkReaderDataBase.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
