/*!
	\file NetworkCollectionReaderDataBase.cpp
	\brief Network Collection Reader Object Implementation (DataBase)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include "DebugLogger.hpp"
#include "Exception.hpp"
#include "Serializable.hpp"
#include "Network.hpp"
#include "NetworkCollection.hpp"
#include "NetworkReaderDataBase.hpp"
#include "DataBaseStatement.hpp"
#include "DataBaseColumn.hpp"

#include "NetworkCollectionReaderDataBase.hpp"

namespace MLM
{

	NetworkCollectionReaderDataBase::NetworkCollectionReaderDataBase( DataBaseConnection & conn ) :
		m_conn( conn )
	{
	}


	NetworkCollectionReaderDataBase::~NetworkCollectionReaderDataBase( void )
	{
	}


	void NetworkCollectionReaderDataBase::readObject( Serializable * s )
	{
		NetworkCollection & collection = dynamic_cast<NetworkCollection&>(*s);
		NetworkReaderDataBase netrd( m_conn );
		
		DataBaseStatement * stmnt = m_conn.prepare( "SELECT id FROM tb_network ORDER BY id;" );

		while( stmnt->fetch() )
		{
			Network net( stmnt->getIntColumn( "id" ) );
   			net.readFrom( &netrd );
   			
			collection.addNetwork( net );
		}

		delete stmnt;
	}

}

/* $Id: NetworkCollectionReaderDataBase.cpp 438 2017-05-04 17:19:20Z tiago.ventura $ */
