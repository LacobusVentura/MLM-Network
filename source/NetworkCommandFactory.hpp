/*!
	\file NetworkCommandFactory.hpp
	\brief Network Command Factory Interface (Factory Design Pattern)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __COMMANDFACTORY_HPP__
#define __COMMANDFACTORY_HPP__

#include <map>
#include <string>
#include <cstdio>

#include "Exception.hpp"
#include "Command.hpp"
#include "NetworkCommands.hpp"
#include "PropagationRuleFactory.hpp"

namespace MLM
{
	class NetworkCommandFactory
	{
		public:

			static Command * create( std::map<std::string,std::string> args )
			{
				if( !args.size() )
					throwex( InvalidSyntaxException( "No arguments supplied!" ) );

				std::string cmd = args["command"];

				int net = atoi(args["network"].c_str());
				int cstmr = atoi(args["customer"].c_str());
				double score = atof(args["score"].c_str());
				int prnt = atoi(args["parent"].c_str());
				std::string output_format = args["output-format"];


				if( cmd == "networkList" )
				{
					return new NetworkListCommand();
				}
				else if( cmd == "propagationRuleInfo" )
				{
					return new PropagationRuleInfoCommand( args["rule"] );
				}
				else if( cmd == "networkInfo" )
				{
					return new NetworkInfoCommand( net );
				}
				else if( cmd == "customerInfo" )
				{
					return new CustomerInfoCommand( net, cstmr );
				}
				else if( cmd == "networkAdd" )
				{
					return new AddNetworkCommand( net, args["name"], args["description"], atoi(args["coefficient"].c_str()) );
				}
				else if( cmd == "networkSetRoot" )
				{
					return new SetRootCommand( net, cstmr );
				}
				else if( cmd == "customerAdd" )
				{
					return new AddCustomerCommand( net, prnt, cstmr );
				}
				else if( cmd == "networkDump" )
				{
					return new NetworkDumpCommand( net );
				}
				else if( cmd == "customerActivate" )
				{
					return new SetRootCommand( net, cstmr );
				}
				else if( cmd == "customerDeactivate" )
				{
					return new DeactivateCustomerCommand( net, cstmr );
				}
				else if( cmd == "customerAddScore" )
				{
					return new AddCustomerScoreCommand( net, cstmr, score );
				}
				else if( cmd == "customerSubtractScore" )
				{
					return new SubtractCustomerScoreCommand( net, cstmr, score );
				}
				else if( cmd == "customerSetScore" )
				{
					return new SetCustomerScoreCommand( net, cstmr, score );
				}
				else if( cmd == "networkPropagateScore" )
				{
					return new PropagateScoreCommand( net, cstmr, args["rule"], score );
				}
				else
				{
					std::stringstream ss;
					ss << "Invalid Command Argument: " << cmd;
					throwex( InvalidSyntaxException( ss.str() ) );
				}
			}
	};
}

#endif

/* $Id: NetworkCommandFactory.hpp 441 2017-05-05 01:34:20Z tiago.ventura $ */
