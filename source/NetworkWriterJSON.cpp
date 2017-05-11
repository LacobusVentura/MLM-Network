/*!
	\file NetworkWriterJSON.cpp
	\brief Network Writer Object Implementation (JSON Format)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>

#include "Exception.hpp"
#include "Serializable.hpp"
#include "Network.hpp"
#include "NetworkWriterJSON.hpp"


namespace MLM
{

	NetworkWriterJSON::NetworkWriterJSON( std::ostream& os ) :
		m_full_info( false ),
		m_ostream( os )
	{
	}


	NetworkWriterJSON::~NetworkWriterJSON( void )
	{
	}


	void NetworkWriterJSON::writeObject( const Serializable * s )
	{
		const Network & net = dynamic_cast<const Network&>( *s );
		std::vector<Customer*> vec;

		m_ostream << "{" << std::endl;
		m_ostream << "\t\"IndicationsTree\": {" << std::endl;
		m_ostream << "\t\t" << "\"Customers\": [" << std::endl;

		vec = net.invitationsTree().nodeList();

		for( std::size_t i = 0; i < vec.size(); i++ )
		{
			Customer * node = vec[i];
			Customer * parent = node->parent();

			m_ostream << "\t\t\t" << "{ \"id\": " << node->id() << ", " <<
										"\"parent\": " << ((parent)?parent->id():-1) << ", " <<
										"\"depth\": " << node->depth() << ", " <<
										"\"invitations\": " << node->childCount() << " " <<
										"}" << ((i==vec.size()-1)?"":",") <<
										std::endl;
		}

		m_ostream << "\t\t" << "]" << std::endl;
		m_ostream << "\t}," << std::endl;

		m_ostream << std::endl;

		m_ostream << "\t\"BalancedTree\": {" << std::endl;
		m_ostream << "\t\t" << "\"Customers\": [" << std::endl;

		vec = net.balancedTree().nodeList();

		for( std::size_t i = 0; i < vec.size(); i++ )
		{
			Customer * node = vec[i];
			Customer * parent = node->parent();

			m_ostream << "\t\t\t" << "{ \"id\": " << node->id() << ", " <<
										"\"parent\": " << ((parent)?parent->id():-1) << ", " <<
										"\"score\": " << node->score() << ", " <<
										"\"active\": " << ((node->active())?"true":"false") << ", " <<
										"\"depth\": " << node->depth() << " " <<
										"}" << ((i==vec.size()-1)?"":",") <<
										std::endl;
		}

		m_ostream << "\t\t" << "]" << std::endl;
		m_ostream << "\t" << "}" << std::endl;
		m_ostream << "}" << std::endl;
		m_ostream << std::endl;
	}

}

/* $Id: NetworkWriterJSON.cpp 439 2017-05-04 19:50:36Z tiago.ventura $ */
