/*!
	\file PropagationRuleWriterJSON.hpp
	\brief Propagation Rule Writer Object Interface (JSON Format)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __PROPAGATIONRULEWRITERJSON_HPP__
#define __PROPAGATIONRULEWRITERJSON_HPP__

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

#include "Writer.hpp"
#include "Serializable.hpp"

namespace MLM
{
	class PropagationRuleWriterJSON : public Writer
	{
		public:

			PropagationRuleWriterJSON( std::ostream& os );
			virtual ~PropagationRuleWriterJSON( void );

			void writeObject( const Serializable * s );


		private:

			std::ostream& m_ostream;
	};
}

#endif

/* $Id: PropagationRuleWriterJSON.hpp 439 2017-05-04 19:50:36Z tiago.ventura $ */
