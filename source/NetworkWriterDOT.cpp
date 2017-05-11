/*!
	\file NetworkWriterDOT.cpp
	\brief Network Writer Object Implementation (GraphViz/DOT Format)
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
#include "NetworkWriterDOT.hpp"


namespace MLM
{

	NetworkWriterDOT::NetworkWriterDOT( const std::string& filename ) :
		m_ofstream( filename.c_str() ),
		m_ostream( m_ofstream )
	{
		if( !m_ofstream.is_open() )
			throwex( FileIOException( "Error openning file for write." ) );
	}


	NetworkWriterDOT::NetworkWriterDOT( std::ostream& os ) :
		m_ofstream(),
		m_ostream( os )
	{
	}


	NetworkWriterDOT::~NetworkWriterDOT( void )
	{
	}


	void NetworkWriterDOT::writeObject( const Serializable * s )
	{
		const Network & net = dynamic_cast<const Network&>( *s );

		std::vector<Customer*> vec;

		m_ostream << "digraph MLM_NETWORK {" << std::endl;

		m_ostream << std::endl;

		m_ostream << "\t" << "subgraph cluster_00 {" << std::endl;

		m_ostream << std::endl;

		m_ostream << "\t\t" << "nodesep = 0.1;" << std::endl;
		m_ostream << "\t\t" << "ranksep = 0.5;" << std::endl;
		m_ostream << "\t\t" << "node [style=filled, shape=circle, fillcolor=lightgrey, width=0.27, fixedsize=true, fontsize=8];" << std::endl;
		m_ostream << "\t\t" << "edge [arrowsize=0.5];" << std::endl;
		m_ostream << "\t\t" << "label = \"ARVORE DE INDICACOES\";" << std::endl;

		m_ostream << std::endl;

		vec = net.invitationsTree().nodeList();

		for( std::size_t i = 0; i < vec.size(); i++ )
			m_ostream << "\t\t" << "I" << vec[i]->id() << " [label=\"" << vec[i]->id() << "\", " <<
													"xlabel=\"\", " <<
													"fillcolor=\"" << ((vec[i]->active())?"lightgrey":"grey") << "\"" <<
													"];" << std::endl;

		for( std::size_t i = 0; i < vec.size(); i++ )
			if( vec[i]->invitationParent() >= 0 )
				m_ostream << "\t\t" << "I" << vec[i]->invitationParent() << "-> I" << vec[i]->id() << ";" << std::endl;

		m_ostream << "	}" << std::endl;

		m_ostream << std::endl;

		m_ostream << "\t"<< "subgraph cluster_01 {" << std::endl;

		m_ostream << std::endl;

		m_ostream << "\t\t" << "nodesep = 0.1;" << std::endl;
		m_ostream << "\t\t" << "ranksep = 0.5;" << std::endl;
		m_ostream << "\t\t" << "node [style=filled, shape=circle, fillcolor=lightgrey, width=0.27, fixedsize=true, fontsize=8];" << std::endl;
		m_ostream << "\t\t" << "edge [arrowsize=0.5];" << std::endl;
		m_ostream << "\t\t" << "label = \"ARVORE BALANCEADA\";" << std::endl;

		m_ostream << std::endl;

		vec = net.balancedTree().nodeList();

		for( std::size_t i = 0; i < vec.size(); i++ )
				m_ostream << "\t\t" << "B" << vec[i]->id() <<   " [label=\"" << vec[i]->id() << "\", " <<
																"xlabel=\"" << vec[i]->score() << "\", " <<
																"fillcolor=\"" << ((vec[i]->active())?"lightgrey":"grey") << "\"" <<
																"];" << std::endl;

		for( std::size_t i = 0; i < vec.size(); i++ )
			if( vec[i]->overflowParent() >= 0 )
				m_ostream << "\t\t" << "B" << vec[i]->overflowParent() << "-> B" << vec[i]->id() << ";" << std::endl;

		m_ostream << "	}" << std::endl;

		m_ostream << std::endl;

		m_ostream << "}" << std::endl;

		m_ostream << std::endl;

		m_ostream << "# end-of-file #" << std::endl;
	}
}

/* $Id: NetworkWriterDOT.cpp 383 2017-04-06 14:00:13Z tiago.ventura $ */
