/*!
	\file DataBaseStatement.hpp
	\brief Data Base Statement Object Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __DATABASESTATEMENT_HPP__
#define __DATABASESTATEMENT_HPP__

#include <vector>
#include <string>

namespace MLM
{
	class DataBaseConnection;
	class DataBaseColumn;

	class DataBaseStatement
	{

		public:

			DataBaseStatement( DataBaseConnection& dbconn, std::string sql );
			virtual ~DataBaseStatement( void );

			std::string sql( void ) const;
			DataBaseConnection& conn( void ) const;

			int getIntColumn( int idx );
			long long getInt64Column( int idx );
			std::string getTextColumn( int idx );
			double getDoubleColumn( int idx );

			int getIntColumn( std::string name );
			long long getInt64Column( std::string name );
			std::string getTextColumn( std::string name );
			double getDoubleColumn( std::string name );
			
			virtual int execute( void ) = 0;
			virtual bool fetch( void ) = 0;

			virtual int columnCount( void ) = 0;
			virtual int rowCount( void ) = 0;

			virtual DataBaseColumn * getColumn( int idx ) = 0;
			virtual DataBaseColumn * getColumn( std::string name ) = 0;

			virtual void reset( void ) = 0;

			virtual void setAttribute( std::string name, std::string value ) = 0;
			virtual void setAttribute( std::string name, int value ) = 0;
			virtual void setAttribute( std::string name, long long value ) = 0;
			virtual void setAttribute( std::string name, double value ) = 0;
			virtual void setAttributeNull( std::string name ) = 0;

			virtual void setAttribute( int idx, std::string value ) = 0;
			virtual void setAttribute( int idx, int value ) = 0;
			virtual void setAttribute( int idx, long long value ) = 0;
			virtual void setAttribute( int idx, double value ) = 0;
			virtual void setAttributeNull( int idx ) = 0;

			virtual void resetAttributes( void ) = 0;

			virtual std::string getErrorMsg( void ) const = 0;
			virtual int getColumnIndex( std::string name ) = 0;


		protected:

			DataBaseConnection & m_conn;
			std::string m_sql;

	};
}

#endif

/* $Id: DataBaseStatement.hpp 372 2017-03-31 10:30:51Z tiago.ventura $ */
