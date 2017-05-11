/*!
	\file DataBaseStatementSQLite3.cpp
	\brief Data Base Statement Object Implementation (SQLite3 Database)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include <iostream>
#include <map>
#include <string>

#include "sqlite3.h"

#include "DebugLogger.hpp"

#include "Exception.hpp"
#include "DataBaseConnectionSQLite3.hpp"
#include "DataBaseStatementSQLite3.hpp"
#include "DataBaseColumnSQLite3.hpp"


namespace MLM
{

	DataBaseStatementSQLite3::DataBaseStatementSQLite3( DataBaseConnectionSQLite3& dbconn, std::string sql ) :
		DataBaseStatement( dbconn, sql ),
		m_stmnt_sqlite(NULL),
		m_conn_sqlite(dbconn.m_conn_sqlite),
		m_cols_count(0),
		m_ok(false),
		m_done(false),
		m_columns_map()
	{
		int ret = sqlite3_prepare_v2( m_conn_sqlite, sql.c_str(), static_cast<int>(sql.size()), &m_stmnt_sqlite, NULL );

		if( ret != SQLITE_OK )
		{
			sqlite3_finalize( m_stmnt_sqlite );
			m_stmnt_sqlite = NULL;

			std::stringstream ss;
			ss << "Cant prepare query: \"" << sql << "\"";

			throwex( DataBaseException( ss.str() ) );
		}

		m_cols_count = sqlite3_column_count(m_stmnt_sqlite);
	}


	DataBaseStatementSQLite3::~DataBaseStatementSQLite3( void )
	{
		sqlite3_finalize( m_stmnt_sqlite );
	}


	bool DataBaseStatementSQLite3::fetch( void )
	{
		if( !m_done )
		{
			int ret = sqlite3_step( m_stmnt_sqlite );

			if( ret == SQLITE_ROW )
			{
				m_ok = true;
			}
			else if ( ret == SQLITE_DONE )
			{
				m_ok = false;
				m_done = true;
			}
			else
			{
				m_ok = false;
				m_done = false;

				throwex( DataBaseException( getErrorMsg() ) );
			}
		}
		else
		{
			throwex( DataBaseException( "Statement needs to be reseted." ) );
		}

		return m_ok;
	}


	int DataBaseStatementSQLite3::execute( void )
	{
		int ret = sqlite3_step( m_stmnt_sqlite );

		if( !m_done )
		{
			if( ret == SQLITE_DONE )
			{
				m_ok = false;
				m_done = true;
			}
			else if ( ret == SQLITE_ROW )
			{
				m_ok = false;
				m_done = false;

				throwex( DataBaseException( "execute() does not expect results. Use fetch() instead." ) );
			}
			else
			{
				m_ok = false;
				m_done = false;

				throwex( DataBaseException( getErrorMsg() ) );
			}

		}
		else
		{
			throwex( DataBaseException( "Statement needs to be reseted." ) );
		}

		return sqlite3_changes( m_conn_sqlite );
	}


	int DataBaseStatementSQLite3::columnCount( void )
	{
		return m_cols_count;
	}


	int DataBaseStatementSQLite3::rowCount( void )
	{
		return -1;
	}


	DataBaseColumn * DataBaseStatementSQLite3::getColumn( int idx )
	{
		if(!m_ok)
			throwex( DataBaseException( "No row to get a column from. executeStep() was not called, or returned false.") );

		if( (idx < 0) || (idx >= m_cols_count) )
			throwex( DataBaseException( "Column index out of range." ) );

		return new DataBaseColumnSQLite3( *this, idx );
	}


	DataBaseColumn * DataBaseStatementSQLite3::getColumn( std::string name )
	{
		if(!m_ok)
			throwex( DataBaseException( "No row to get a column from. executeStep() was not called, or returned false.") );

		int idx = getColumnIndex( name );
		return new DataBaseColumnSQLite3( *this, idx );
	}


	void DataBaseStatementSQLite3::reset( void )
	{
		m_ok = false;
		m_done = false;

		sqlite3_reset( m_stmnt_sqlite );
	}


	void DataBaseStatementSQLite3::setAttribute( std::string name, std::string value )
	{
		int idx = sqlite3_bind_parameter_index( m_stmnt_sqlite, name.c_str() );
		int ret = sqlite3_bind_text( m_stmnt_sqlite, idx, value.c_str(), static_cast<int>(value.size()), SQLITE_STATIC );

		if( SQLITE_OK != ret )
			throwex( DataBaseException( getErrorMsg() ) );
	}


	void DataBaseStatementSQLite3::setAttribute( std::string name, int value )
	{
		int idx = sqlite3_bind_parameter_index( m_stmnt_sqlite, name.c_str() );
		int ret = sqlite3_bind_int( m_stmnt_sqlite, idx, value );

		if( SQLITE_OK != ret )
			throwex( DataBaseException( getErrorMsg() ) );
	}


	void DataBaseStatementSQLite3::setAttribute( std::string name, double value )
	{
		int idx = sqlite3_bind_parameter_index( m_stmnt_sqlite, name.c_str() );
		int ret = sqlite3_bind_double( m_stmnt_sqlite, idx, value );

		if( SQLITE_OK != ret )
			throwex( DataBaseException( getErrorMsg() ) );
	}


	void DataBaseStatementSQLite3::setAttribute( std::string name, long long value )
	{
		int idx = sqlite3_bind_parameter_index( m_stmnt_sqlite, name.c_str() );
		int ret = sqlite3_bind_int64( m_stmnt_sqlite, idx, value );

		if( SQLITE_OK != ret )
			throwex( DataBaseException( getErrorMsg() ) );
	}


	void DataBaseStatementSQLite3::setAttributeNull( std::string name )
	{
		int idx = sqlite3_bind_parameter_index( m_stmnt_sqlite, name.c_str() );
		int ret = sqlite3_bind_null( m_stmnt_sqlite, idx );

		if( SQLITE_OK != ret )
			throwex( DataBaseException( getErrorMsg() ) );
	}


	void DataBaseStatementSQLite3::setAttribute( int idx, std::string value )
	{
		int ret = sqlite3_bind_text( m_stmnt_sqlite, idx, value.c_str(), static_cast<int>(value.size()), SQLITE_STATIC );

		if( SQLITE_OK != ret )
			throwex( DataBaseException( getErrorMsg() ) );
	}


	void DataBaseStatementSQLite3::setAttribute( int idx, int value )
	{
		int ret = sqlite3_bind_int( m_stmnt_sqlite, idx, value );

		if( SQLITE_OK != ret )
			throwex( DataBaseException( getErrorMsg() ) );
	}


	void DataBaseStatementSQLite3::setAttribute( int idx, double value )
	{
		int ret = sqlite3_bind_double( m_stmnt_sqlite, idx, value );

		if( SQLITE_OK != ret )
			throwex( DataBaseException( getErrorMsg() ) );
	}


	void DataBaseStatementSQLite3::setAttribute( int idx, long long value )
	{
		int ret = sqlite3_bind_int64( m_stmnt_sqlite, idx, value );

		if( SQLITE_OK != ret )
			throwex( DataBaseException( getErrorMsg() ) );
	}


	void DataBaseStatementSQLite3::setAttributeNull( int idx )
	{
		int ret = sqlite3_bind_null( m_stmnt_sqlite, idx );

		if( SQLITE_OK != ret )
			throwex( DataBaseException( getErrorMsg() ) );
	}


	void DataBaseStatementSQLite3::resetAttributes( void )
	{
		int ret = sqlite3_clear_bindings( m_stmnt_sqlite );

		if( SQLITE_OK != ret )
			throwex( DataBaseException( getErrorMsg() ) );

	}


	int DataBaseStatementSQLite3::getColumnIndex( std::string name )
	{
		std::map< std::string, int >::iterator it;

		if( m_columns_map.empty() )
		{
			for( int i = 0; i < m_cols_count; i++ )
			{
				std::string key( sqlite3_column_name( m_stmnt_sqlite, i ) );
				m_columns_map[ key ] = i;
			}
		}

		it = m_columns_map.find( name );

		if( it == m_columns_map.end() )
		{
			std::stringstream ss;
			ss << "Column '" << name << "' not found.";

			throwex( DataBaseException( ss.str() ) );
		}

		return (*it).second;
	}


	std::string DataBaseStatementSQLite3::getErrorMsg( void ) const
	{
		return std::string( sqlite3_errmsg( m_conn_sqlite ) );
	}

}

/* $Id: DataBaseStatementSQLite3.cpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
