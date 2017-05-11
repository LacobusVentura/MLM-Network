/*!
	\file NetworkEventHistoryRecorder.hpp
	\brief Network Event Recorder Object Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __NETWORKEVENTRECORDER_HPP__
#define __NETWORKEVENTRECORDER_HPP__

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

#include "NetworkEvents.hpp"
#include "GlobalEventHandler.hpp"
#include "NetworkEventHistory.hpp"

namespace MLM
{

	class NetworkEventHistoryRecorder : public GlobalEventHandler
	{
		public:

			NetworkEventHistoryRecorder( NetworkEventHistory & hist );
			virtual ~NetworkEventHistoryRecorder( void );

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
		
			NetworkEventHistory & m_network_event_history;
	};

}

#endif

/* $Id: NetworkEventHistoryRecorder.hpp 443 2017-05-05 01:35:27Z tiago.ventura $ */
