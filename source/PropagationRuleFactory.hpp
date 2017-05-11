/*!
	\file PropagationRuleFactory.hpp
	\brief Interface Propagation Rule Factory
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __PROPAGATIONRULEFACTORY_HPP__
#define __PROPAGATIONRULEFACTORY_HPP__

#include <vector>
#include <string>

#include "Exception.hpp"
#include "PropagationRule.hpp"
#include "PropagationStep.hpp"
#include "DataBaseConnectionSQLite3.hpp"
#include "PropagationRuleReaderDataBase.hpp"

namespace MLM
{

	class PropagationRuleFactory
	{

		public:

			static PropagationRule rule( std::string ruleName )
			{
				if( ruleName == "signing" )
				{
					return PropagationRuleFactory::signing();
				}
				else if( ruleName == "ensurance" )
				{
					return ensurance();
				}
				else if( ruleName == "purchasing" )
				{
					return purchasing();
				}
				else
				{
					std::stringstream ss;
					ss << "Invalid Propagation Rule Name: " << ruleName;
					throwex( InvalidSyntaxException( ss.str() ) );
				}
			}


			static PropagationRule signing( void )
			{
				static PropagationRule rl = getPropagationRule(1);
				return rl;
			}


			static PropagationRule ensurance( void )
			{
				static PropagationRule rl = getPropagationRule(2);
				return rl;
			}


			static PropagationRule purchasing( void )
			{
				static PropagationRule rl = getPropagationRule(3);
				return rl;
			}


		private:


			static PropagationRule getPropagationRule( int id )
			{
				PropagationRule rl( id );
				PropagationRuleReaderDataBase rd( DataBaseConnectionSQLite3::instance() );
				rl.readFrom( &rd );
				return rl;
			}
	};

}

#endif

/* $Id: PropagationRuleFactory.hpp 405 2017-04-20 12:56:27Z tiago.ventura $ */
