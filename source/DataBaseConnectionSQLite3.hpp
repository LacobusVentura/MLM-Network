/*!
	\file DataBaseConnectionSQLite3.hpp
	\brief Data Base Connection Object Interface (SQLite3 Database)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __DATABASECONNECTIONSQLITE3_HPP__
#define __DATABASECONNECTIONSQLITE3_HPP__

#include <vector>
#include <string>

#include "sqlite3.h"
#include "DataBaseConnection.hpp"

namespace MLM
{
	class DataBaseConnectionSQLite3 : public DataBaseConnection
	{

		friend class DataBaseStatementSQLite3;

		public:

			virtual ~DataBaseConnectionSQLite3( void );

			static DataBaseConnectionSQLite3& instance( void );

			std::string version( void ) const;

			void beginTransaction( void );
			void commitTransaction( void );
			void rollbackTransaction( void );
			bool inTransaction( void );

			void connect( void );
			void disconnect( void );
			bool isConnected( void );

			DataBaseStatement * prepare( const std::string & sql );
			int execute( const std::string & sql );

			int lastInsertedId( void );

			std::string getErrorMsg( void ) const;

		private:

			DataBaseConnectionSQLite3( const std::string& dbfile );
			DataBaseConnectionSQLite3( const DataBaseConnectionSQLite3 &obj );

		protected:

			sqlite3 * m_conn_sqlite;
			std::string m_database_file;

	};
}

#endif

/* $Id: DataBaseConnectionSQLite3.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
