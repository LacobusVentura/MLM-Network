/*!
	\file Writer.hpp
	\brief Writer Object Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __WRITER_HPP__
#define __WRITER_HPP__

namespace MLM
{
	class Serializable;

	class Writer
	{
		public:

			virtual void writeObject( const Serializable * obj ) = 0;

	};
}

#endif

/* $Id: Writer.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
