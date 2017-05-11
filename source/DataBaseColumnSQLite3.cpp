/*!
	\file DataBaseColumnSQLite3.cpp
	\brief Data Base Column Object Implementation (SQLite3 Implementation)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include <string>

#include <sqlite3.h>

#include "DataBaseColumnSQLite3.hpp"
#include "DataBaseStatementSQLite3.hpp"

namespace MLM
{

	DataBaseColumnSQLite3::DataBaseColumnSQLite3( DataBaseStatementSQLite3& stmnt, int index ) :
		DataBaseColumn( stmnt, index ),
		m_stmnt_sqlite(stmnt.m_stmnt_sqlite)
	{
	}


	DataBaseColumnSQLite3::~DataBaseColumnSQLite3( void )
	{
	}


	std::string DataBaseColumnSQLite3::name( void )
	{
		return std::string( sqlite3_column_name(m_stmnt_sqlite, m_index) );
	}


	int DataBaseColumnSQLite3::size( void )
	{
		return sqlite3_column_bytes( m_stmnt_sqlite, m_index );
	}


	int DataBaseColumnSQLite3::getInt( void )
	{
		return sqlite3_column_int( m_stmnt_sqlite, m_index );
	}


	unsigned int DataBaseColumnSQLite3::getUInt( void )
	{
		return static_cast<unsigned>(getInt64());
	}


	long long DataBaseColumnSQLite3::getInt64( void )
	{
		return sqlite3_column_int64( m_stmnt_sqlite, m_index );
	}


	double DataBaseColumnSQLite3::getDouble( void )
	{
		return sqlite3_column_double( m_stmnt_sqlite, m_index );
	}


	std::string DataBaseColumnSQLite3::getText( void )
	{
		const char * txt = reinterpret_cast<const char*>(sqlite3_column_text(m_stmnt_sqlite, m_index));
		return std::string( (txt) ? txt : "" );
	}


	const void * DataBaseColumnSQLite3::getBlob( void )
	{
		return sqlite3_column_blob( m_stmnt_sqlite, m_index );
	}


	bool DataBaseColumnSQLite3::isInteger( void )
	{
		return( sqlite3_column_type( m_stmnt_sqlite, m_index ) == SQLITE_INTEGER );
	}


	bool DataBaseColumnSQLite3::isFloat( void )
	{
		return( sqlite3_column_type( m_stmnt_sqlite, m_index ) == SQLITE_FLOAT );
	}


	bool DataBaseColumnSQLite3::isText( void )
	{
		return( sqlite3_column_type( m_stmnt_sqlite, m_index ) == SQLITE_TEXT );
	}


	bool DataBaseColumnSQLite3::isBlob( void )
	{
		return( sqlite3_column_type( m_stmnt_sqlite, m_index ) == SQLITE_BLOB );
	}


	bool DataBaseColumnSQLite3::isNull( void )
	{
		return( sqlite3_column_type( m_stmnt_sqlite, m_index ) == SQLITE_NULL );
	}

}

/* $Id: DataBaseColumnSQLite3.cpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
