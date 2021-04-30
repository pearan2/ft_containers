/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:34:02 by honlee            #+#    #+#             */
/*   Updated: 2021/04/30 12:06:57 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <algorithm>
# include <iostream>
# include <limits>
# include "list.hpp"

namespace ft
{
	template <class T, class Container = ft::list<T> > 
	class stack
	{
		private :
			Container c;
			stack(const stack<T>& origin){ (void)origin; }
			stack<T>& operator=(const stack<T> &origin){ (void)origin; }

		public	:
			typedef T value_type;
			typedef Container container_type;
			typedef size_t size_type;

			explicit stack (const container_type& ctnr = container_type()) : c(ctnr)
			{
				
			}

			~stack()
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

			value_type& top()
			{
				return (c.back());
			}

			const value_type& top() const
			{
				return (c.back());
			}

			void push (const value_type& val)
			{
				c.push_back(val);
			}

			void pop()
			{
				c.pop_back();
			}

			//////////////////////////////////////////////////////////////////
			//						Member functions end					//
			//////////////////////////////////////////////////////////////////

			//friends setting
			template <class TT, class CTNR>
 			friend bool operator== (const stack<TT,CTNR>& lhs, const stack<TT,CTNR>& rhs);

			template <class TT, class CTNR>
 			friend bool operator< (const stack<TT,CTNR>& lhs, const stack<TT,CTNR>& rhs);
	};

	//////////////////////////////////////////////////////////////////
	//					relational operators start					//
	//////////////////////////////////////////////////////////////////

	template <class T, class Container>
 	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		//can access to private because friend
		return (lhs.c == rhs.c);
	}

	template <class T, class Container>
  	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Container>
 	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		//can access to private because friend
		return (lhs.c < rhs.c);
	}

	template <class T, class Container>
  	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs < rhs || lhs == rhs);
	}

	template <class T, class Container>
  	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (!(lhs <= rhs));
	}

	template <class T, class Container>
  	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (!(lhs < rhs));
	}

	//////////////////////////////////////////////////////////////////
	//					relational operators end					//
	//////////////////////////////////////////////////////////////////

}

#endif