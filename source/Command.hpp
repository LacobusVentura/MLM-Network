/*!
	\file Command.hpp
	\brief Command Object Abstract Interface (Command Design Pattern)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

namespace MLM
{
	class Command
	{
		public:

			virtual void execute( void ) = 0;
	};
}

#endif

/* $Id: Command.hpp 383 2017-04-06 14:00:13Z tiago.ventura $ */
