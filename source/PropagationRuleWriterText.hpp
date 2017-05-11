/*!
	\file PropagationRuleWriterText.hpp
	\brief Propagation Rule Writer Object Interface (Text Format)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __PROPAGATIONRULEWRITERTEXT_HPP__
#define __PROPAGATIONRULEWRITERTEXT_HPP__

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

#include "Writer.hpp"
#include "Serializable.hpp"

namespace MLM
{
	class PropagationRuleWriterText : public Writer
	{
		public:

			PropagationRuleWriterText( std::ostream& os );
			virtual ~PropagationRuleWriterText( void );

			void writeObject( const Serializable * s );


		private:

			std::ostream& m_ostream;
	};
}

#endif

/* $Id: PropagationRuleWriterText.hpp 439 2017-05-04 19:50:36Z tiago.ventura $ */
