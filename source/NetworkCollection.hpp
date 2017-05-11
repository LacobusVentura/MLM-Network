/*!
	\file NetworkCollection.hpp
	\brief Network Collection Object Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __NETWORKCOLLECTION_HPP__
#define __NETWORKCOLLECTION_HPP__

#include <vector>

#include "Serializable.hpp"
#include "Network.hpp"

namespace MLM
{
	class NetworkCollection : public Serializable
	{
		public:

			NetworkCollection( void );
			virtual ~NetworkCollection( void );
			
			int count( void ) const;
			const Network & network( int idx ) const;
			void addNetwork( Network & net );
			void clear( void );

		private:

			std::vector<Network> m_collection;
			
	};
}

#endif

/* $Id: NetworkCollection.hpp 438 2017-05-04 17:19:20Z tiago.ventura $ */
