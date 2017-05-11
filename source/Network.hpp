/*!
	\file Network.hpp
	\brief Network Object Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __NETWORK_HPP__
#define __NETWORK_HPP__

#include <vector>
#include <ctime>

#include "Serializable.hpp"
#include "Tree.hpp"
#include "TreeNode.hpp"
#include "Customer.hpp"
#include "PropagationRule.hpp"
#include "EventDispatcher.hpp"


namespace MLM
{
	class Network : public Serializable , public EventDispatcher
	{
		friend class NetworkReaderDataBase;

		public:

			Network( void );
			Network( int id );
			Network( const Network &obj );
			virtual ~Network( void );

			Network& operator=( const Network& obj );

			void id( int id );
			int id( void ) const;

			void name( std::string name );
			std::string name( void ) const;

			void description( std::string desc );
			std::string description( void ) const;

			void creation( std::time_t ts );
			std::time_t creation( void ) const;

			void overflowCoefficient( int k );
			int overflowCoefficient( void ) const;

			void rootCustomer( const Customer& c );
			Customer * rootCustomer( void ) const;

			int customerCount( void ) const;
			int activeCustomerCount( void ) const;
			int inactiveCustomerCount( void ) const;

			const Tree<Customer> & invitationsTree( void ) const;
			const Tree<Customer> & balancedTree( void ) const;

			Customer & addCustomer( const Customer& parent, const Customer& c );
			void removeCustomer( const Customer& c );

			std::vector<Customer> propagateScore( const Customer & src, const PropagationRule & rule, double score );

			void customerAddScore( const Customer & cstmr, double score );
			void customerSubtractScore( const Customer & cstmr, double score );
			void customerSetScore( const Customer & cstmr, double score );

			void customerActivate( const Customer & cstmr );
			void customerDeactivate( const Customer & cstmr );

			Customer * searchCustomer( const Customer & cstmr );


		protected:

			int m_id;
			std::string m_name;
			std::string m_description;
			std::time_t m_creation;

			int m_coefficient;
			int m_customer_count;
			int m_inactive_customer_count;

			Tree<Customer> m_invitations;
			Tree<Customer> m_balanced;

		private:

			friend std::ostream& operator<<( std::ostream& os, const Network& obj );
	};
}

#endif

/* $Id: Network.hpp 431 2017-05-03 18:26:28Z tiago.ventura $ */
