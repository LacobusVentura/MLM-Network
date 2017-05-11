/*!
	\file CommandLineApplication.hpp
	\brief Command Line Application Object Abstract Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __COMMANDLINEAPPLICATION_HPP__
#define __COMMANDLINEAPPLICATION_HPP__

#include <vector>
#include <string>

#include "Application.hpp"

namespace MLM
{
	class CommandLineApplication : public Application
	{
		public:

			CommandLineApplication( int argc, char ** argv )
			{
				for( int i = 0; i < argc; i++ )
					m_args.push_back( std::string( argv[i] ) );
			}


			virtual ~CommandLineApplication( void )
			{
			}


			std::string argument( int idx )
			{
				return m_args[ idx ];
			}


			int count( void )
			{
				return m_args.size();
			}


			virtual void run( void ) = 0;


		private:

			std::vector<std::string> m_args;
	};
}

#endif

/* $Id: CommandLineApplication.hpp 438 2017-05-04 17:19:20Z tiago.ventura $ */
