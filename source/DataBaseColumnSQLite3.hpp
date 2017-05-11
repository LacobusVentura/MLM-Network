/*!
	\file DataBaseColumnSQLite3.hpp
	\brief Data Base Column Object Interface (SQLite3 Implementation)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __DATABASECOLUMNSQLITE3_HPP__
#define __DATABASECOLUMNSQLITE3_HPP__

#include <string>

#include "DataBaseColumn.hpp"
#include "DataBaseStatement.hpp"
#include "DataBaseStatementSQLite3.hpp"

namespace MLM
{

	class DataBaseColumnSQLite3 : public DataBaseColumn
	{

		public:

			DataBaseColumnSQLite3( DataBaseStatementSQLite3& stmnt, int index );
			virtual ~DataBaseColumnSQLite3( void );

			std::string name( void );
			int size( void );
			
			int getInt( void );
			unsigned int getUInt( void );
			long long getInt64( void );
			double getDouble( void );
			std::string getText( void );
			const void * getBlob( void );

			bool isInteger( void );
			bool isFloat( void );
			bool isText( void );
			bool isBlob( void );
			bool isNull( void );


		private:
		
  			sqlite3_stmt * m_stmnt_sqlite;
	};

}

#endif

/* $Id: DataBaseColumnSQLite3.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
