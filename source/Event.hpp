/*!
	\file Event.hpp
	\brief Events Object and Event Handling Object Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include <string>

namespace MLM
{
	class GlobalEventHandler;

	class Event
	{
		public:

			virtual void dispatch( GlobalEventHandler & ) = 0;

	};
}
#endif

/* $Id: Event.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
