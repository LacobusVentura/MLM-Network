/*!
	\file TreeNode.hpp
	\brief k-ary Tree Node Object Interface/Implementation (aka: Left-child right-sibling Binary Tree Node)
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __TREENODE_HPP__
#define __TREENODE_HPP__

#include <cstdio>
#include <vector>

namespace MLM
{

	template <class T>
	class TreeNode
	{
		public:

			TreeNode( void ) :
				m_parent(NULL),
				m_first_child(NULL),
				m_last_child(NULL),
				m_previous_sibling(NULL),
				m_next_sibling(NULL)
			{
			}


			TreeNode( const TreeNode &obj ) :
				m_parent(obj.m_parent),
				m_first_child(obj.m_first_child),
				m_last_child(obj.m_last_child),
				m_previous_sibling(obj.m_previous_sibling),
				m_next_sibling(obj.m_next_sibling)
			{
			}


			virtual ~TreeNode( void )
			{
			}


			TreeNode& operator=( const TreeNode& obj )
			{
				m_parent = obj.m_parent;
				m_first_child = obj.m_first_child;
				m_last_child = obj.m_last_child;
				m_previous_sibling = obj.m_previous_sibling;
				m_next_sibling = obj.m_next_sibling;

				return *this;
			}


			T * parent( void ) const
			{
				return m_parent;
			}


			T * nextSibling( void ) const
			{
				return m_next_sibling;
			}


			T * prevSibling( void ) const
			{
				return m_previous_sibling;
			}


			T * firstChild( void ) const
			{
				return m_first_child;
			}


			T * lastChild( void ) const
			{
				return m_last_child;
			}


			int childCount( void ) const
			{
				return childCount( crefDerived() );
			}


			int siblingCount( void ) const
			{
				return ((m_parent) ? m_parent->childCount() - 1 : 0);
			}


			int descendantCount( void ) const
			{
				return nodeCount( cptrDerived() ) - 1;
			}


			int maxDepth( void ) const
			{
				return maxDepth( crefDerived() );
			}


			int depthNodeCount( int depth ) const
			{
				return depthNodeCount( cptrDerived(), depth );
			}


			T * search( const T& node ) const
			{
				return search( crefDerived(), node );
			}


			bool isLeaf( void ) const
			{
				return (!m_first_child && !m_last_child);
			}


			bool isRoot( void ) const
			{
				return (!m_parent);
			}


			bool hasSibling( void ) const
			{
				return (m_next_sibling || m_previous_sibling);
			}


			bool isDescendant( const T * node ) const
			{
				T * pwalk = node;

				while( pwalk )
				{
					pwalk = pwalk->m_parent;

					if( pwalk == this )
						return true;
				}

				return false;
			}


			bool isAncestral( const T * node ) const
			{
				T * pwalk = this;

				while( pwalk )
				{
					pwalk = pwalk->m_parent;

					if( pwalk == node )
						return true;
				}

				return false;
			}


			T & addChild( const T& node )
			{
				T * child = new T( node );

				child->m_parent = ptrDerived();

				if( m_first_child && m_last_child )
				{
					m_last_child->m_next_sibling = child;
					child->m_previous_sibling = m_last_child;
					m_last_child = child;
				}
				else
				{
					m_last_child = child;
					m_first_child = child;
				}

				return *child;
			}


			int depth( void ) const
			{
				int depth = 0;
				T * pwalk = m_parent;

				while( pwalk )
				{
					depth++;
					pwalk = pwalk->m_parent;
				}

				return depth;
			}


			std::vector<T*> siblingList( void ) const
			{
				std::vector<T*> vec;
				TreeNode * pwalk = NULL;

				if(!m_parent)
					return vec;

				pwalk = m_parent->m_first_child;

				while( pwalk )
				{
					if(pwalk != this)
						vec.push_back(pwalk);

					pwalk = pwalk->m_next_sibling;
				}

				return vec;
			}


			std::vector<T*> descendantList( void ) const
			{
				std::vector<T*> vec;
				descendantList( vec, crefDerived() );
				return vec;
			}


			std::vector<T*> depthNodeList( int depth ) const
			{
				std::vector<T*> vec;
				depthNodeList( vec, crefDerived(), this->depth() + depth );
				return vec;
			}


			std::vector<T*> childList( void ) const
			{
				std::vector<T*> vec;
				TreeNode * pwalk = m_first_child;

				while( pwalk )
				{
					vec.push_back(pwalk);
					pwalk = pwalk->m_next_sibling;
				}

				return vec;
			}


			std::vector<T*> ancestralList( void ) const
			{
				std::vector<T*> vec;
				T * pwalk = m_parent;

				while( pwalk )
				{
					vec.push_back(pwalk);
					pwalk = pwalk->m_parent;
				}

				return vec;
			}


			static void removeLeafNode( T * node )
			{
				if( !node )
					return;

				if(!node->isLeaf())
					return;

				if( node->m_previous_sibling && node->m_next_sibling )
				{
					node->m_previous_sibling->m_next_sibling = node->m_next_sibling;
					node->m_next_sibling->m_previous_sibling = node->m_previous_sibling;
				}
				else if( !node->m_previous_sibling && node->m_next_sibling )
				{
					node->m_parent->m_first_child = node->m_next_sibling;
					node->m_next_sibling->m_previous_sibling = NULL;
				}
				else if( node->m_previous_sibling && !node->m_next_sibling )
				{
					node->m_parent->m_last_child = node->m_previous_sibling;
					node->m_previous_sibling->m_next_sibling = NULL;
				}
				else
				{
					node->m_parent->m_first_child = NULL;
					node->m_parent->m_last_child = NULL;
				}

				delete node;
			}


		private:


			T * ptrDerived( void ) { return static_cast<T*>(this); }
			T & refDerived( void ) { return static_cast<T&>(*this); }
			const T * cptrDerived( void ) const { return static_cast<const T*>(this); }
			const T & crefDerived( void ) const { return static_cast<const T&>(*this); }


			int childCount( const TreeNode & node ) const
			{
				TreeNode * pwalk = node.m_first_child;
				int count = 0;

				while( pwalk )
				{
					count++;
					pwalk = pwalk->m_next_sibling;
				}

				return count;
			}


			int nodeCount( const TreeNode * node ) const
			{
				TreeNode * pwalk = NULL;
				int count = 1;

				if( !node )
					return 0;

				pwalk = node->m_first_child;

				while( pwalk )
				{
					count += nodeCount( pwalk );
					pwalk = pwalk->m_next_sibling;
				}

				return count;
			}


			int depthNodeCount( TreeNode * node, int depth ) const
			{
				TreeNode * pwalk = NULL;
				int count = 0;

				if( !node )
					return 0;

				if( node->depth() == depth )
					count = 1;

				pwalk = node->m_first_child;

				while( pwalk )
				{
					count += depthNodeCount( pwalk, depth );

					pwalk = pwalk->m_next_sibling;
				}

				return count;
			}


			T * search( const T & root, const T & data ) const
			{
				T * pwalk = NULL;
				T * node = NULL;

				if( root == data )
					return const_cast<T*>(&root);

				pwalk = root.m_first_child;

				while( pwalk )
				{
					node = search( *pwalk, data );

					if( node )
						return node;

					pwalk = pwalk->m_next_sibling;
				}

				return NULL;
			}


			int maxDepth( const T & root ) const
			{
				T * pwalk = root.m_first_child;
				int depth = 0;
				int max = 0;

				while( pwalk )
				{
					depth = maxDepth( *pwalk );

					if( depth > max )
						max = depth;

					pwalk = pwalk->m_next_sibling;
				}

				return max + 1;
			}


			void depthNodeList( std::vector<T*> & vec, const T & root, int depth ) const
			{
				T * pwalk = root.m_first_child;

				if( root.depth() == depth )
					vec.push_back( const_cast<T*>(&root) );

				while( pwalk )
				{
					depthNodeList( vec, *pwalk, depth );
					pwalk = pwalk->m_next_sibling;
				}
			}


			void descendantList( std::vector<T*> & vec, const T & root ) const
			{
				T * pwalk = NULL;

				pwalk = root.m_first_child;

				while( pwalk )
				{
		 			vec.push_back( pwalk );
					descendantList( vec, *pwalk );
					pwalk = pwalk->m_next_sibling;
				}
			}


		private:

			T * m_parent;
			T * m_first_child;
			T * m_last_child;
			T * m_previous_sibling;
			T * m_next_sibling;
	};
}

#endif

/* $Id: TreeNode.hpp 361 2017-03-29 20:15:32Z tiago.ventura $ */
