/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 22:02:59 by honlee            #+#    #+#             */
/*   Updated: 2021/04/27 17:38:41 by honlee           ###   ########.fr       */
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

			unsigned int operator+(const vectorConstIterator<T>target) const
			{
				return (this->ptr + target.getPtr());
			}

			unsigned int operator+(const vectorIterator<T>target) const
			{
				return (this->ptr + target.getPtr());
			}

			vectorIterator<T> operator-(unsigned int n) const
			{
				return (vectorIterator<T>(this->ptr - n));
			}

			int operator-(const vectorIterator<T>target) const
			{
				return (this->ptr - target.getPtr());
			}

			int operator-(const vectorConstIterator<T>target) const
			{
				return (this->ptr - target.getPtr());
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

			bool		  operator==(const vectorConstIterator<T> &origin) const
			{
				return (ptr == origin.getPtr());
			}

			bool		  operator==(const vectorIterator<T> &origin) const
			{
				return (ptr == origin.getPtr());
			}

			bool		  operator!=(const vectorConstIterator<T> &origin) const
			{
				return (!operator==(origin));
			}

			bool		  operator!=(const vectorIterator<T> &origin) const
			{
				return (!operator==(origin));
			}

			bool		  operator<(const vectorConstIterator<T> &origin) const
			{
				return (ptr < origin.getPtr());
			}

			bool		  operator<(const vectorIterator<T> &origin) const
			{
				return (ptr < origin.getPtr());
			}

			bool		  operator<=(const vectorConstIterator<T> &origin) const
			{
				return ( operator==(origin) || operator<(origin) );
			}

			bool		  operator<=(const vectorIterator<T> &origin) const
			{
				return ( operator==(origin) || operator<(origin) );
			}

			bool		  operator>(const vectorConstIterator<T> &origin) const
			{
				return (!operator<=(origin));
			}

			bool		  operator>(const vectorIterator<T> &origin) const
			{
				return (!operator<=(origin));
			}

			bool		  operator>=(const vectorConstIterator<T> &origin) const
			{
				return (operator>(origin) || operator==(origin));
			}

			bool		  operator>=(const vectorIterator<T> &origin) const
			{
				return (operator>(origin) || operator==(origin));
			}		
	};

	template<typename T>
    vectorIterator<T> operator+(unsigned int n, vectorIterator<T>& rai)
    {
            return (&(*rai) + n);
    }

	template <typename T>
	class vectorConstIterator
	{
		private	:
			T* ptr;

		public	:
			//default
			vectorConstIterator(T* ptr = NULL) : ptr(ptr)
			{
				
			}
			//copy
			vectorConstIterator(const vectorConstIterator<T> &origin) : ptr(origin.ptr)
			{
				
			}

			vectorConstIterator(const vectorIterator<T> &origin) : ptr(origin.getPtr())
			{
				
			}

			//operator=
			vectorConstIterator<T>& operator=(const vectorConstIterator<T> &origin)
			{
				this->ptr = origin.ptr;
				return (*this);
			}
			
			vectorConstIterator<T>& operator=(const vectorIterator<T> &origin)
			{
				this->ptr = origin.getPtr();
				return (*this);
			}

			~vectorConstIterator()
			{
				
			}

			T*	getPtr() const
			{
				return (this->ptr);
			}

			const T& operator*(void) const
			{
				return (*ptr);
			}

			const T* operator->(void) const
			{
				return (&(this->operator*()));
			}
			//전위 - 미리 증가시키고 보낸다.
			vectorConstIterator<T>& operator++(void)
			{
				this->ptr++;
				return (*this);
			}
			//후위 - 보내고 증가 시킨다.
			vectorConstIterator<T> operator++(int)
			{
				vectorConstIterator<T> temp(*this);
				this->ptr++;
				return (temp);
			}
			//전위 - 미리 증가시키고 보낸다.
			vectorConstIterator<T>& operator--(void)
			{
				this->ptr--;
				return (*this);
			}
			//후위 - 보내고 증가
			vectorConstIterator<T> operator--(int)
			{
				vectorConstIterator<T> temp(*this);
				this->ptr--;
				return (temp);
			}

			vectorConstIterator<T> operator+(unsigned int n) const
			{
				return (vectorConstIterator<T>(this->ptr + n));
			}

			unsigned int operator+(const vectorConstIterator<T>target) const
			{
				return (this->ptr + target.getPtr());
			}

			unsigned int operator+(const vectorIterator<T>target) const
			{
				return (this->ptr + target.getPtr());
			}
			
			vectorConstIterator<T> operator-(unsigned int n) const
			{
				return (vectorConstIterator<T>(this->ptr - n));
			}

			int operator-(const vectorIterator<T>target) const
			{
				return (this->ptr - target.getPtr());
			}

			int operator-(const vectorConstIterator<T>target) const
			{
				return (this->ptr - target.getPtr());
			}

			vectorConstIterator<T>& operator+=(unsigned int n)
			{
				this->ptr += n;
				return (*this);
			}

			vectorConstIterator<T>& operator-=(unsigned int n)
			{
				this->ptr -= n;
				return (*this);
			}

			const T&				operator[](unsigned int n) const
			{
				return (*(operator+(n)));
			}

			bool		  operator==(const vectorConstIterator<T> &origin) const
			{
				return (ptr == origin.getPtr());
			}

			bool		  operator==(const vectorIterator<T> &origin) const
			{
				return (ptr == origin.getPtr());
			}

			bool		  operator!=(const vectorConstIterator<T> &origin) const
			{
				return (!operator==(origin));
			}

			bool		  operator!=(const vectorIterator<T> &origin) const
			{
				return (!operator==(origin));
			}

			bool		  operator<(const vectorConstIterator<T> &origin) const
			{
				return (ptr < origin.getPtr());
			}

			bool		  operator<(const vectorIterator<T> &origin) const
			{
				return (ptr < origin.getPtr());
			}

			bool		  operator<=(const vectorConstIterator<T> &origin) const
			{
				return ( operator==(origin) || operator<(origin) );
			}

			bool		  operator<=(const vectorIterator<T> &origin) const
			{
				return ( operator==(origin) || operator<(origin) );
			}

			bool		  operator>(const vectorConstIterator<T> &origin) const
			{
				return (!operator<=(origin));
			}

			bool		  operator>(const vectorIterator<T> &origin) const
			{
				return (!operator<=(origin));
			}

			bool		  operator>=(const vectorConstIterator<T> &origin) const
			{
				return (operator>(origin) || operator==(origin));
			}

			bool		  operator>=(const vectorIterator<T> &origin) const
			{
				return (operator>(origin) || operator==(origin));
			}			
	};
	template<typename T>
    vectorConstIterator<T> operator+(unsigned int n, vectorConstIterator<T>& rai)
    {
            return (&(*rai) + n);
    }

} // namespace ft


#endif