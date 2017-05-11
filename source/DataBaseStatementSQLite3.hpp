/*!
	\file DataBaseStatementSQLite3.hpp
	\brief Data Base Statement Object Interface (SQLite3 Database)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __DATABASESTATEMENTSQLITE3_HPP__
#define __DATABASESTATEMENTSQLITE3_HPP__

#include <vector>
#include <string>
#include <map>

#include "sqlite3.h"

#include "DataBaseColumn.hpp"
#include "DataBaseStatement.hpp"
#include "DataBaseConnection.hpp"
#include "DataBaseConnectionSQLite3.hpp"

namespace MLM
{

	class DataBaseStatementSQLite3 : public DataBaseStatement
	{

		friend class DataBaseColumnSQLite3;

		public:

			DataBaseStatementSQLite3( DataBaseConnectionSQLite3& dbconn, std::string sql );
			virtual ~DataBaseStatementSQLite3( void );

			int execute( void );
			bool fetch( void );

			int columnCount( void );
			int rowCount( void );

			DataBaseColumn * getColumn( int idx );
			DataBaseColumn * getColumn( std::string name );

			void reset( void );

			void setAttribute( std::string name, std::string value );
			void setAttribute( std::string name, int value );
			void setAttribute( std::string name, long long value );
			void setAttribute( std::string name, double value );
			void setAttributeNull( std::string name );

			void setAttribute( int idx, std::string value );
			void setAttribute( int idx, int value );
			void setAttribute( int idx, long long value );
			void setAttribute( int idx, double value );
			void setAttributeNull( int idx );

			void resetAttributes( void );

			std::string getErrorMsg( void ) const;
			int getColumnIndex( std::string name );


		protected:

			sqlite3_stmt * m_stmnt_sqlite;
			sqlite3 * m_conn_sqlite;

		private:

			int m_cols_count;
			bool m_ok;
			bool m_done;

			std::map< std::string, int > m_columns_map;

	};

}

#endif

/* $Id: DataBaseStatementSQLite3.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
