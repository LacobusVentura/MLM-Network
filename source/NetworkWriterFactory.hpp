/*!
	\file NetworkWriterFactory.hpp
	\brief Network Command Factory Interface (Factory Design Pattern)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __WRITERFACTORY_HPP__
#define __WRITERFACTORY_HPP__

#include <string>

#include "Writer.hpp"
#include "Exception.hpp"
#include "CustomerWriterDataBase.hpp"
#include "NetworkWriterDataBase.hpp"
#include "NetworkWriterDOT.hpp"
#include "NetworkWriterText.hpp"
#include "NetworkWriterJSON.hpp"
#include "PropagationRuleWriterText.hpp"
#include "CustomerWriterText.hpp"

namespace MLM
{
	class WriterFactory
	{
		public:

			static Writer & createNetworkWriter( std::string fmt )
			{
				if( fmt == "dot" )
				{
					static NetworkWriterDOT obj( std::cout );
					return obj;
				}
				if( fmt == "text" )
				{
					static NetworkWriterText obj( std::cout );
					return obj;
				}
				else if( fmt == "json" )
				{
					static NetworkWriterJSON obj( std::cout );
					return obj;
				}
				else
				{
					static NetworkWriterText obj( std::cout );
					return obj;
				}
			}

			static Writer & createCustomerWriter( std::string fmt )
			{
				if( fmt == "text" )
				{
					static CustomerWriterText obj( std::cout );
					return obj;
				}
				//else if( fmt == "json" )
				//{
				//	static CustomerWriterJSON obj( std::cout );
				//	return obj;
				//}
				else
				{
					static CustomerWriterText obj( std::cout );
					return obj;
				}
			}
				
				
			static Writer & createPropagationRuleWriter( std::string fmt )
			{
				if( fmt == "text" )
				{
					static PropagationRuleWriterText obj( std::cout );
					return obj;
				}
				//else if( fmt == "json" )
				//{
				//	static PropagationRuleWriterJSON obj( std::cout );
				//	return obj;
				//}
				else
				{
					static PropagationRuleWriterText obj( std::cout );
					return obj;
				}
			}
	};

}

#endif

/* $Id: NetworkWriterFactory.hpp 431 2017-05-03 18:26:28Z tiago.ventura $ */
