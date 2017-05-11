/*!
	\file GlobalEventHandler.hpp
	\brief Global Event Handling Object Interface (Visitor Design Pattern)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __GLOBALEVENTHANDLER_HPP__
#define __GLOBALEVENTHANDLER_HPP__

#include "Event.hpp"

namespace MLM
{
	// Network Events
	class NetworkSetRootCustomerEvent;
	class NetworkAddCustomerEvent;
	class NetworkRearrangeCustomerEvent;
	class NetworkRemoveCustomerEvent;
	class NetworkPropagateEvent;
	class NetworkChangeCustomerScoreEvent;
	class NetworkIncreaseCustomerScoreEvent;
	class NetworkDecreaseCustomerScoreEvent;
	class NetworkActivateCustomerEvent;
	class NetworkDeactivateCustomerEvent;


	class GlobalEventHandler
	{
		public:

			void handleEvent( NetworkSetRootCustomerEvent & e ) { onSetRootCustomer( e ); }
			void handleEvent( NetworkAddCustomerEvent & e ) { onAddCustomer( e ); }
			void handleEvent( NetworkRearrangeCustomerEvent & e ) { onRearrangeCustomer( e ); }
			void handleEvent( NetworkRemoveCustomerEvent & e ) { onRemoveCustomer( e ); }
			void handleEvent( NetworkPropagateEvent & e ) { onPropagate( e ); }
			void handleEvent( NetworkChangeCustomerScoreEvent & e ) { onChangeCustomerScore( e ); }
			void handleEvent( NetworkIncreaseCustomerScoreEvent & e ) { onIncreaseCustomerScore( e ); }
			void handleEvent( NetworkDecreaseCustomerScoreEvent & e ) { onDecreaseCustomerScore( e ); }
			void handleEvent( NetworkActivateCustomerEvent & e ) { onActivateCustomer( e ); }
			void handleEvent( NetworkDeactivateCustomerEvent & e ) { onDeactivateCustomer( e ); }


			virtual void onSetRootCustomer( NetworkSetRootCustomerEvent & e ) = 0;
			virtual void onAddCustomer( NetworkAddCustomerEvent & e ) = 0;
			virtual void onRearrangeCustomer( NetworkRearrangeCustomerEvent & e ) = 0;
			virtual void onRemoveCustomer( NetworkRemoveCustomerEvent & e ) = 0;
			virtual void onPropagate( NetworkPropagateEvent & e ) = 0;
			virtual void onChangeCustomerScore( NetworkChangeCustomerScoreEvent & e ) = 0;
			virtual void onIncreaseCustomerScore( NetworkIncreaseCustomerScoreEvent & e ) = 0;
			virtual void onDecreaseCustomerScore( NetworkDecreaseCustomerScoreEvent & e ) = 0;
			virtual void onActivateCustomer( NetworkActivateCustomerEvent & e ) = 0;
			virtual void onDeactivateCustomer( NetworkDeactivateCustomerEvent & e ) = 0;
	};
}

#endif

/* $Id: GlobalEventHandler.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
