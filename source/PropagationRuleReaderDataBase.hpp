/*!
	\file PropagationRuleReaderDataBase.hpp
	\brief Propagation Rule Reader Object Interface (DataBase Serialization)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __PROPAGATIONRULEREADERDATABASE_HPP__
#define __PROPAGATIONRULEREADERDATABASE_HPP__


#include "Exception.hpp"
#include "Serializable.hpp"
#include "DataBaseConnection.hpp"
#include "PropagationRule.hpp"

namespace MLM
{

	class PropagationRuleReaderDataBase : public Reader
	{

		public:

			PropagationRuleReaderDataBase( DataBaseConnection& conn );
			virtual ~PropagationRuleReaderDataBase( void );

			void readObject( Serializable * s );

		private:

			DataBaseConnection & m_conn;
	};

}

#endif

/* $Id: PropagationRuleReaderDataBase.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
