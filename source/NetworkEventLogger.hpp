/*!
	\file NetworkEventLogger.hpp
	\brief Network Event Logger Object Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __NETWORKEVENTLOGGER_HPP__
#define __NETWORKEVENTLOGGER_HPP__

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

#include "DebugLogger.hpp"
#include "NetworkEvents.hpp"
#include "GlobalEventHandler.hpp"

namespace MLM
{

	class NetworkEventLogger : public GlobalEventHandler
	{
		public:

			NetworkEventLogger( void );
			virtual ~NetworkEventLogger( void );

			void onSetRootCustomer( NetworkSetRootCustomerEvent & e );

			void onAddCustomer( NetworkAddCustomerEvent & e );
			void onRemoveCustomer( NetworkRemoveCustomerEvent & e );
			void onRearrangeCustomer( NetworkRearrangeCustomerEvent & e );

			void onPropagate( NetworkPropagateEvent & e );
			
			void onChangeCustomerScore( NetworkChangeCustomerScoreEvent & e );
			void onIncreaseCustomerScore( NetworkIncreaseCustomerScoreEvent & e );
			void onDecreaseCustomerScore( NetworkDecreaseCustomerScoreEvent & e );

			void onActivateCustomer( NetworkActivateCustomerEvent & e );
			void onDeactivateCustomer( NetworkDeactivateCustomerEvent & e );
			
		private:
		
			DebugLogger & m_console;
	};

}

#endif

/* $Id: NetworkEventLogger.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
