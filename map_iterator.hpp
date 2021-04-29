/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 04:30:58 by honlee            #+#    #+#             */
/*   Updated: 2021/04/30 00:57:58 by honlee           ###   ########.fr       */
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

	template <typename TK, typename TV, class Compare>
	class mapReverseIterator;

	template <typename TK, typename TV, class Compare>
	class mapReverseConstIterator;

	template <typename TK, typename TV, class Compare = ft::less<TK> >
	class mapIterator
	{
		private :
			node<TK, TV, Compare>* now;
			node<TK, TV, Compare>* rootPtr;
			Compare cmp;

			class OutOfRangeException : public std::exception
			{
				virtual const char * what() const throw()
				{
					return "Iterator is out of range";
				}
			};

		public	:
			mapIterator()
			{
				
			}

			mapIterator(node<TK, TV, Compare> *now, node<TK, TV, Compare> *rootPtr) : now(now), rootPtr(rootPtr)
			{
				
			}

			mapIterator(const mapIterator<TK, TV, Compare>& origin) : now(origin.getNow()), rootPtr(origin.getRootPtr())
			{

			}

			~mapIterator()
			{

			}

			mapIterator<TK, TV, Compare>& operator=(const mapIterator<TK, TV, Compare>& origin)
			{
				this->now = origin.getNow();
				this->rootPtr = origin.getRootPtr();
				return (*this);
			}

			pair<const TK, TV>& operator*(void) const
			{
				return (now->ip);
			}

			pair<const TK, TV>* operator->(void) const
			{
				return (&(this->operator*()));
			}
			//전위 - 미리 증가시키고 보낸다.
			mapIterator<TK, TV, Compare>& operator++(void)
			{
				this->now = getNext();
				return (*this);
			}
			//후위 - 보내고 증가 시킨다.
			mapIterator<TK, TV, Compare> operator++(int)
			{
				mapIterator<TK, TV, Compare> temp(*this);
				this->now = getNext();
				return (temp);
			}
			//전위 - 미리 증가시키고 보낸다.
			mapIterator<TK, TV, Compare>& operator--(void)
			{
				this->now = getPrev();
				return (*this);
			}
			//후위 - 보내고 증가
			mapIterator<TK, TV, Compare> operator--(int)
			{
				mapIterator<TK, TV, Compare> temp(*this);
				this->now = getPrev();
				return (temp);
			}

			bool		  operator==(const mapConstIterator<TK, TV, Compare> &origin) const
			{
				return (now == origin.getNow());
			}

			bool		  operator==(const mapIterator<TK, TV, Compare> &origin) const
			{
				return (now == origin.getNow());
			}

			bool		  operator!=(const mapConstIterator<TK, TV, Compare> &origin) const
			{
				return (!operator==(origin));
			}

			bool		  operator!=(const mapIterator<TK, TV, Compare> &origin) const
			{
				return (!operator==(origin));
			}

			node<TK, TV, Compare>* getNow() const
			{
				return (this->now);
			}

			node<TK, TV, Compare>* getRootPtr() const
			{
				return (this->rootPtr);
			}

			node<TK, TV, Compare>* getPrev() const
			{
				if (now == NULL)
					return (now->getRightest(rootPtr));
		
				if (now->getLeft() != NULL)
					return (now->getRightest(now->getLeft()));
				node<TK, TV, Compare>* parent = now->getParent();
				while (parent != NULL && cmp(now->ip.first, parent->ip.first))
					parent = parent->getParent();
				
				return (parent);
			}

			node<TK, TV, Compare>* getNext() const
			{
				if (now == NULL)
					return (now->getLeftest(rootPtr));

				if (now->getRight() != NULL)
					return (now->getLeftest(now->getRight()));
				node<TK, TV, Compare>* parent = now->getParent();
				while (parent != NULL && cmp(parent->ip.first, now->ip.first))
					parent = parent->getParent();
			
				return (parent);
			}
	};

	template <typename TK, typename TV, class Compare = ft::less<TK> >
	class mapConstIterator
	{
		private :
			node<TK, TV, Compare>* now;
			node<TK, TV, Compare>* rootPtr;
			Compare cmp;

			class OutOfRangeException : public std::exception
			{
				virtual const char * what() const throw()
				{
					return "Iterator is out of range";
				}
			};

		public	:
			mapConstIterator()
			{
				
			}

			mapConstIterator(node<TK, TV, Compare> *now, node<TK, TV, Compare> *rootPtr) : now(now), rootPtr(rootPtr)
			{

			}

			mapConstIterator(const mapConstIterator<TK, TV, Compare>& origin) : now(origin.getNow()), rootPtr(origin.getRootPtr())
			{

			}

			mapConstIterator(const mapIterator<TK, TV, Compare>& origin) : now(origin.getNow()), rootPtr(origin.getRootPtr())
			{

			}

			~mapConstIterator()
			{

			}

			mapConstIterator<TK, TV, Compare>& operator=(const mapConstIterator<TK, TV, Compare>& origin)
			{
				this->now = origin.getNow();
				this->rootPtr = origin.getRootPtr();
				return (*this);
			}

			mapConstIterator<TK, TV, Compare>& operator=(const mapIterator<TK, TV, Compare>& origin)
			{
				this->now = origin.getNow();
				this->rootPtr = origin.getRootPtr();
				return (*this);
			}

			const pair<const TK, TV>& operator*(void) const
			{
				return (now->ip);
			}

			const pair<const TK, TV>* operator->(void) const
			{
				return (&(this->operator*()));
			}
			//전위 - 미리 증가시키고 보낸다.
			mapConstIterator<TK, TV, Compare>& operator++(void)
			{
				this->now = getNext();
				return (*this);
			}
			//후위 - 보내고 증가 시킨다.
			mapConstIterator<TK, TV, Compare> operator++(int)
			{
				mapConstIterator<TK, TV, Compare> temp(*this);
				this->now = getNext();
				return (temp);
			}
			//전위 - 미리 증가시키고 보낸다.
			mapConstIterator<TK, TV, Compare>& operator--(void)
			{
				this->now = getPrev();
				return (*this);
			}
			//후위 - 보내고 증가
			mapConstIterator<TK, TV, Compare> operator--(int)
			{
				mapConstIterator<TK, TV, Compare> temp(*this);
				this->now = getPrev();
				return (temp);
			}

			bool		  operator==(const mapConstIterator<TK, TV, Compare> &origin) const
			{
				return (now == origin.getNow());
			}

			bool		  operator==(const mapIterator<TK, TV, Compare> &origin) const
			{
				return (now == origin.getNow());
			}

			bool		  operator!=(const mapConstIterator<TK, TV, Compare> &origin) const
			{
				return (!operator==(origin));
			}

			bool		  operator!=(const mapIterator<TK, TV, Compare> &origin) const
			{
				return (!operator==(origin));
			}

			node<TK, TV, Compare>* getNow() const
			{
				return (this->now);
			}

			node<TK, TV, Compare>* getRootPtr() const
			{
				return (this->rootPtr);
			}

			node<TK, TV, Compare>* getPrev() const
			{
				if (now == NULL)
					return (now->getRightest(rootPtr));
				if (now->getLeft() != NULL)
					return (now->getRightest(now->getLeft()));
				node<TK, TV, Compare>* parent = now->getParent();
				while (parent != NULL && cmp(now->ip.first, parent->ip.first))
					parent = parent->getParent();
				
				return (parent);
			}

			node<TK, TV, Compare>* getNext() const
			{
				if (now == NULL)
					return (now->getLeftest(rootPtr));

				if (now->getRight() != NULL)
					return (now->getLeftest(now->getRight()));
				node<TK, TV, Compare>* parent = now->getParent();
				while (parent != NULL && cmp(parent->ip.first, now->ip.first))
					parent = parent->getParent();
			
				return (parent);
			}
	};

	template <typename TK, typename TV, class Compare = ft::less<TK> >
	class mapReverseIterator
	{
		private :
			node<TK, TV, Compare>* now;
			node<TK, TV, Compare>* rootPtr;
			Compare cmp;

			class OutOfRangeException : public std::exception
			{
				virtual const char * what() const throw()
				{
					return "Iterator is out of range";
				}
			};

		public	:
			mapReverseIterator()
			{
				
			}

			mapReverseIterator(node<TK, TV, Compare> *now, node<TK, TV, Compare> *rootPtr) : now(now), rootPtr(rootPtr)
			{
				
			}

			mapReverseIterator(const mapReverseIterator<TK, TV, Compare>& origin) : now(origin.getNow()), rootPtr(origin.getRootPtr())
			{

			}

			mapReverseIterator(const mapIterator<TK, TV, Compare>& origin) : now(origin.getPrev()), rootPtr(origin.getRootPtr())
			{

			}

			~mapReverseIterator()
			{

			}

			mapReverseIterator<TK, TV, Compare>& operator=(const mapReverseIterator<TK, TV, Compare>& origin)
			{
				this->now = origin.getNow();
				this->rootPtr = origin.getRootPtr();
				return (*this);
			}

			mapReverseIterator<TK, TV, Compare>& operator=(const mapIterator<TK, TV, Compare>& origin)
			{
				this->now = origin.getPrev();
				this->rootPtr = origin.getRootPtr();
				return (*this);
			}

			pair<const TK, TV>& operator*(void) const
			{
				return (now->ip);
			}

			pair<const TK, TV>* operator->(void) const
			{
				return (&(this->operator*()));
			}
			//전위 - 미리 증가시키고 보낸다.
			mapReverseIterator<TK, TV, Compare>& operator++(void)
			{
				this->now = getNext();
				return (*this);
			}
			//후위 - 보내고 증가 시킨다.
			mapReverseIterator<TK, TV, Compare> operator++(int)
			{
				mapReverseIterator<TK, TV, Compare> temp(*this);
				this->now = getNext();
				return (temp);
			}
			//전위 - 미리 증가시키고 보낸다.
			mapReverseIterator<TK, TV, Compare>& operator--(void)
			{
				this->now = getPrev();
				return (*this);
			}
			//후위 - 보내고 증가
			mapReverseIterator<TK, TV, Compare> operator--(int)
			{
				mapReverseIterator<TK, TV, Compare> temp(*this);
				this->now = getPrev();
				return (temp);
			}

			bool		  operator==(const mapReverseConstIterator<TK, TV, Compare> &origin) const
			{
				return (now == origin.getNow());
			}

			bool		  operator==(const mapReverseIterator<TK, TV, Compare> &origin) const
			{
				return (now == origin.getNow());
			}

			bool		  operator!=(const mapReverseConstIterator<TK, TV, Compare> &origin) const
			{
				return (!operator==(origin));
			}

			bool		  operator!=(const mapReverseIterator<TK, TV, Compare> &origin) const
			{
				return (!operator==(origin));
			}

			node<TK, TV, Compare>* getNow() const
			{
				return (this->now);
			}

			node<TK, TV, Compare>* getRootPtr() const
			{
				return (this->rootPtr);
			}

			node<TK, TV, Compare>* getNext() const
			{
				if (now == NULL)
					return (now->getRightest(rootPtr));

				if (now->getLeft() != NULL)
					return (now->getRightest(now->getLeft()));
				node<TK, TV, Compare>* parent = now->getParent();
				while (parent != NULL && cmp(now->ip.first, parent->ip.first))
					parent = parent->getParent();
				
				return (parent);
			}

			node<TK, TV, Compare>* getPrev() const
			{
				if (now == NULL)
					return (now->getLeftest(rootPtr));

				if (now->getRight() != NULL)
					return (now->getLeftest(now->getRight()));
				node<TK, TV, Compare>* parent = now->getParent();
				while (parent != NULL && cmp(parent->ip.first, now->ip.first))
					parent = parent->getParent();
			
				return (parent);
			}

			mapIterator<TK, TV, Compare> base(void) const
			{
				return (mapIterator<TK, TV, Compare>(getPrev(), rootPtr));
			}
	};
	
	template <typename TK, typename TV, class Compare = ft::less<TK> >
	class mapReverseConstIterator
	{
		private :
			node<TK, TV, Compare>* now;
			node<TK, TV, Compare>* rootPtr;
			Compare cmp;

			class OutOfRangeException : public std::exception
			{
				virtual const char * what() const throw()
				{
					return "Iterator is out of range";
				}
			};

		public	:
			mapReverseConstIterator()
			{
				
			}

			mapReverseConstIterator(node<TK, TV, Compare> *now, node<TK, TV, Compare> * rootPtr) : now(now), rootPtr(rootPtr)
			{
				
			}

			mapReverseConstIterator(const mapReverseConstIterator<TK, TV, Compare>& origin) : now(origin.getNow()), rootPtr(origin.getRootPtr())
			{

			}

			mapReverseConstIterator(const mapReverseIterator<TK, TV, Compare>& origin) : now(origin.getNow()), rootPtr(origin.getRootPtr())
			{

			}
			/////////////////////
			mapReverseConstIterator(const mapConstIterator<TK, TV, Compare>& origin) : now(origin.getPrev()), rootPtr(origin.getRootPtr())
			{

			}

			mapReverseConstIterator(const mapIterator<TK, TV, Compare>& origin) : now(origin.getPrev()), rootPtr(origin.getRootPtr())
			{

			}
			///////////////////////
			~mapReverseConstIterator()
			{

			}

			mapReverseConstIterator<TK, TV, Compare>& operator=(const mapReverseConstIterator<TK, TV, Compare>& origin)
			{
				this->now = origin.getNow();
				this->rootPtr = origin.getRootPtr();
				return (*this);
			}

			mapReverseConstIterator<TK, TV, Compare>& operator=(const mapReverseIterator<TK, TV, Compare>& origin)
			{
				this->now = origin.getNow();
				this->rootPtr = origin.getRootPtr();
				return (*this);
			}


			////////////////////////
			mapReverseConstIterator<TK, TV, Compare>& operator=(const mapConstIterator<TK, TV, Compare>& origin)
			{
				this->now = origin.getPrev();
				this->rootPtr = origin.getRootPtr();
				return (*this);
			}

			mapReverseConstIterator<TK, TV, Compare>& operator=(const mapIterator<TK, TV, Compare>& origin)
			{
				this->now = origin.getPrev();
				this->rootPtr = origin.getRootPtr();
				return (*this);
			}			
			////////////////////////

			const pair<const TK, TV>& operator*(void) const
			{
				return (now->ip);
			}

			const pair<const TK, TV>* operator->(void) const
			{
				return (&(this->operator*()));
			}
			//전위 - 미리 증가시키고 보낸다.
			mapReverseConstIterator<TK, TV, Compare>& operator++(void)
			{
				this->now = getNext();
				return (*this);
			}
			//후위 - 보내고 증가 시킨다.
			mapReverseConstIterator<TK, TV, Compare> operator++(int)
			{
				mapReverseConstIterator<TK, TV, Compare> temp(*this);
				this->now = getNext();
				return (temp);
			}
			//전위 - 미리 증가시키고 보낸다.
			mapReverseConstIterator<TK, TV, Compare>& operator--(void)
			{
				this->now = getPrev();
				return (*this);
			}
			//후위 - 보내고 증가
			mapReverseConstIterator<TK, TV, Compare> operator--(int)
			{
				mapReverseConstIterator<TK, TV, Compare> temp(*this);
				this->now = getPrev();
				return (temp);
			}

			bool		  operator==(const mapReverseConstIterator<TK, TV, Compare> &origin) const
			{
				return (now == origin.getNow());
			}

			bool		  operator==(const mapReverseIterator<TK, TV, Compare> &origin) const
			{
				return (now == origin.getNow());
			}

			bool		  operator!=(const mapReverseConstIterator<TK, TV, Compare> &origin) const
			{
				return (!operator==(origin));
			}

			bool		  operator!=(const mapReverseIterator<TK, TV, Compare> &origin) const
			{
				return (!operator==(origin));
			}

			node<TK, TV, Compare>* getNow() const
			{
				return (this->now);
			}

			node<TK, TV, Compare>* getRootPtr() const
			{
				return (this->rootPtr);
			}

			node<TK, TV, Compare>* getNext() const
			{
				if (now == NULL)
					return (now->getRightest(rootPtr));

				if (now->getLeft() != NULL)
					return (now->getRightest(now->getLeft()));
				node<TK, TV, Compare>* parent = now->getParent();
				while (parent != NULL && cmp(now->ip.first, parent->ip.first))
					parent = parent->getParent();
				
				return (parent);
			}

			node<TK, TV, Compare>* getPrev() const
			{
				if (now == NULL)
					return (now->getLeftest(rootPtr));

				if (now->getRight() != NULL)
					return (now->getLeftest(now->getRight()));
				node<TK, TV, Compare>* parent = now->getParent();
				while (parent != NULL && cmp(parent->ip.first, now->ip.first))
					parent = parent->getParent();
			
				return (parent);
			}

			mapConstIterator<TK, TV, Compare> base(void) const
			{
				return (mapConstIterator<TK, TV, Compare>(getPrev(), rootPtr));
			}
	};
}

#endif