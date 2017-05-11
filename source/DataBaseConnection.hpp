/*!
	\file DataBaseConnection.hpp
	\brief Data Base Connection Object Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __DATABASECONNECTION_HPP__
#define __DATABASECONNECTION_HPP__

#include <map>
#include <vector>
#include <string>


namespace MLM
{
	class DataBaseStatement;
	class DataBaseColumn;

	class DataBaseConnection
	{
		public:

			DataBaseConnection( void ) :
				m_host(),
				m_port(0),
				m_database(),
				m_username(),
				m_password()
			{
			}


			virtual ~DataBaseConnection( void )
			{
			}


			std::string host( void ) const { return m_host; }
			void host( std::string hst ) { m_host = hst; }

			int port( void ) const { return m_port; }
			void port( int prt  ) { m_port = prt; }

			std::string database( void ) const { return m_database; }
			void database( std::string db ) { m_database = db; }

			std::string username( void ) const { return m_username; }
			void username( std::string user ) { m_username = user; }

			std::string password( void ) const { return m_password; }
			void password( std::string pass ) { m_password = pass; }


			virtual void connect( void ) = 0;
			virtual void disconnect( void ) = 0;
			virtual bool isConnected( void ) = 0;

			virtual void beginTransaction( void ) = 0;
			virtual void commitTransaction( void ) = 0;
			virtual void rollbackTransaction( void ) = 0;
			virtual bool inTransaction( void ) = 0;

			virtual DataBaseStatement * prepare( const std::string & sql ) = 0;
			virtual int execute( const std::string & sql ) = 0;

			virtual int lastInsertedId( void ) = 0;

			virtual std::string getErrorMsg( void ) const = 0;
			virtual std::string version( void ) const = 0;


		private:

			std::string m_host;
			int m_port;
			std::string m_database;
			std::string m_username;
			std::string m_password;
	};
}

#endif

/* $Id: DataBaseConnection.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
