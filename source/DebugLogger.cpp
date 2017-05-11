/*!
	\file DebugLogger.cpp
	\brief
*/

#include <iostream>

#include "Logger.hpp"
#include "DebugLogger.hpp"

namespace MLM
{

	DebugLogger::DebugLogger( std::string filename ) :
		m_ofstream( filename.c_str(), std::fstream::out | std::fstream::app  ),
		m_ostream( m_ofstream )
	{
		levelFilter( eAll );
		//levelFilter( (LogLevel) (eFatal | eError | eWarning | eNotice) );
	}


	DebugLogger::DebugLogger( std::ostream& os ) :
		m_ofstream(),
		m_ostream( os )
	{
		levelFilter( eAll );
		//levelFilter( (LogLevel) (eFatal | eError | eWarning | eNotice) );
	}


 	DebugLogger::DebugLogger( const DebugLogger& obj ) :
	 	m_ofstream(),
		m_ostream( obj.m_ostream )
 	{
 	}



	DebugLogger::~DebugLogger( void )
	{
	}


	DebugLogger& DebugLogger::operator=( const DebugLogger& obj )
	{
		(void) obj;
		return *this;
	}


	DebugLogger& DebugLogger::getConsoleInstance( void )
	{
		static DebugLogger inst( std::cout );
		return inst;
	}


	DebugLogger& DebugLogger::getLogFileInstance( void )
	{
		static DebugLogger inst( "./MLM.log" );
		return inst;
	}


	void DebugLogger::onLog( const std::string& msg, LogLevel level )
	{
		m_ostream << "[" << timestamp() << " " << levelString(level) << "] " << msg << std::endl;
	}

};

/* $Id: DebugLogger.cpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
