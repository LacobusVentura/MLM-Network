/*!
	\file PropagationRule.hpp
	\brief Interface of a Propagation Rule
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __PROPAGATIONRULE_HPP__
#define __PROPAGATIONRULE_HPP__

#include <string>
#include <vector>

#include "Serializable.hpp"
#include "PropagationStep.hpp"

namespace MLM
{
	class PropagationRule : public Serializable
	{
		public:

			PropagationRule( void );
			PropagationRule( int id );
			PropagationRule( int id, std::string name );
			PropagationRule( const PropagationRule &obj );
			virtual ~PropagationRule( void );
			
			PropagationRule& operator=( const PropagationRule& obj );

			int id( void ) const;
			void id( int id );

			std::string name( void ) const;
			void name( const std::string& name  );

			std::string description( void ) const;
			void description( const std::string& desc );

			std::vector<PropagationStep> stepList( void ) const;
			void stepList( const std::vector<PropagationStep>& lst );

		private:

			int m_id;
			std::string m_name;
			std::string m_description;
			std::vector<PropagationStep> m_steps;
	};
}

#endif

/* $Id: PropagationRule.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
