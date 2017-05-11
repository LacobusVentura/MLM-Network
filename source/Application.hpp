/*!
	\file Application.hpp
	\brief Application Object Abstract Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

namespace MLM
{
	class Application
	{
		public:

			virtual void run( void ) = 0;
	};
}

#endif

/* $Id: Application.hpp 383 2017-04-06 14:00:13Z tiago.ventura $ */
