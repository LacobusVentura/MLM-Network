/*!
	\file Logger.hpp
	\brief Logger Object Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <ctime>
#include <string>

namespace MLM
{
	class Logger
	{
		public:

			virtual ~Logger( void ) { }

			enum LogLevel { eNoLog = 0x00, eNotice = 0x01, eDebug = 0x02, eWarning = 0x04, eError = 0x08, eFatal = 0x10, eAll = 0xFF };

			void levelFilter( LogLevel lvl ) { m_filter = lvl; }
			LogLevel levelFilter( void ) const { return m_filter; }

			void debug( const std::string& msg )  { log( msg, eDebug ); }
			void warning( const std::string& msg ) { log( msg, eWarning ); }
			void error( const std::string& msg ) { log( msg, eError ); }
			void fatal( const std::string& msg ) { log( msg, eFatal ); }
			void notice( const std::string& msg ) { log( msg, eNotice ); }

			virtual void onLog( const std::string& msg, LogLevel level ) = 0;


		protected:


			Logger( void ) : m_filter(eNoLog) { }
			
			
			std::string levelString( LogLevel level ) const
			{
				switch( level )
				{
					case eFatal   : return "FATAL";
					case eNotice  : return "NOTICE";
					case eError   : return "ERROR";
					case eWarning : return "WARNING";
					case eDebug   : return "DEBUG";
					default       : return "UNKNOWN";
				}
			}


			std::string timestamp( void ) const
			{
				time_t rawtime;
				struct tm * timeinfo;
				char buf[64];

				time (&rawtime);
				timeinfo = localtime(&rawtime);

				strftime( buf, sizeof(buf), "%d.%m.%Y %H:%M:%S", timeinfo );
				std::string str( buf );

				return str;
			}


		private:

			void log( const std::string& msg, LogLevel lvl )
			{
				if( lvl & m_filter )
					onLog( msg, lvl );
			}


		private:

			LogLevel m_filter;

	};
}

#endif

/* $Id: Logger.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
