/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 04:30:58 by honlee            #+#    #+#             */
/*   Updated: 2021/05/01 10:07:28 by honlee           ###   ########seoul.kr  */
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
			saver<TK, TV, Compare>* sv;
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

			mapIterator(node<TK, TV, Compare> *now, saver<TK, TV, Compare>* sv) : now(now), sv(sv)
			{
				
			}

			mapIterator(const mapIterator<TK, TV, Compare>& origin) : now(origin.getNow()), sv(origin.getSV())
			{

			}

			~mapIterator()
			{

			}

			mapIterator<TK, TV, Compare>& operator=(const mapIterator<TK, TV, Compare>& origin)
			{
				this->now = origin.getNow();
				this->sv = origin.getSV();
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
			//?????? - ?????? ??????????????? ?????????.
			mapIterator<TK, TV, Compare>& operator++(void)
			{
				this->now = getNext();
				return (*this);
			}
			//?????? - ????????? ?????? ?????????.
			mapIterator<TK, TV, Compare> operator++(int)
			{
				mapIterator<TK, TV, Compare> temp(*this);
				this->now = getNext();
				return (temp);
			}
			//?????? - ?????? ??????????????? ?????????.
			mapIterator<TK, TV, Compare>& operator--(void)
			{
				this->now = getPrev();
				return (*this);
			}
			//?????? - ????????? ??????
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

			saver<TK, TV, Compare>* getSV() const
			{
				return (this->sv);
			}

			node<TK, TV, Compare>* getPrev() const
			{
				if (now == NULL)
					return (now->getRightest(sv->root));
		
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
					return (now->getLeftest(sv->root));

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
			saver<TK, TV, Compare>* sv;
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

			mapConstIterator(node<TK, TV, Compare> *now, saver<TK, TV, Compare> *sv) : now(now), sv(sv)
			{

			}

			mapConstIterator(const mapConstIterator<TK, TV, Compare>& origin) : now(origin.getNow()), sv(origin.getSV())
			{

			}

			mapConstIterator(const mapIterator<TK, TV, Compare>& origin) : now(origin.getNow()), sv(origin.getSV())
			{

			}

			~mapConstIterator()
			{

			}

			mapConstIterator<TK, TV, Compare>& operator=(const mapConstIterator<TK, TV, Compare>& origin)
			{
				this->now = origin.getNow();
				this->sv = origin.getSV();
				return (*this);
			}

			mapConstIterator<TK, TV, Compare>& operator=(const mapIterator<TK, TV, Compare>& origin)
			{
				this->now = origin.getNow();
				this->sv = origin.getSV();
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
			//?????? - ?????? ??????????????? ?????????.
			mapConstIterator<TK, TV, Compare>& operator++(void)
			{
				this->now = getNext();
				return (*this);
			}
			//?????? - ????????? ?????? ?????????.
			mapConstIterator<TK, TV, Compare> operator++(int)
			{
				mapConstIterator<TK, TV, Compare> temp(*this);
				this->now = getNext();
				return (temp);
			}
			//?????? - ?????? ??????????????? ?????????.
			mapConstIterator<TK, TV, Compare>& operator--(void)
			{
				this->now = getPrev();
				return (*this);
			}
			//?????? - ????????? ??????
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

			saver<TK, TV, Compare>* getSV() const
			{
				return (this->sv);
			}

			node<TK, TV, Compare>* getPrev() const
			{
				if (now == NULL)
					return (now->getRightest(sv->root));
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
					return (now->getLeftest(sv->root));

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
			saver<TK, TV, Compare>* sv;
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

			mapReverseIterator(node<TK, TV, Compare> *now, saver<TK, TV, Compare> *sv) : now(now), sv(sv)
			{
				
			}

			mapReverseIterator(const mapReverseIterator<TK, TV, Compare>& origin) : now(origin.getNow()), sv(origin.getSV())
			{

			}

			mapReverseIterator(const mapIterator<TK, TV, Compare>& origin) : now(origin.getPrev()), sv(origin.getSV())
			{

			}

			~mapReverseIterator()
			{

			}

			mapReverseIterator<TK, TV, Compare>& operator=(const mapReverseIterator<TK, TV, Compare>& origin)
			{
				this->now = origin.getNow();
				this->sv = origin.getSV();
				return (*this);
			}

			mapReverseIterator<TK, TV, Compare>& operator=(const mapIterator<TK, TV, Compare>& origin)
			{
				this->now = origin.getPrev();
				this->sv = origin.getSV();
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
			//?????? - ?????? ??????????????? ?????????.
			mapReverseIterator<TK, TV, Compare>& operator++(void)
			{
				this->now = getNext();
				return (*this);
			}
			//?????? - ????????? ?????? ?????????.
			mapReverseIterator<TK, TV, Compare> operator++(int)
			{
				mapReverseIterator<TK, TV, Compare> temp(*this);
				this->now = getNext();
				return (temp);
			}
			//?????? - ?????? ??????????????? ?????????.
			mapReverseIterator<TK, TV, Compare>& operator--(void)
			{
				this->now = getPrev();
				return (*this);
			}
			//?????? - ????????? ??????
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

			saver<TK, TV, Compare>* getSV() const
			{
				return (this->sv);
			}

			node<TK, TV, Compare>* getNext() const
			{
				if (now == NULL)
					return (now->getRightest(sv->root));

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
					return (now->getLeftest(sv->root));

				if (now->getRight() != NULL)
					return (now->getLeftest(now->getRight()));
				node<TK, TV, Compare>* parent = now->getParent();
				while (parent != NULL && cmp(parent->ip.first, now->ip.first))
					parent = parent->getParent();
			
				return (parent);
			}

			mapIterator<TK, TV, Compare> base(void) const
			{
				return (mapIterator<TK, TV, Compare>(getPrev(), sv));
			}
	};
	
	template <typename TK, typename TV, class Compare = ft::less<TK> >
	class mapReverseConstIterator
	{
		private :
			node<TK, TV, Compare>* now;
			saver<TK, TV, Compare>* sv;
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

			mapReverseConstIterator(node<TK, TV, Compare> *now, saver<TK, TV, Compare>* sv) : now(now), sv(sv)
			{
				
			}

			mapReverseConstIterator(const mapReverseConstIterator<TK, TV, Compare>& origin) : now(origin.getNow()), sv(origin.getSV())
			{

			}

			mapReverseConstIterator(const mapReverseIterator<TK, TV, Compare>& origin) : now(origin.getNow()), sv(origin.getSV())
			{

			}
			/////////////////////
			mapReverseConstIterator(const mapConstIterator<TK, TV, Compare>& origin) : now(origin.getPrev()), sv(origin.getSV())
			{

			}

			mapReverseConstIterator(const mapIterator<TK, TV, Compare>& origin) : now(origin.getPrev()), sv(origin.getSV())
			{

			}
			///////////////////////
			~mapReverseConstIterator()
			{

			}

			mapReverseConstIterator<TK, TV, Compare>& operator=(const mapReverseConstIterator<TK, TV, Compare>& origin)
			{
				this->now = origin.getNow();
				this->sv = origin.getSV();
				return (*this);
			}

			mapReverseConstIterator<TK, TV, Compare>& operator=(const mapReverseIterator<TK, TV, Compare>& origin)
			{
				this->now = origin.getNow();
				this->sv = origin.getSV();
				return (*this);
			}


			////////////////////////
			mapReverseConstIterator<TK, TV, Compare>& operator=(const mapConstIterator<TK, TV, Compare>& origin)
			{
				this->now = origin.getPrev();
				this->sv = origin.getSV();
				return (*this);
			}

			mapReverseConstIterator<TK, TV, Compare>& operator=(const mapIterator<TK, TV, Compare>& origin)
			{
				this->now = origin.getPrev();
				this->sv = origin.getSV();
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
			//?????? - ?????? ??????????????? ?????????.
			mapReverseConstIterator<TK, TV, Compare>& operator++(void)
			{
				this->now = getNext();
				return (*this);
			}
			//?????? - ????????? ?????? ?????????.
			mapReverseConstIterator<TK, TV, Compare> operator++(int)
			{
				mapReverseConstIterator<TK, TV, Compare> temp(*this);
				this->now = getNext();
				return (temp);
			}
			//?????? - ?????? ??????????????? ?????????.
			mapReverseConstIterator<TK, TV, Compare>& operator--(void)
			{
				this->now = getPrev();
				return (*this);
			}
			//?????? - ????????? ??????
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

			saver<TK, TV, Compare>* getSV() const
			{
				return (this->sv);
			}

			node<TK, TV, Compare>* getNext() const
			{
				if (now == NULL)
					return (now->getRightest(sv->root));

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
					return (now->getLeftest(sv->root));

				if (now->getRight() != NULL)
					return (now->getLeftest(now->getRight()));
				node<TK, TV, Compare>* parent = now->getParent();
				while (parent != NULL && cmp(parent->ip.first, now->ip.first))
					parent = parent->getParent();
			
				return (parent);
			}

			mapConstIterator<TK, TV, Compare> base(void) const
			{
				return (mapConstIterator<TK, TV, Compare>(getPrev(), sv));
			}
	};
}

#endif