/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 22:02:59 by honlee            #+#    #+#             */
/*   Updated: 2021/04/26 23:02:41 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

namespace ft
{
	template <typename T>
	class vectorIterator;

	template <typename T>
	class vectorConstIterator;

	template <typename T>
	class vectorReverseIterator;

	template <typename T>
	class vectorReverseConstIterator;

	template <typename T>
	class vectorIterator
	{
		private	:
			T* ptr;

		public	:
			//default
			vectorIterator(T* ptr = NULL) : ptr(ptr)
			{
				
			}
			//copy
			vectorIterator(const vectorIterator<T> &origin) : ptr(origin.ptr)
			{
				
			}
			//operator=
			vectorIterator<T>& operator=(const vectorIterator<T> &origin)
			{
				this->ptr = origin.ptr;
				return (*this);
			}
			
			~vectorIterator()
			{
				
			}

			T*	getPtr() const
			{
				return (this->ptr);
			}

			T& operator*(void) const
			{
				return (*ptr);
			}

			T* operator->(void)
			{
				return (&(this->operator*()));
			}
			//전위 - 미리 증가시키고 보낸다.
			vectorIterator<T>& operator++(void)
			{
				this->ptr++;
				return (*this);
			}
			//후위 - 보내고 증가 시킨다.
			vectorIterator<T> operator++(int)
			{
				vectorIterator<T> temp(*this);
				this->ptr++;
				return (temp);
			}
			//전위 - 미리 증가시키고 보낸다.
			vectorIterator<T>& operator--(void)
			{
				this->ptr--;
				return (*this);
			}
			//후위 - 보내고 증가
			vectorIterator<T> operator--(int)
			{
				vectorIterator<T> temp(*this);
				this->ptr--;
				return (temp);
			}

			vectorIterator<T> operator+(unsigned int n) const
			{
				return (vectorIterator<T>(this->ptr + n));
			}

			vectorIterator<T> operator-(unsigned int n) const
			{
				return (vectorIterator<T>(this->ptr - n));
			}

			vectorIterator<T>& operator+=(unsigned int n)
			{
				this->ptr += n;
				return (*this);
			}

			vectorIterator<T>& operator-=(unsigned int n)
			{
				this->ptr -= n;
				return (*this);
			}

			T&				operator[](unsigned int n)
			{
				return (*(operator+(n)));
			}

			bool		  operator==(const vectorIterator<T> &origin) const
			{
				return (ptr == origin.ptr);
			}

			bool		  operator!=(const vectorIterator<T> &origin) const
			{
				return (!operator==(origin));
			}
	};



} // namespace ft


#endif