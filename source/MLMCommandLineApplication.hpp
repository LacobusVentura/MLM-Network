/*!
	\file MLMCommandLineApplication.hpp
	\brief
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __MLMCOMMANDLINEAPPLICATION_HPP__
#define __MLMCOMMANDLINEAPPLICATION_HPP__

#include <vector>
#include <sstream>
#include <string>
#include <map>

#include "NetworkCommandFactory.hpp"
#include "CommandLineApplication.hpp"

namespace MLM
{

	class MLMCommandLineApplication : public CommandLineApplication
	{
		public:

			MLMCommandLineApplication( int argc, char ** argv ) :
				CommandLineApplication( argc, argv )
			{
				for( int i = 1; i < count(); i++ )
				{
					std::string arg( argument(i) );
					size_t pos = arg.find("--");

					if( pos == std::string::npos )
					{
						std::stringstream ss;
						ss << "Invalid Argument: " << argv[i];
						throwex( InvalidSyntaxException( ss.str() ) );
					}

					arg.erase( 0, pos + 2 );

					pos = arg.find("=");

					if( pos == std::string::npos )
					{
						std::stringstream ss;
						ss << "Invalid Argument: " << argv[i];
						throwex( InvalidSyntaxException( ss.str() ) );
					}

					std::string key = arg.substr( 0, pos );
					std::string value = arg.substr( pos + 1, std::string::npos );

					m_mapped_args[ key ] = value;
				}
			}


			virtual ~MLMCommandLineApplication( void ) {}


			void run( void )
			{
				Command * cmd = NetworkCommandFactory::create( m_mapped_args );
				cmd->execute();
			}


		private:

			std::map<std::string,std::string> m_mapped_args;
	};

}

#endif

/* $Id: MLMCommandLineApplication.hpp 438 2017-05-04 17:19:20Z tiago.ventura $ */
