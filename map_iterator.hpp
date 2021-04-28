/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 04:30:58 by honlee            #+#    #+#             */
/*   Updated: 2021/04/28 05:58:30 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include <iostream>
# include <string>
# include "utils.hpp"
# include "BST.hpp"

namespace ft
{
	template <typename TK, typename TV, class Compare>
	class mapIterator;

	template <typename TK, typename TV, class Compare>
	class mapConstIterator;

	template <typename TK, typename TV, class Compare = ft::less<TK> >
	class mapIterator
	{
		private :
			node <TK, TV>* now;
			Compare cmp;

			class OutOfRangeException : public std::exception
			{
				virtual const char * what() const throw()
				{
					return "Iterator is out of range";
				}
			};

			node <TK, TV>* getPrev()
			{
				if (now == NULL)
					throw (OutOfRangeException());

				if (now->getLeft() != NULL)
					return (now->getRightest(now->getLeft()));
				
				node <TK, TV>* parent = now->getParent();
				while (parent != NULL && cmp(now->first, parent->first))
					parent = parent->getParent();
				
				return (parent);
			}

			node <TK, TV>* getNext()
			{
				if (now == NULL)
					throw (OutOfRangeException());

				if (now->getRight() != NULL)
					return (now->getLeftest(now->getRight()));
				
				node <TK, TV>* parent = now->getParent();
				while (parent != NULL && cmp(parent->first, now->first))
					parent = parent->getParent();
			
				return (parent);
			}

		public	:
			mapIterator()
			{
				
			}

			mapIterator(node <TK, TV> *now) : now(now)
			{
				
			}

			mapIterator(const mapIterator<TK, TV>& origin) : now(origin.now)
			{

			}

			~mapIterator()
			{

			}

			mapIterator<TK, TV>& operator=(const mapIterator<TK, TV>& origin)
			{
				this->now = origin.now;
				return (*this);
			}

			node <TK, TV>& operator*(void) const
			{
				return (*now);
			}

			node <TK, TV>* operator->(void)
			{
				return (&(this->operator*()));
			}
			//전위 - 미리 증가시키고 보낸다.
			mapIterator<TK, TV>& operator++(void)
			{
				this->now = getNext();
				return (*this);
			}
			//후위 - 보내고 증가 시킨다.
			mapIterator<TK, TV> operator++(int)
			{
				mapIterator<TK, TV> temp(*this);
				this->now = getNext();
				return (temp);
			}
			//전위 - 미리 증가시키고 보낸다.
			mapIterator<TK, TV>& operator--(void)
			{
				this->now = getPrev();
				return (*this);
			}
			//후위 - 보내고 증가
			mapIterator<TK, TV> operator--(int)
			{
				mapIterator<TK, TV> temp(*this);
				this->now = getPrev();
				return (temp);
			}

			bool		  operator==(const mapIterator<TK, TV> &origin) const
			{
				return (now == origin.getNow());
			}

			//bool		  operator==(const mapConstIterator<TK, TV> &origin) const
			//{
			//	return (now == origin.getNow());
			//}

			bool		  operator!=(const mapIterator<TK, TV> &origin) const
			{
				return (!operator==(origin));
			}

			//bool		  operator!=(const mapConstIterator<TK, TV> &origin) const
			//{
			//	return (!operator==(origin));
			//}

			node<TK, TV>* getNow() const
			{
				return (this->now);
			}
	};
}

#endif