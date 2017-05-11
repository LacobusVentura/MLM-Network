/*!
	\file Reader.hpp
	\brief Reader Object Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __READER_HPP__
#define __READER_HPP__

namespace MLM
{
	class Serializable;

	class Reader
	{
		public:

			virtual void readObject( Serializable * s ) = 0;
	};
}

#endif

/* $Id: Reader.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
