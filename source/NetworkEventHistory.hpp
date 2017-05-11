/*!
	\file NetworkEventHistory.hpp
	\brief Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __NETWORKEVENTHISTORY_HPP__
#define __NETWORKEVENTHISTORY_HPP__

#include <vector>

#include "Serializable.hpp"
#include "NetworkEvents.hpp"

namespace MLM
{
	class NetworkEventHistory : public Serializable
	{
		public:

			NetworkEventHistory( void );
			virtual ~NetworkEventHistory( void );

			void addEvent( NetworkEvent * evnt );
			void reset( void );
			int count( void ) const;

			std::vector<NetworkEvent*> events( void ) const;

		private:
		
			NetworkEventHistory( const NetworkEventHistory &obj );
			NetworkEventHistory& operator=( const NetworkEventHistory& obj );

			void destroy( void );

		private:

			std::vector<NetworkEvent*> m_events;
	};
}

#endif

/* $Id: NetworkEventHistory.hpp 443 2017-05-05 01:35:27Z tiago.ventura $ */
