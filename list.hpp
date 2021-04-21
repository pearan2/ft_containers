/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:44:46 by honlee            #+#    #+#             */
/*   Updated: 2021/04/21 23:39:19 by honlee           ###   ########.fr       */
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
			node(node* prev, node* next, T& value) : prev(prev), next(next), value(value)
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

			T		getValue(void)
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
			explicit list (const Alloc& alloc = Alloc())
			{
				std::cout << "default constructor called" << std::endl;
			}
			
			//fill
			explicit list (size_type n, const value_type& val = value_type(), const Alloc& alloc = Alloc())
			{
				std::cout << "fill constructor called" << std::endl;
			}

			//range
			template <class InputIterator, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type>
  			list (InputIterator first, InputIterator last, const Alloc& alloc = Alloc())
			{
				std::cout << "range constructor called" << std::endl;
			}

			//copy
			list (const list& origin)
			{
				
			}

			//////////////////////////////////////////////////////////////////
			//						constructor end							//
			//////////////////////////////////////////////////////////////////

	};
}

#endif