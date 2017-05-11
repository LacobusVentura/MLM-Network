/*!
	\file MLM.hpp
	\brief Multi Level Marketing Generic Framework Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)

	\mainpage
	\image html maintree.png
*/

#ifndef __MLM_HPP__
#define __MLM_HPP__

// Debugger/Logging
#include "Exception.hpp"
#include "Logger.hpp"
#include "DebugLogger.hpp"

// Searialization Interface (Serializable Pattern)
#include "Reader.hpp"
#include "Writer.hpp"
#include "Serializable.hpp"

// Event Mechanism (Visitor Pattern)
#include "Event.hpp"
#include "EventDispatcher.hpp"
#include "GlobalEventHandler.hpp"

// Tree
#include "Tree.hpp"
#include "TreeNode.hpp"

// Entities
#include "Network.hpp"
#include "Customer.hpp"
#include "PropagationRule.hpp"
#include "PropagationStep.hpp"
#include "NetworkCollection.hpp"

// Searializable Pattern Writer Data Base
#include "CustomerWriterDataBase.hpp"
#include "NetworkWriterDataBase.hpp"
#include "NetworkWriterDOT.hpp"
#include "NetworkWriterText.hpp"
#include "NetworkWriterJSON.hpp"
#include "PropagationRuleWriterText.hpp"
#include "CustomerWriterText.hpp"
#include "NetworkCollectionWriterText.hpp"

// Searializable Pattern Reader Data Base
#include "CustomerReaderDataBase.hpp"
#include "NetworkReaderDataBase.hpp"
#include "PropagationRuleReaderDataBase.hpp"
#include "NetworkCollectionReaderDataBase.hpp"

// Network Events
#include "NetworkEvents.hpp"
#include "NetworkEventLogger.hpp"

// Database Interface (Abstract Classes)
#include "DataBaseConnection.hpp"
#include "DataBaseStatement.hpp"
#include "DataBaseColumn.hpp"

// Database Implementations (SQLite3)
#include "DataBaseConnectionSQLite3.hpp"
#include "DataBaseStatementSQLite3.hpp"
#include "DataBaseColumnSQLite3.hpp"

// Factories
#include "PropagationRuleFactory.hpp"
#include "NetworkCommandFactory.hpp"
#include "NetworkWriterFactory.hpp"

// Command Interface (Abstract Classes)
#include "Command.hpp"

// Application Interface (Abstract Classes)
#include "Application.hpp"
#include "CommandLineApplication.hpp"
#include "MLMCommandLineApplication.hpp"

// Network Commands
#include "NetworkCommands.hpp"


#endif

/* $Id: MLM.hpp 436 2017-05-03 22:45:35Z tiago.ventura $ */
