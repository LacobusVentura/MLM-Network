/*!
	\file CustomerWriterDataBase.hpp
	\brief Network Writer Object Interface (Database)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __CUSTOMERWRITERDATABASE_HPP__
#define __CUSTOMERWRITERDATABASE_HPP__

#include "Writer.hpp"
#include "Serializable.hpp"
#include "DataBaseConnection.hpp"

namespace MLM
{
	class CustomerWriterDataBase : public Writer
	{
		public:

			CustomerWriterDataBase( DataBaseConnection& conn );
			virtual ~CustomerWriterDataBase( void );

			void writeObject( const Serializable * s );

		private:
		
			DataBaseConnection & m_conn;
		
	};
}

#endif

/* $Id: CustomerWriterDataBase.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
