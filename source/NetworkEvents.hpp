/*!
	\file NetWorkEvents.hpp
	\brief Network Event Objects Interface/Implementation
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __NETWORKEVENTS_HPP__
#define __NETWORKEVENTS_HPP__

#include <string>
#include <vector>

#include "Event.hpp"
#include "GlobalEventHandler.hpp"
#include "Customer.hpp"
#include "Network.hpp"

namespace MLM
{
	class NetworkEvent : public Event
	{
		public:

			virtual ~NetworkEvent( void ) {}

			void id( int id ) { m_id = id; };
			int id( void ) const { return m_id; };

			const Network & network( void ) const { return m_network; };
			const Customer & customer( void ) const { return m_source; };

			virtual void dispatch( GlobalEventHandler & e ) = 0;
			virtual NetworkEvent * copy( void ) const = 0;


		protected:

			NetworkEvent( const Network & net, const Customer & cstmr ) :
				m_id(-1),
				m_network(net),
				m_source(cstmr)
			{
			}
			
			
			NetworkEvent( const NetworkEvent & obj ) :
				m_id(obj.m_id),
				m_network(obj.m_network),
				m_source(obj.m_source)
			{
			}


		private:
		
			int m_id;
			Network m_network;
			Customer m_source;
	};


	class NetworkAddCustomerEvent : public NetworkEvent
	{
		public:

			NetworkAddCustomerEvent( const Network & net, const Customer & src ) :
				NetworkEvent(net, src )
			{
			}
			

			NetworkAddCustomerEvent( const NetworkAddCustomerEvent & obj ) :
				NetworkEvent(obj)
			{
			}

			virtual ~NetworkAddCustomerEvent( void ) {}

			NetworkEvent * copy( void ) const { return new NetworkAddCustomerEvent(*this); }
			void dispatch( GlobalEventHandler & e ) { e.handleEvent( *this ); }
	};

	
	class NetworkRearrangeCustomerEvent : public NetworkAddCustomerEvent
	{
		public:

			NetworkRearrangeCustomerEvent( Network & net, Customer & src ) : NetworkAddCustomerEvent(net, src) {}
			NetworkRearrangeCustomerEvent( const NetworkRearrangeCustomerEvent & obj ) : NetworkAddCustomerEvent(obj) {}
			virtual ~NetworkRearrangeCustomerEvent( void ) {}

			NetworkEvent * copy( void ) const { return new NetworkRearrangeCustomerEvent(*this); }
			void dispatch( GlobalEventHandler & e ) { e.handleEvent( *this ); }
	};
	
	
	class NetworkRemoveCustomerEvent : public NetworkEvent
	{
		public:

			NetworkRemoveCustomerEvent( const Network & net, const Customer & src ) : NetworkEvent(net, src) {}
			NetworkRemoveCustomerEvent( const NetworkRemoveCustomerEvent & obj ) : NetworkEvent(obj) {}
			virtual ~NetworkRemoveCustomerEvent( void ) {}
			
			NetworkEvent * copy( void ) const { return new NetworkRemoveCustomerEvent(*this); }
			void dispatch( GlobalEventHandler & e ) { e.handleEvent( *this ); }
	};

	
	class NetworkSetRootCustomerEvent : public NetworkEvent
	{
		public:

			NetworkSetRootCustomerEvent( const Network & net, const Customer & src ) : NetworkEvent(net, src) {}
			NetworkSetRootCustomerEvent( const NetworkSetRootCustomerEvent & obj ) : NetworkEvent(obj) {}
			virtual ~NetworkSetRootCustomerEvent( void ) {}
			
			NetworkEvent * copy( void ) const { return new NetworkSetRootCustomerEvent(*this); }
			void dispatch( GlobalEventHandler & e ) { e.handleEvent( *this ); }
	};
	

	class NetworkPropagateEvent : public NetworkEvent
	{
		public:

			NetworkPropagateEvent( const Network & net, const Customer & src, const PropagationRule & rule, const std::vector<Customer> & affected, double score ) :
				NetworkEvent(net, src),
				m_rule(rule),
				m_affected(affected),
				m_score(score)
			{
			}


			NetworkPropagateEvent( const NetworkPropagateEvent & obj ) :
				NetworkEvent(obj),
				m_rule(obj.m_rule),
				m_affected(obj.m_affected),
				m_score(obj.m_score)
			{
			}

			virtual ~NetworkPropagateEvent( void ) {}

			std::vector<Customer> affected( void ) const { return m_affected; };
			double score( void ) const { return m_score; };
			const PropagationRule & rule( void ) const { return m_rule; };

			NetworkEvent * copy( void ) const { return new NetworkPropagateEvent(*this); }
			void dispatch( GlobalEventHandler & e ) { e.handleEvent( *this ); }

		private:
		
			PropagationRule m_rule;
			std::vector<Customer> m_affected;
			double m_score;
	};
	
	
	class NetworkChangeCustomerScoreEvent : public NetworkEvent
	{
		public:

			NetworkChangeCustomerScoreEvent( const Network & net, const Customer & src, double score ) : NetworkEvent(net, src), m_score(score) {}
			NetworkChangeCustomerScoreEvent( const NetworkChangeCustomerScoreEvent & obj ) : NetworkEvent(obj) { m_score = obj.m_score; }
			virtual ~NetworkChangeCustomerScoreEvent( void ) {}
			
			double score( void ) const { return m_score; };
			
			NetworkEvent * copy( void ) const { return new NetworkChangeCustomerScoreEvent(*this); }
			void dispatch( GlobalEventHandler & e ) { e.handleEvent( *this ); }

		private:

			double m_score;
	};
	
	
	class NetworkIncreaseCustomerScoreEvent : public NetworkChangeCustomerScoreEvent
	{
		public:

			NetworkIncreaseCustomerScoreEvent( const Network & net, const Customer & src, double score ) : NetworkChangeCustomerScoreEvent( net, src, score ) {}
			NetworkIncreaseCustomerScoreEvent( const NetworkIncreaseCustomerScoreEvent & obj ) : NetworkChangeCustomerScoreEvent(obj) {}
			virtual ~NetworkIncreaseCustomerScoreEvent( void ) {}

			NetworkEvent * copy( void ) const { return new NetworkIncreaseCustomerScoreEvent(*this); }
			void dispatch( GlobalEventHandler & e ) { e.handleEvent( *this ); }
	};
	

	class NetworkDecreaseCustomerScoreEvent : public NetworkChangeCustomerScoreEvent
	{
		public:

			NetworkDecreaseCustomerScoreEvent( const Network & net, const Customer & src, double score ) : NetworkChangeCustomerScoreEvent(net, src, score) {}
			NetworkDecreaseCustomerScoreEvent( const NetworkDecreaseCustomerScoreEvent & obj ) : NetworkChangeCustomerScoreEvent(obj) {}
			virtual ~NetworkDecreaseCustomerScoreEvent( void ) {}

			NetworkEvent * copy( void ) const { return new NetworkDecreaseCustomerScoreEvent(*this); }
			void dispatch( GlobalEventHandler & e ) { e.handleEvent( *this ); }
	};
	

	class NetworkActivateCustomerEvent : public NetworkEvent
	{
		public:

			NetworkActivateCustomerEvent( const Network & net, const Customer & src ) : NetworkEvent(net, src) {}
			NetworkActivateCustomerEvent( const NetworkActivateCustomerEvent & obj ) : NetworkEvent(obj) {}
			virtual ~NetworkActivateCustomerEvent( void ) {}

			NetworkEvent * copy( void ) const { return new NetworkActivateCustomerEvent(*this); }
			void dispatch( GlobalEventHandler & e ) { e.handleEvent( *this ); }
	};
	

	class NetworkDeactivateCustomerEvent : public NetworkEvent
	{
		public:

			NetworkDeactivateCustomerEvent( const Network & net, const Customer & src ) : NetworkEvent(net, src) {}
			NetworkDeactivateCustomerEvent( const NetworkDeactivateCustomerEvent & obj ) : NetworkEvent(obj) {}
			virtual ~NetworkDeactivateCustomerEvent( void ) {}

			NetworkEvent * copy( void ) const { return new NetworkDeactivateCustomerEvent(*this); }
			void dispatch( GlobalEventHandler & e ) { e.handleEvent( *this ); }
	};

}

#endif

/* $Id: NetworkEvents.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */

