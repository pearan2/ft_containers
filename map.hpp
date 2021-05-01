/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 04:20:32 by honlee            #+#    #+#             */
/*   Updated: 2021/05/01 10:10:06 by honlee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "BST.hpp"
# include "utils.hpp"
# include "map_iterator.hpp"
# include <algorithm>
# include <cstddef>
# include <iostream>
# include <limits>

namespace ft
{
	template < class TK, class TV, class Compare = ft::less<TK>, class Alloc = std::allocator<pair<const TK,TV> > >
	class map
	{
		private :
			node<TK, TV, Compare>	*root;
			unsigned int				noe;
			saver<TK, TV, Compare>  *sv;

			void	setSV()
			{
				sv->root = root;
			}

		public	:
			typedef TK key_type;
			typedef TV mapped_type;
			typedef pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			typedef value_type &reference;
			typedef const value_type &const_reference;
			typedef value_type *pointer;
			typedef const value_type *const_pointer;
			typedef ptrdiff_t difference_type;
			typedef size_t size_type;
			typedef mapIterator<TK, TV, Compare> iterator;
			typedef mapConstIterator<TK, TV, Compare> const_iterator;
			typedef mapReverseIterator<TK, TV, Compare> reverse_iterator;
			typedef mapReverseConstIterator<TK, TV, Compare> const_reverse_iterator;

			typedef Alloc allocator_type;
			
			//c plusplus 홈페이지에 나와있는 그대로 가따붙임 pair 를 직접 비교해주는 클레스.
			class value_compare
			{
				private :
					Compare comp;
					value_compare (Compare c) : comp(c){}
				public	:
					typedef bool result_type;
  					typedef value_type first_argument_type;
  					typedef value_type second_argument_type;

					value_compare(){}

					value_compare(const value_compare& origin) : comp(origin.comp) {}

					~value_compare(){}

					value_compare& operator=(const value_compare& origin)
					{
						comp = origin.comp;
						return (*this);
					}

					bool operator() (const value_type& x, const value_type& y) const
  					{
    					return comp(x.first, y.first);
					}
			};

			//////////////////////////////////////////////////////////////////
			//						constructor start						//
			//////////////////////////////////////////////////////////////////

			//default
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : root(NULL), noe(0)
			{				
				(void)comp;
				(void)alloc;
				sv = new saver<TK, TV, Compare>();
			}

			//range
			template <class InputIterator>
  			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : root(NULL), noe(0)
			{				
				(void)comp;
				(void)alloc;
				sv = new saver<TK, TV, Compare>();
				insert(first, last);			
			}
			
			//copy
			map (const map& x) : root(NULL), noe(0) 
			{
				//std::cout << "copy constrcutor called" << std::endl;
				this->root = new node<TK, TV, Compare>(* x.root);
				this->noe = x.noe;
				sv = new saver<TK, TV, Compare>();
				setSV();
			}

			map<TK, TV, Compare, Alloc>& operator= (const map& x)
			{
				this->root->deleteAll(this->root); // 가지고 있던 모든 것 파괴
				this->root = new node<TK, TV, Compare>(* x.root);
				this->noe = x.noe;
				setSV();
				return (*this);
			}

			~map()
			{
				if (noe > 0)
					this->root->deleteAll(this->root);
				delete (sv);
			}

			//////////////////////////////////////////////////////////////////
			//						constructor end							//
			//////////////////////////////////////////////////////////////////	

			//////////////////////////////////////////////////////////////////
			//						Iterators start							//
			//////////////////////////////////////////////////////////////////

			iterator begin()
			{
				return (iterator(root->getLeftest(root), sv));
			}

			const_iterator begin() const
			{
				return (const_iterator(root->getLeftest(root), sv));
			}

			iterator end()
			{
				return (iterator(NULL, sv));
			}

			const_iterator end() const
			{
				return (const_iterator(NULL, sv));
			}

			reverse_iterator rbegin()
			{
				return (reverse_iterator(root->getRightest(root), sv));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(root->getRightest(root), sv));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(NULL, sv));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(NULL, sv));
			}

			//////////////////////////////////////////////////////////////////
			//						Iterators end							//
			//////////////////////////////////////////////////////////////////

			//////////////////////////////////////////////////////////////////
			//						Capacity start							//
			//////////////////////////////////////////////////////////////////

			bool empty() const
			{
				return (this->noe == 0);
			}

			size_type size() const
			{
				return (this->noe);
			}

			size_type max_size() const
			{
				return (Alloc().max_size());
			}

			//////////////////////////////////////////////////////////////////
			//						Capacity end							//
			//////////////////////////////////////////////////////////////////

			//////////////////////////////////////////////////////////////////
			//						Element access start					//
			//////////////////////////////////////////////////////////////////
			
			//value 의 레퍼런스를 내보낸다.
			mapped_type& operator[] (const key_type& key)
			{
				node<TK, TV, Compare>* ret;

				if (noe == 0)
				{
					noe++;
					root = new node<TK, TV, Compare>(key);
					setSV();
					return (root->ip.second);
				}
				else
				{
					if ((ret = root->find(root, key)) != NULL) // 찾았다 (존재한다.)
					{
						return (ret->ip.second);
					}
					else
					{
						noe++;
						return (root->mergeInsert(root, key)->ip.second);
					}
				}
			}

			//////////////////////////////////////////////////////////////////
			//						Element access end						//
			//////////////////////////////////////////////////////////////////

			//////////////////////////////////////////////////////////////////
			//						Modifiers start							//
			//////////////////////////////////////////////////////////////////

			pair<iterator,bool> insert (const value_type& val)
			{
				node<TK, TV, Compare>* ret;

				if (noe == 0)
				{
					noe++;
					root = new node<TK, TV, Compare>(val.first, val.second);
					setSV();
					return (pair<iterator, bool>(iterator(root, sv), true));
				}
				else
				{
					if ((ret = root->find(root, val.first)) != NULL) // 찾았다 (존재한다.)
					{
						return (pair<iterator, bool>(iterator(ret, sv), false));
					}
					else
					{
						noe++;
						ret = root->mergeInsert(root, val.first, val.second);
						return (pair<iterator, bool>(iterator(ret, sv), true));
					}
				}
			}

			iterator insert (iterator position, const value_type& val)
			{
				(void)position;
				return (insert(val).first);
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				for (InputIterator iter = first; iter != last; iter++)
					insert(pair<const TK, TV>(iter->first, iter->second));
			}

			void erase (iterator position)
			{
				erase(position->first);
			}

			size_type erase (const key_type& k)
			{
				if (noe == 0)
					return (0);
				else
				{
					if (root->find(root, k) != NULL)
					{
						root->deleteNode(&root, root, k);
						setSV();
						noe--;
						if (noe == 0)
						{
							root = NULL;
							setSV();
						}
						return (1);
					}
					else
						return (0);
				}
			}

			void erase (iterator first, iterator last)
			{
				iterator iter = first;
				iterator iter_next;
				for (; iter != last;)
				{
					iter_next = iter;
					iter_next++;
					erase(iter);
					iter = iter_next;
					if (iter == last)
						break ;
				}
			}

			void swap (map& x)
			{
				node<TK, TV, Compare> *temp = this->root;
				this->root = x.root;
				x.root = temp;
				
				unsigned int temp_size = this->noe;
				this->noe = x.noe;
				x.noe = temp_size;
			}

			void clear()
			{
				if (noe == 0)
					return ;
				noe = 0;
				root->deleteAll(root);
				root = NULL;
			}

			//////////////////////////////////////////////////////////////////
			//						Modifiers end							//
			//////////////////////////////////////////////////////////////////

			//////////////////////////////////////////////////////////////////
			//						Observers start							//
			//////////////////////////////////////////////////////////////////
			key_compare key_comp() const
			{
				return (Compare());
			}

			value_compare value_comp() const
			{
				return (value_compare());
			}

			//////////////////////////////////////////////////////////////////
			//						Observers end							//
			//////////////////////////////////////////////////////////////////

			//////////////////////////////////////////////////////////////////
			//						Operations start						//
			//////////////////////////////////////////////////////////////////

			iterator find (const key_type& k)
			{
				if (noe == 0)
					return (iterator(NULL, sv));
				return (iterator(root->find(root, k), sv));
			}

			const_iterator find (const key_type& k) const
			{
				if (noe == 0)
					return (const_iterator(NULL, sv));
				return (const_iterator( root->find(root, k), sv ) );
			}

			size_type count (const key_type& k) const
			{
				if (noe == 0)
					return (0);
				if (root->find(root, k) != NULL)
					return (1);
				else
					return (0);
			}

			iterator lower_bound (const key_type& k)
			{
				if (noe == 0)
					return (iterator(NULL, sv));
				else
					return (iterator(root->getLowerBound(root, k), sv));
			}

			const_iterator lower_bound (const key_type& k) const
			{
				if (noe == 0)
					return (const_iterator(NULL, sv));
				else
					return (const_iterator(root->getLowerBound(root, k), sv));
			}

			iterator upper_bound (const key_type& k)
			{
				if (noe == 0)
					return (iterator(NULL, sv));
				else
					return (iterator(root->getUpperBound(root, k), sv));
			}

			const_iterator upper_bound (const key_type& k) const
			{
				if (noe == 0)
					return (const_iterator(NULL, sv));
				else
					return (const_iterator(root->getUpperBound(root, k), sv));
			}

			pair<iterator,iterator>             equal_range (const key_type& k)
			{
				return (pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
			}

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				return (pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
			}

			//////////////////////////////////////////////////////////////////
			//						Operations end							//
			//////////////////////////////////////////////////////////////////	
	};
}

#endif