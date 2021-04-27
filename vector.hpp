/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:14:24 by honlee            #+#    #+#             */
/*   Updated: 2021/04/27 17:21:59 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <limits>
#include <string>

#include "template_util.hpp"
#include "utils.hpp"
#include "vector_iterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		private :
			T*		arr;
			size_t	noe;
			size_t	cap; 

			unsigned int	getIdxFromPtr(T* target)
			{
				return (target - arr);
			}

			void	expand(unsigned int to_size)
			{
				if (noe >= to_size)
					return ;

				Alloc alloc;

				T* temp = alloc.allocate(to_size);
				if (noe > 0)
				{
					for (size_t i = 0; i < noe; i++)
						alloc.construct(temp + i, *(arr + i));	
					alloc.destroy(arr);
					alloc.deallocate(arr, noe);
				}
				cap = to_size;
				arr = temp;
			}

			void	setValue(T* pos, const T& val)
			{
				Alloc alloc;
				alloc.construct(pos, val);
			}

			void	shift(T* pos, unsigned int shift_size)
			{
				Alloc alloc;
				unsigned int idx = getIdxFromPtr(pos);

				if (shift_size + noe >= cap)
					expand( (noe + shift_size) * 2 );
				for (unsigned int i = 0; i < noe - idx; i++)
					setValue(arr + noe - 1 + shift_size - i, *(arr + noe - 1 - i));
			}

			void	shift_back(T* pos, unsigned int shift_size)
			{
				unsigned int idx = getIdxFromPtr(pos);

				for (unsigned int i = idx; i < noe - shift_size; i++)
					setValue(arr + i, *(arr + i + shift_size));
				noe -= shift_size;
			}

			class OutOfRangeException : public std::exception
			{
				virtual const char * what() const throw()
				{
					return "Index is out of range";
				}
			};

		public	:
			typedef Alloc allocator_type;
			typedef T value_type;
			typedef size_t size_type;
			typedef ptrdiff_t difference_type;
			typedef T &reference;
			typedef const T &const_reference;
			typedef T *pointer;
			typedef const T *const_pointer;
			typedef vectorIterator<T> iterator;
			typedef vectorConstIterator<T> const_iterator;
			// typedef ReverseIterator<iterator> reverse_iterator;
			// typedef ReverseIterator<const_iterator> const_reverse_iterator;


			//////////////////////////////////////////////////////////////////
			//						constructor start						//
			//////////////////////////////////////////////////////////////////
			// default constructor
			explicit vector (const allocator_type& alloc = allocator_type()) : arr(NULL), noe(0), cap(0)
			{
				(void)alloc;
				expand(42);
			}
			// fill constructor
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : arr(NULL), noe(0), cap(0)
			{
				(void)alloc;
				expand(42);
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}
			// range constructor
			template <class InputIterator>
         	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type dummy = 0) : arr(NULL), noe(0), cap(0)
			{
				(void)alloc;
				dummy = 0;
				expand(42);
				for (InputIterator iter = first; iter != last; iter++)
					push_back(*iter);
			}
			// copy constructor
			vector (const vector& x) : arr(NULL), noe(0), cap(0)
			{
				expand(42);
				insert(begin(), x.begin(), x.end());
			}

			vector<T>& operator= (const vector& x)
			{
				clear();
				insert(begin(), x.begin(), x.end());
				return (*this);
			}

			~vector()
			{
				Alloc alloc;

				//std::cout << size() << std::endl;
				alloc.destroy(arr);
				alloc.deallocate(arr, cap);
			}
			//////////////////////////////////////////////////////////////////
			//						constructor end							//
			//////////////////////////////////////////////////////////////////
			

			//////////////////////////////////////////////////////////////////
			//						iterator start							//
			//////////////////////////////////////////////////////////////////
			iterator begin()
			{
				return (iterator(arr));
			}

			// 이 클레스의 인스턴스가 const 라면, 이 메소드가 호출될 것이고
			// 그렇다면 arr 또한 const 일 것이다. 그렇다면 vectorIterator<const T> 이므로 const_iterator 로 캐스팅된다.
			const_iterator begin() const 
			{
				return (iterator(arr));
			}

			iterator end()
			{
				return (iterator(arr + noe));
			}

			const_iterator end() const
			{
				return (iterator(arr +noe));
			}

			//////////////////////////////////////////////////////////////////
			//						iterator end							//
			//////////////////////////////////////////////////////////////////

			//////////////////////////////////////////////////////////////////
			//						capacity start							//
			//////////////////////////////////////////////////////////////////
	
			size_type size() const
			{
				return (this->noe);
			}

			size_type max_size() const
			{
				return (Alloc().max_size());
			}

			void resize (size_type n, value_type val = value_type())
			{
				unsigned int numOfEle = this->noe;
				if (numOfEle < n)
				{
					for (unsigned int i = 0; i < n - numOfEle; i++)
						push_back(val);
				}
				else
				{
					for (unsigned int i = 0; i < numOfEle - n; i++)
						pop_back();
				}
			}

			size_type capacity() const
			{
				return (this->cap);
			}

			bool empty() const
			{
				return (noe == 0);
			}

			void reserve (size_type n)
			{
				if (n > noe)
					expand(n);
			}
			
			//////////////////////////////////////////////////////////////////
			//						capacity end							//
			//////////////////////////////////////////////////////////////////
	

			//////////////////////////////////////////////////////////////////
			//						element start							//
			//////////////////////////////////////////////////////////////////

			reference operator[] (size_type n)
			{
				return (at(n));
			}

			const_reference operator[] (size_type n) const
			{
				return (at(n));
			}

			reference at (size_type n)
			{
				if (n < noe)
					return (arr[n]);
				else
					throw OutOfRangeException();
			}

			const_reference at (size_type n) const
			{
				if (n < noe)
					return (arr[n]);
				else
					throw OutOfRangeException();
			}

			reference front()
			{
				return (at(0));
			}

			const_reference front() const
			{
				return (at(0));
			}

			reference back()
			{
				return (at(noe - 1));
			}

			const_reference back() const
			{
				return (at(noe - 1));
			}

			//////////////////////////////////////////////////////////////////
			//						element end								//
			//////////////////////////////////////////////////////////////////



			//////////////////////////////////////////////////////////////////
			//						modifiers start							//
			//////////////////////////////////////////////////////////////////
			
			template <class InputIterator>
  			void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type dummy = 0)
			{
				dummy = 0;
				clear();
				unsigned int i = 0;
				for (InputIterator iter = first; iter != last; iter++)
				{
					setValue(arr + i, *iter);
					i++;
				}
				noe += i;
			}

			void assign (size_type n, const value_type& val)
			{
				clear();
				for (size_type i = 0; i < n; i++)
					setValue(arr + i, val);
				noe += n;
			}

			void push_back (const value_type& val)
			{
				if (noe >= cap)
					expand(cap * 2);
				setValue(arr + noe, val);
				noe++;
			}

			void pop_back()
			{
				if (noe > 0)
					noe--;
			}

			iterator insert (iterator position, const value_type& val)
			{
				T* pos_ptr = position.getPtr();
				shift(pos_ptr, 1);
				setValue(pos_ptr, val);
				noe++;
				return (pos_ptr);
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				T* pos_ptr = position.getPtr();
				shift(pos_ptr, n);
				for (unsigned int i = 0; i < n; i++)
					setValue(pos_ptr + i, val);
				noe += n;
			}

			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type dummy = 0)
			{
				dummy = 0;
				unsigned int len = 0;
				T* pos_ptr = position.getPtr();
				
				for (InputIterator iter = first; iter != last; iter++)
					len++;

				shift(pos_ptr, len);
				
				unsigned int i = 0;
				for (InputIterator iter = first; iter != last; iter++)
				{
					setValue(pos_ptr + i, *iter);
					i++;
				}
				noe += len;
			}

			iterator erase (iterator position)
			{
				unsigned int idx = getIdxFromPtr(position.getPtr());

				shift_back(position.getPtr(), 1);
				return (iterator(arr + idx));
				
			}

			iterator erase (iterator first, iterator last)
			{
				unsigned int idx = getIdxFromPtr(first.getPtr());

				unsigned int i = 0;
				for (iterator iter = first; iter != last; iter++)
					i++;
				shift_back(first.getPtr(), i);
				return (iterator(arr + idx));
			}

			void swap (vector& x)
			{
				T* temp = this->arr;
				this->arr = x.arr;
				x.arr = temp;

				unsigned int temp_noe = this->noe;
				this->noe = x.noe;
				x.noe = temp_noe;
				
				unsigned int temp_cap = this->cap;
				this->cap = x.cap;
				x.cap = temp_cap;
			}

			void clear()
			{
				noe = 0;
			}

			//////////////////////////////////////////////////////////////////
			//						modifiers end							//
			//////////////////////////////////////////////////////////////////
		
	};
}

#endif