/*!
	\file CustomerReaderDataBase.hpp
	\brief Network Reader Object Interface (DataBase)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __CUSTOMERREADERDATABASE_HPP__
#define __CUSTOMERREADERDATABASE_HPP__


#include "Reader.hpp"
#include "Serializable.hpp"
#include "Network.hpp"
#include "DataBaseConnection.hpp"

namespace MLM
{

	class CustomerReaderDataBase : public Reader
	{

		public:

			CustomerReaderDataBase( DataBaseConnection & m_conn );
			virtual ~CustomerReaderDataBase( void );

			void readObject( Serializable * s );


		private:

			DataBaseConnection & m_conn;
			
	};
	
}

#endif

/* $Id: CustomerReaderDataBase.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
