/*!
	\file DataBaseConnectionSQLite3.cpp
	\brief Data Base Connection Object Implementation (SQLite3 Database)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include <map>
#include <string>
#include <utility>

#include "sqlite3.h"

#include "Exception.hpp"
#include "DataBaseConnectionSQLite3.hpp"
#include "DataBaseStatementSQLite3.hpp"


namespace MLM
{

	DataBaseConnectionSQLite3::DataBaseConnectionSQLite3( const std::string& dbfile ) :
		m_conn_sqlite(NULL),
		m_database_file(dbfile)
	{
		connect();
	}


	DataBaseConnectionSQLite3::~DataBaseConnectionSQLite3( void )
	{
		disconnect();
	}


	DataBaseConnectionSQLite3& DataBaseConnectionSQLite3::instance( void )
	{
		static DataBaseConnectionSQLite3 inst( "./database.db" );
		return inst;
	}


	std::string DataBaseConnectionSQLite3::version( void ) const
	{
		return std::string( sqlite3_libversion() );
	}


	void DataBaseConnectionSQLite3::beginTransaction( void )
	{
		execute( "BEGIN" );
	}


	void DataBaseConnectionSQLite3::commitTransaction( void )
	{
		execute( "COMMIT" );
	}


	void DataBaseConnectionSQLite3::rollbackTransaction( void )
	{
		execute( "ROLLBACK" );
	}


	bool DataBaseConnectionSQLite3::inTransaction( void )
	{
		return ( !sqlite3_get_autocommit( m_conn_sqlite ) ) ? true : false;
	}


	void DataBaseConnectionSQLite3::connect( void )
	{
		int ret = sqlite3_open_v2( m_database_file.c_str(), &m_conn_sqlite, SQLITE_OPEN_READWRITE, NULL );

		if( ret != SQLITE_OK )
		{
			std::string msg( sqlite3_errmsg( m_conn_sqlite ) );

			sqlite3_close( m_conn_sqlite );
			m_conn_sqlite = NULL;

			std::stringstream ss;
			ss << msg << " (" << m_database_file << ")";
			
			throwex( ConnectionDataBaseException( ss.str() ) );
		}

		sqlite3_busy_timeout( m_conn_sqlite, 25 );
	}


	void DataBaseConnectionSQLite3::disconnect( void )
	{
		sqlite3_close( m_conn_sqlite );
		m_conn_sqlite = NULL;
	}


	bool DataBaseConnectionSQLite3::isConnected( void )
	{
		return (!m_conn_sqlite) ? false : true;
	}


	DataBaseStatement * DataBaseConnectionSQLite3::prepare( const std::string & sql )
	{
		return new DataBaseStatementSQLite3( *this, sql );
	}


	int DataBaseConnectionSQLite3::execute( const std::string& sql )
	{
		int ret = sqlite3_exec( m_conn_sqlite, sql.c_str(), NULL, NULL, NULL );

		if ( ret != SQLITE_OK )
			throwex( QueryDataBaseException( getErrorMsg() ) );

		return sqlite3_changes( m_conn_sqlite );
	}


	int DataBaseConnectionSQLite3::lastInsertedId( void )
	{
		return sqlite3_last_insert_rowid( m_conn_sqlite );
	}


	std::string DataBaseConnectionSQLite3::getErrorMsg( void ) const
	{
		return std::string( sqlite3_errmsg( m_conn_sqlite ) );
	}

}

/* $Id: DataBaseConnectionSQLite3.cpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
