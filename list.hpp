/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:44:46 by honlee            #+#    #+#             */
/*   Updated: 2021/04/22 00:33:46 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

#include <algorithm>
#include <cstddef>
#include <iostream>
#include "template_util.hpp"

namespace ft
{
	template <typename T>
	class node
	{
		private :
			node*	prev;
			node*	next;
			T		value;

		public	:
			//canonical form start
			node() : prev(NULL), next(NULL)
			{
				
			}
			node(node* prev, node* next) : prev(prev), next(next)
			{

			}
			node(node* prev, node* next, const T& value) : prev(prev), next(next), value(value)
			{
				
			}
			node(node const &origin) : prev(origin.prev), next(origin.next), value(origin.value)
			{
				
			}
			node &operator=(node const &origin)
			{
				this->prev = origin.prev;
				this->next = origin.next;
				this->valu = origin.value;
				return (*this);
			}
			~node()
			{
			}
			//canonical form end

			//getter
			node*	getPrev(void)
			{
				return (this->prev);
			}

			node*	getNext(void)
			{
				return (this->next);
			}

			const T&getValue(void) const
			{
				return (this->value);
			}

			T&		getValue(void)
			{
				return (this->value);
			}

			//setter
			void	setNext(node *next)
			{
				this->next = next;
			}
			void	setPrev(node *prev)
			{
				this->prev = prev;
			}
			void	setValue(const T& value)
			{
				this->value = value;
			}

			//new with value
			node*	clone_with_value(void)
			{
				return (new node(NULL, NULL, this->value));
			}
	};

	template <class T, class Alloc = std::allocator<T> >
	class list
	{
		private :
			node<T>			*head;
			node<T>			*tail;
			size_t			number_of_node;

		public :
			//member types start
			typedef T value_type;
			typedef T &reference;
			typedef const T &const_reference;
			typedef T *pointer;
			typedef const T *const_pointer;
			//typedef ListIterator<T> iterator;
			//typedef ListIterator<const T> const_iterator;
			//typedef ReverseIterator<iterator> reverse_iterator;
			//typedef ReverseIterator<const_iterator> const_reverse_iterator;
			typedef std::ptrdiff_t difference_type;
			typedef size_t size_type;
			//rebind
			typedef typename Alloc::template rebind< node<T> >::other Alnod;
			//rebind end
			//member types end
			
			//////////////////////////////////////////////////////////////////
			//						constructor start						//
			//////////////////////////////////////////////////////////////////
			//default
			explicit list (const Alloc& alloc = Alloc()) : head(NULL), tail(NULL), number_of_node(0)
			{
				std::cout << "default constructor called" << std::endl;
			}
			
			//fill
			explicit list (size_type n, const value_type& val = value_type(), const Alloc& alloc = Alloc()) : head(NULL), tail(NULL), number_of_node(0)
			{
				std::cout << "fill constructor called" << std::endl;
			}

			//range
			template <class InputIterator, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type>
  			list (InputIterator first, InputIterator last, const Alloc& alloc = Alloc()) : head(NULL), tail(NULL), number_of_node(0)
			{
				std::cout << "range constructor called" << std::endl;
			}

			//copy
			list (const list& origin) : head(NULL), tail(NULL), number_of_node(0)
			{
				std::cout << "copy constructor called" << std::endl;
			}
			//////////////////////////////////////////////////////////////////
			//						constructor end							//
			//////////////////////////////////////////////////////////////////


			//////////////////////////////////////////////////////////////////
			//						Modifiers start							//
			//////////////////////////////////////////////////////////////////
			void push_back (const value_type& val)
			{
				Alnod alloc;

				node<T> node_stack(NULL, NULL, val);
				node<T> * node_tmp = alloc.allocate(1);
				alloc.construct(node_tmp, node_stack);

				if (this->number_of_node == 0)
				{
					this->head = node_tmp;
					this->tail = node_tmp;
				}
				else
				{
					this->tail->setNext(node_tmp);
					node_tmp->setPrev(this->tail);
					this->tail = node_tmp;
				}
				this->number_of_node++;
			}
			//////////////////////////////////////////////////////////////////
			//						Modifiers end							//
			//////////////////////////////////////////////////////////////////

			//////////////////////////////////////////////////////////////////
			//						Element access start					//
			//////////////////////////////////////////////////////////////////
			reference front()
			{
				return (head->getValue());
			}

			const_reference front() const
			{
				return (head->getValue());
			}

			reference back()
			{
				return (tail->getValue());
			}

			const_reference back() const
			{
				return (tail->getValue());
			}
			//////////////////////////////////////////////////////////////////
			//						Element access end						//
			//////////////////////////////////////////////////////////////////
	};
}

#endif