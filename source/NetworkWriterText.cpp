/*!
	\file NetworkWriterText.cpp
	\brief Network Writer Object Implementation (Text Format)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

#include "Exception.hpp"
#include "Writer.hpp"
#include "Serializable.hpp"
#include "Network.hpp"
#include "NetworkWriterText.hpp"

namespace MLM
{

	NetworkWriterText::NetworkWriterText( std::ostream& os ) :
		m_full_info( false ),
		m_ostream( os )
	{
	}


	NetworkWriterText::~NetworkWriterText( void )
	{
	}


	void NetworkWriterText::writeObject( const Serializable * s )
	{
		const Network & net = dynamic_cast<const Network&>( *s );

		std::time_t tm = net.creation();
		std::string asctm = std::asctime( std::localtime( &tm ) );
		asctm.resize( asctm.size() - 1 );

		m_ostream << std::endl << "NETWORK INFO" << std::endl << std::endl;

		m_ostream << "	ID: " << net.id() << std::endl;
		m_ostream << "	Name: " << net.name() << std::endl;
		m_ostream << "	Description: " << net.description() << std::endl;
		m_ostream << "	Coefficient: " << net.overflowCoefficient() << std::endl;
		m_ostream << "	Creation: " << asctm << " (epoch: " << tm << ")" << std::endl << std::endl;


		m_ostream << "	Customer Count: " << net.customerCount() << std::endl;
		m_ostream << "	Customers Active: " << net.activeCustomerCount() << std::endl;
		m_ostream << "	Customers Inactive: " << net.inactiveCustomerCount() << std::endl << std::endl;

		m_ostream << "	Invitation Tree Depth: " << net.invitationsTree().maxDepth() << std::endl;
		m_ostream << "	Balanced Tree Depth: " << net.balancedTree().maxDepth() << std::endl << std::endl;

		if( net.rootCustomer() )
		{
			m_ostream << "	Root Customer ID: " << net.rootCustomer()->id() << std::endl << std::endl;

			if( m_full_info && !net.rootCustomer()->isLeaf() )
			{
				std::vector<Customer*> vec = net.invitationsTree().nodeList();

				m_ostream << "	Invitation Tree: ";

				for( std::size_t i = 0; i < vec.size(); i++ )
				{
					Customer * node = vec[i];

					if( node->parent() )
						m_ostream << node->id() << " -> " << node->parent()->id() << "; ";
				}

				m_ostream << std::endl << std::endl;

				vec = net.balancedTree().nodeList();

				m_ostream << "	Balanced Tree: ";

				for( std::size_t i = 0; i < vec.size(); i++ )
				{
					Customer * node = vec[i];

					if( node->parent() )
						m_ostream << node->id() << " -> " << node->parent()->id() << "; ";
				}

				m_ostream << std::endl;
			}
		}
	}
}

/* $Id: NetworkWriterText.cpp 441 2017-05-05 01:34:20Z tiago.ventura $ */
