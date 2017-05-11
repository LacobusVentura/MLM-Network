/*!
	\file PropagationStep.hpp
	\brief Propagation Step Object Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __PROPAGATIONSTEP_HPP__
#define __PROPAGATIONSTEP_HPP__

#include "Serializable.hpp"

namespace MLM
{
	class PropagationStep : public Serializable
	{
		public:

			PropagationStep( void );
			PropagationStep( int id_rule, int seq );
			PropagationStep( int id_rule, int seq, double val, int min );
			PropagationStep( const PropagationStep &obj );
			virtual ~PropagationStep( void );

			PropagationStep& operator=( const PropagationStep& other );
			bool operator<(const PropagationStep &other) const;
			bool operator>(const PropagationStep &other) const;

			int idRule( void ) const;
			void idRule( int id );

			int sequence( void ) const;
			void sequence( int seq );

			double percentage( void ) const;
			void percentage( double val );

			int minInvitations( void ) const;
			void minInvitations( int n );

		private:

			int m_id_rule;
			int m_sequence;
			double m_percentage;
			int m_invitations;
	};
}

#endif

/* $Id: PropagationStep.hpp 441 2017-05-05 01:34:20Z tiago.ventura $ */
