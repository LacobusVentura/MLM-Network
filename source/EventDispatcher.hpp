/*!
	\file EventDispatcher.hpp
	\brief Events Dispatcher/Handling Control Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __EVENTDISPATCHER_HPP__
#define __EVENTDISPATCHER_HPP__

#include <vector>
#include <algorithm>

#include "Event.hpp"

namespace MLM
{
	class EventDispatcher
	{
		public:

			void attachEventHandler( GlobalEventHandler & e ) { m_handlers.push_back( &e ); }
			void detachEventHandler( GlobalEventHandler & e ) { m_handlers.erase( std::remove(m_handlers.begin(), m_handlers.end(), &e ), m_handlers.end()); }
			void detachAllHandlers( void ) { m_handlers.clear(); }

		protected:
		
			void dispatchEvent( Event & e ) const
			{
				for( std::size_t i = 0; i < m_handlers.size(); i++ )
					e.dispatch( *m_handlers[i] );
			}

		private:

			std::vector<GlobalEventHandler*> m_handlers;

	};
}

#endif

/* $Id: EventDispatcher.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
