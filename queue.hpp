/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 12:06:17 by honlee            #+#    #+#             */
/*   Updated: 2021/04/30 14:24:24 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include <algorithm>
# include <iostream>
# include <limits>
# include "list.hpp"

namespace ft
{
	template <class T, class Container = ft::list<T> >
	class queue
	{
		private :
			Container c;

			queue(const queue& origin) {(void)origin;}
			queue<T>& operator=(const queue& origin){(void)origin;}
		public	:

			typedef T value_type;
			typedef Container container_type;
			typedef size_t size_type;

			explicit queue (const container_type& ctnr = container_type()) : c(ctnr)
			{
				
			}

			~queue()
			{
				
			}

			//////////////////////////////////////////////////////////////////
			//						Member functions start					//
			//////////////////////////////////////////////////////////////////

			bool empty() const
			{
				return (c.empty());
			}

			size_type size() const
			{
				return (c.size());
			}

			value_type& front()
			{
				return (c.front());
			}

			const value_type& front() const
			{
				return (c.front());
			}

			value_type& back()
			{
				return (c.back());
			}

			const value_type& back() const
			{
				return (c.back());
			}

			void push (const value_type& val)
			{
				return (c.push_back(val));
			}

			void pop()
			{
				return (c.pop_front());
			}

			//////////////////////////////////////////////////////////////////
			//						Member functions end					//
			//////////////////////////////////////////////////////////////////

			//friends setting
			template <class TT, class CTNR>
 			friend bool operator== (const queue<TT,CTNR>& lhs, const queue<TT,CTNR>& rhs);

			template <class TT, class CTNR>
 			friend bool operator< (const queue<TT,CTNR>& lhs, const queue<TT,CTNR>& rhs);
	};

	template <class T, class Container>
 	bool operator==(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		//can access to private because friend
		return (lhs.c == rhs.c);
	}

	template <class T, class Container>
  	bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Container>
 	bool operator<(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		//can access to private because friend
		return (lhs.c < rhs.c);
	}

	template <class T, class Container>
  	bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs < rhs || lhs == rhs);
	}

	template <class T, class Container>
  	bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (!(lhs <= rhs));
	}

	template <class T, class Container>
  	bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (!(lhs < rhs));
	}
}

#endif