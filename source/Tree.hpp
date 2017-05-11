/*!
	\file Tree.hpp
	\brief k-ary Tree Object Interface/Implementation (aka: Left-child right-sibling Binary Tree)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __TREE_HPP__
#define __TREE_HPP__

#include <vector>

#include "TreeNode.hpp"

namespace MLM
{
	template <class T>
	class Tree
	{
		public:

			Tree( void ) :
				m_root(NULL)
			{
			}


			virtual ~Tree( void )
			{
				destroy(m_root);
			}


			void clear( void )
			{
				destroy(m_root);
				m_root = NULL;
			}


			T * root( void ) const
			{
				return m_root;
			}


			T & root( const T& node )
			{
				destroy(m_root);
				m_root = new T( node );
				return *m_root;
			}


			int nodeCount( void ) const
			{
				if(!m_root)
					return 0;

				return m_root->descendantCount() + 1;
			}


			T * search( const T& node ) const
			{
				if(!m_root)
					return NULL;

				return m_root->search( node );
			}


			int maxDepth( void ) const
			{
				if(!m_root)
					return 0;

				return m_root->maxDepth();
			}


			int depthNodeCount( int depth ) const
			{
				if(!m_root)
					return 0;

				return m_root->depthNodeCount( depth );
			}


			std::vector<T*> nodeList( void ) const
			{
				std::vector<T*> vec;

				if(!m_root)
					return vec;

				vec = m_root->descendantList();
				vec.insert( vec.begin(), m_root );

				return vec;
			}


			std::vector<T*> depthNodeList( int depth ) const
			{
				std::vector<T*> vec;

				if(!m_root)
					return vec;

				return m_root->depthNodeList( depth );
			}


		private:

			Tree( const Tree &obj ) {}
			Tree& operator=( const Tree& obj ) {}

			void destroy( T * root )
			{
				T * pwalk = NULL;
				T * aux = NULL;

				if(!root)
					return;

				pwalk = root->firstChild();

				while( pwalk )
				{
					aux = pwalk->nextSibling();
					destroy( pwalk );
					pwalk = aux;
				}

				delete root;
			}

		private:

			T * m_root;

	};

}

#endif

/* $Id: Tree.hpp 366 2017-03-30 00:42:37Z tiago.ventura $ */
