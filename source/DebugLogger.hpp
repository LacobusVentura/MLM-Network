/*!
	\file DebugLogger.hpp
	\brief Debug/Logger Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __DEBUGLOGGER_HPP__
#define __DEBUGLOGGER_HPP__


#include <iostream>
#include <string>
#include <fstream>

#include "Logger.hpp"


namespace MLM
{

	class DebugLogger : public Logger
	{
		public:

			virtual ~DebugLogger( void );

			static DebugLogger& getConsoleInstance( void );
			static DebugLogger& getLogFileInstance( void );

			void onLog( const std::string& str, LogLevel level );

		private:

			DebugLogger( std::ostream& os = std::cout );
			DebugLogger( std::string filename );
			DebugLogger( const DebugLogger& );
			DebugLogger& operator=( const DebugLogger& );


		private:

			std::ofstream m_ofstream;
			std::ostream& m_ostream;
	};
};

#endif

/* $Id: DebugLogger.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */

