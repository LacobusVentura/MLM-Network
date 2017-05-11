/*!
	\file Serializable.hpp
	\brief Serializable Object Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __SERIALIZABLE_HPP__
#define __SERIALIZABLE_HPP__

#include "Reader.hpp"
#include "Writer.hpp"

namespace MLM
{
	class Serializable
	{
		public:


			Serializable( void ) :
				m_modified(true)
			{
			}


			virtual ~Serializable( void )
			{
			}


			bool isModified( void ) const
			{
				return m_modified;
			}


			void setModified( void ) const
			{
				m_modified = true;
			}


			void resetModified( void ) const
			{
				m_modified = false;
			}


			void readFrom( Reader * rd )
			{
				rd->readObject( this );
			}


			void writeTo( Writer * wr ) const
			{
				wr->writeObject( this );
			}


		private:

			mutable bool m_modified;

	};
}

#endif

/* $Id: Serializable.hpp 367 2017-03-30 12:00:17Z tiago.ventura $ */
