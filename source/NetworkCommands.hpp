/*!
	\file NetworkCommands.hpp
	\brief Network Commands Object Interface (Command Design Pattern)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __NETWORKCOMMANDS_HPP__
#define __NETWORKCOMMANDS_HPP__

#include <iostream>

#include "Exception.hpp"
#include "Command.hpp"
#include "DataBaseConnectionSQLite3.hpp"

#include "PropagationRule.hpp"
#include "Network.hpp"
#include "Customer.hpp"
#include "NetworkCollection.hpp"

#include "NetworkEventHistory.hpp"
#include "NetworkEventHistoryRecorder.hpp"

#include "NetworkCollectionReaderDataBase.hpp"
#include "NetworkReaderDataBase.hpp"
#include "NetworkWriterDataBase.hpp"
#include "NetworkEventHistoryWriterDataBase.hpp"

#include "PropagationRuleWriterText.hpp"
#include "NetworkWriterText.hpp"
#include "CustomerWriterText.hpp"
#include "NetworkCollectionWriterText.hpp"

#include "NetworkWriterFactory.hpp"

namespace MLM
{
	class NetworkCommand : public Command
	{
		public:

			NetworkCommand( void ) :
				m_reader( DataBaseConnectionSQLite3::instance() ),
				m_writer( DataBaseConnectionSQLite3::instance() ),
				m_history_writer( DataBaseConnectionSQLite3::instance() ),
				m_history(),
				m_history_recorder( m_history )
				
			{
			}

			virtual ~NetworkCommand( void )
			{
			}

			virtual void execute( void ) = 0;

		protected:

			NetworkReaderDataBase m_reader;
			NetworkWriterDataBase m_writer;
			NetworkEventHistoryWriterDataBase m_history_writer;
			NetworkEventHistory m_history;
			NetworkEventHistoryRecorder m_history_recorder;
	};


	class NetworkListCommand : public NetworkCommand
	{
		public:

			NetworkListCommand( void ) :
				m_collection_writer( std::cout ),
				m_collection_reader( DataBaseConnectionSQLite3::instance() )
			{
			}

			virtual ~NetworkListCommand( void )
			{
			}

			void execute( void )
			{
				m_collection.readFrom( &m_collection_reader );
				m_collection.writeTo( &m_collection_writer );
			}

		private:

			NetworkCollectionWriterText m_collection_writer;
			NetworkCollectionReaderDataBase m_collection_reader;
			NetworkCollection m_collection;
	};
	
	
	class AddNetworkCommand : public NetworkCommand
	{
		public:

			AddNetworkCommand( int net, std::string name, std::string desc, int k ) :
				m_network( net )
			{
				m_network.name( name );
				m_network.description( desc );
				m_network.overflowCoefficient( k );
			}

			virtual ~AddNetworkCommand( void )
			{
			}

			void execute( void )
			{
				try
				{
					m_network.readFrom( &m_reader );
				}
				catch( const Exception & e )
				{
					m_network.writeTo( &m_writer );
				}
			}

		private:

			Network m_network;
	};


	class SetRootCommand : public NetworkCommand
	{
		public:

			SetRootCommand( int net, int cstmr ) :
				m_network( net ),
				m_customer( cstmr )
			{
			}

			virtual ~SetRootCommand( void )
			{

			}

			void execute( void )
			{
				m_network.readFrom( &m_reader );
				m_network.attachEventHandler( m_history_recorder );
				m_network.rootCustomer( m_customer );
				m_network.writeTo( &m_writer );
				m_history.writeTo( &m_history_writer );
			}

		private:

			Network m_network;
			Customer m_customer;
	};


	class AddCustomerCommand : public NetworkCommand
	{
		public:

			AddCustomerCommand( int net, int prnt, int cstmr ) :
				m_network( net ),
				m_parent( prnt ),
				m_customer( cstmr )
			{
			}

			virtual ~AddCustomerCommand( void )
			{
			}

			void execute( void )
			{
				m_network.readFrom( &m_reader );
				m_network.addCustomer( m_parent, m_customer );
				m_network.writeTo( &m_writer );
			}

		private:

			Network m_network;
			Customer m_parent;
			Customer m_customer;
			double m_score;
	};


	class ActivateCustomerCommand : public NetworkCommand
	{
		public:

			ActivateCustomerCommand( int net, int cstmr ) :
				m_network( net ),
				m_customer( cstmr )
			{
			}

			virtual ~ActivateCustomerCommand( void )
			{
			}

			void execute( void )
			{
				m_network.readFrom( &m_reader );
				m_network.customerActivate( m_customer );
				m_network.writeTo( &m_writer );
			}

		private:

			Network m_network;
			Customer m_customer;
	};


	class DeactivateCustomerCommand : public NetworkCommand
	{
		public:

			DeactivateCustomerCommand( int net, int cstmr ) :
				m_network( net ),
				m_customer( cstmr )
			{
			}

			virtual ~DeactivateCustomerCommand( void )
			{
			}

			void execute( void )
			{
				m_network.readFrom( &m_reader );
				m_network.customerDeactivate( m_customer );
				m_network.writeTo( &m_writer );
			}

		private:

			Network m_network;
			Customer m_customer;
	};


	class NetworkDumpCommand : public NetworkCommand
	{
		public:

			NetworkDumpCommand( int net ) :
				m_network( net ),
				m_dot_writer( std::cout )
			{
			}

			virtual ~NetworkDumpCommand( void )
			{
			}

			void execute( void )
			{
				m_network.readFrom( &m_reader );
				m_network.writeTo( &m_writer );
			}

		private:

			Network m_network;
			NetworkWriterDOT m_dot_writer;
	};


	class SetCustomerScoreCommand : public NetworkCommand
	{
		public:

			SetCustomerScoreCommand( int net, int cstmr, double score ) :
				m_network( net ),
				m_customer( cstmr ),
				m_score( score )
			{
			}

			virtual ~SetCustomerScoreCommand( void )
			{
			}

			void execute( void )
			{
				m_network.readFrom( &m_reader );
				m_network.customerSetScore( m_customer, m_score );
				m_network.writeTo( &m_writer );
			}

		private:

			Network m_network;
			Customer m_customer;
			double m_score;
	};


	class AddCustomerScoreCommand : public NetworkCommand
	{
		public:

			AddCustomerScoreCommand( int net, int cstmr, double score ) :
				m_network( net ),
				m_customer( cstmr ),
				m_score( score )
			{
			}

			virtual ~AddCustomerScoreCommand( void )
			{
			}

			void execute( void )
			{
				m_network.readFrom( &m_reader );
				m_network.customerAddScore( m_customer, m_score );
				m_network.writeTo( &m_writer );
			}

		private:

			Network m_network;
			Customer m_customer;
			double m_score;
	};


	class SubtractCustomerScoreCommand : public NetworkCommand
	{
		public:

			SubtractCustomerScoreCommand( int net, int cstmr, double score ) :
				m_network( net ),
				m_customer( cstmr ),
				m_score( score )
			{
			}

			virtual ~SubtractCustomerScoreCommand( void )
			{
			}

			void execute( void )
			{
				m_network.readFrom( &m_reader );
				m_network.customerSubtractScore( m_customer, m_score );
				m_network.writeTo( &m_writer );
			}

		private:

			Network m_network;
			Customer m_customer;
			double m_score;
	};


	class PropagateScoreCommand : public NetworkCommand
	{
		public:

			PropagateScoreCommand( int net, int cstmr, std::string ruleName, double score ) :
				m_network( net ),
				m_customer( cstmr ),
				m_rule( PropagationRuleFactory::rule( ruleName ) ),
				m_score( score )
			{
			}

			virtual ~PropagateScoreCommand( void )
			{
			}

			void execute( void )
			{
				m_network.readFrom( &m_reader );
				m_network.propagateScore( m_customer, m_rule, m_score );
				m_network.writeTo( &m_writer );
			}

		private:

			Network m_network;
			Customer m_customer;
			PropagationRule m_rule;
			double m_score;
	};


	class NetworkInfoCommand : public NetworkCommand
	{
		public:

			NetworkInfoCommand( int net ) :
				m_network( net ),
				m_network_writer( std::cout )
			{
			}

			virtual ~NetworkInfoCommand( void )
			{
			}

			void execute( void )
			{
				m_network.readFrom( &m_reader );
				m_network_writer.fullInfo( true );
				m_network.writeTo( &m_network_writer );
			}

		private:

			Network m_network;
			NetworkWriterText m_network_writer;
	};


	class CustomerInfoCommand : public NetworkCommand
	{
		public:

			CustomerInfoCommand( int net, int cstmr ) :
				m_network( net ),
				m_customer( cstmr ),
				m_customer_writer( std::cout )
			{
			}

			virtual ~CustomerInfoCommand( void )
			{
			}

			void execute( void )
			{
				m_network.readFrom( &m_reader );

				Customer * cstmr = m_network.searchCustomer( m_customer );

				if(!cstmr)
					throwex( RunTimeException( "Customer does not exists in the Network." ) );

				cstmr->writeTo( &m_customer_writer );
			}

		private:

			Network m_network;
			Customer m_customer;
			CustomerWriterText m_customer_writer;
	};


	class PropagationRuleInfoCommand : public NetworkCommand
	{
		public:

			PropagationRuleInfoCommand( std::string ruleName ) :
				m_rule( PropagationRuleFactory::rule( ruleName ) ),
				m_rule_writer( std::cout )
			{
			}

			virtual ~PropagationRuleInfoCommand( void )
			{
			}

			void execute( void )
			{
				m_rule.writeTo( &m_rule_writer );
			}

		private:

			PropagationRule m_rule;
			PropagationRuleWriterText m_rule_writer;
	};

}

#endif

/* $Id: NetworkCommands.hpp 441 2017-05-05 01:34:20Z tiago.ventura $ */
