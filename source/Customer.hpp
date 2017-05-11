/*!
	\file Customer.hpp
	\brief Customer Object Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __CUSTOMER_HPP__
#define __CUSTOMER_HPP__

#include <ctime>
#include <iostream>

#include "TreeNode.hpp"
#include "Serializable.hpp"

namespace MLM
{
	class Network;

	class Customer : public TreeNode<Customer>, public Serializable
	{
		public:

			Customer( void );
			Customer( int id );
			Customer( const Customer &obj );
			virtual ~Customer( void );

			Customer& operator=( const Customer& obj );
			bool operator==(const Customer & other) const;
			bool operator!=(const Customer & other) const;

			int id( void ) const;
			void id( int id );

			int network( void ) const;
			void network( int id );

			int invitationParent( void ) const;
			void invitationParent( int id );

			int overflowParent( void ) const;
			void overflowParent( int id );

			int invitationDepth( void ) const;
			void invitationDepth( int n );

			int overflowDepth( void ) const;
			void overflowDepth( int n );

			bool active( void ) const;
			void active( bool active );

			double score( void ) const;
			void score( double s );

			void scoreAdd( double s );
			void scoreSubtract( double s );

			void deactivate( void );
			void activate( void );

			std::time_t creation( void ) const;
			void creation( std::time_t ts );

		private:

			friend std::ostream& operator<<( std::ostream& os, const Customer& obj );

			int m_id;
			double m_score;
			bool m_active;
			std::time_t m_creation;

			int m_id_network;
			int m_id_invitation_parent;
			int m_id_overflow_parent;
			int m_invitation_depth;
			int m_overflow_depth;
	};
}

#endif

/* $Id: Customer.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
