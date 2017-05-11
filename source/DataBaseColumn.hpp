/*!
	\file DataBaseColumn.hpp
	\brief Data Base Column Object Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __DATABASECOLUMN_HPP__
#define __DATABASECOLUMN_HPP__

#include <string>

namespace MLM
{

	class DataBaseStatement;

	class DataBaseColumn
	{

		public:

			DataBaseColumn( DataBaseStatement& stmnt, int index ) :
				m_statement(stmnt),
				m_index(index)
			{
			}

			virtual ~DataBaseColumn( void )
			{
			}


			virtual std::string name( void ) = 0;
			virtual int size( void ) = 0;
			
			virtual int getInt( void ) = 0;
			virtual unsigned int getUInt( void ) = 0;
			virtual long long getInt64( void ) = 0;
			virtual double getDouble( void ) = 0;
			virtual std::string getText( void ) = 0;
			virtual const void * getBlob( void ) = 0;

			virtual bool isInteger( void ) = 0;
			virtual bool isFloat( void ) = 0;
			virtual bool isText( void ) = 0;
			virtual bool isBlob( void ) = 0;
			virtual bool isNull( void ) = 0;


		protected:

			DataBaseStatement & m_statement;
			int m_index;

	};

}

#endif

/* $Id: DataBaseColumn.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
