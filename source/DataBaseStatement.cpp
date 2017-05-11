/*!
	\file DataBaseStatement.cpp
	\brief Data Base Statement Object Implementation
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include <vector>
#include <string>

#include "DataBaseColumn.hpp"
#include "DataBaseStatement.hpp"

namespace MLM
{

	DataBaseStatement::DataBaseStatement( DataBaseConnection& dbconn, std::string sql ) :
		m_conn(dbconn),
		m_sql(sql)
	{
	}


	DataBaseStatement::~DataBaseStatement( void )
	{
	}


	std::string DataBaseStatement::sql( void ) const
	{
		return m_sql;
	}
	
	
	DataBaseConnection& DataBaseStatement::conn( void ) const
	{
		return m_conn;
	}
	

	int DataBaseStatement::getIntColumn( int idx )
	{
		DataBaseColumn * c = getColumn( idx );
		int n = c->getInt();
		delete c;
		return n;
	}


	long long DataBaseStatement::getInt64Column( int idx )
	{
		DataBaseColumn * c = getColumn( idx );
		long long n64 = c->getInt();
		delete c;
		return n64;
	}


	std::string DataBaseStatement::getTextColumn( int idx )
	{
		DataBaseColumn * c = getColumn( idx );
		std::string s = c->getText();
		delete c;
		return s;
	}


	double DataBaseStatement::getDoubleColumn( int idx )
	{
		DataBaseColumn * c = getColumn( idx );
		int d = c->getDouble();
		delete c;
		return d;
	}


	int DataBaseStatement::getIntColumn( std::string name )
	{
		DataBaseColumn * c = getColumn( name );
		int n = c->getInt();
		delete c;
		return n;
	}


	long long DataBaseStatement::getInt64Column( std::string name )
	{
		DataBaseColumn * c = getColumn( name );
		long long n64 = c->getInt();
		delete c;
		return n64;
	}


	std::string DataBaseStatement::getTextColumn( std::string name )
	{
		DataBaseColumn * c = getColumn( name );
		std::string s = c->getText();
		delete c;
		return s;
	}


	double DataBaseStatement::getDoubleColumn( std::string name )
	{
		DataBaseColumn * c = getColumn( name );
		int d = c->getDouble();
		delete c;
		return d;
	}
}

/* $Id: DataBaseStatement.cpp 362 2017-03-29 20:16:08Z tiago.ventura $ */
