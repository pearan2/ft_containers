/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:14:24 by honlee            #+#    #+#             */
/*   Updated: 2021/04/26 23:03:52 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <limits>

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

			void	expand(unsigned int to_size)
			{
				Alloc alloc;

				T* temp = alloc.allocate(to_size);
				for (size_t i = 0; i < noe; i++)
					alloc.construct(temp + i, *(arr + i));
				alloc.destroy(arr);
				alloc.deallocate(arr, noe);
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
				expand( (noe + shift_size) * 2);
				for (T* ptr = pos + shift_size; ; ptr--)
				{
					setValue(ptr, *(ptr - shift_size));
					if (ptr == pos)
						return ;
				}
			}
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
			typedef vectorIterator<const T> const_iterator;
			// typedef ReverseIterator<iterator> reverse_iterator;
			// typedef ReverseIterator<const_iterator> const_reverse_iterator;


			//////////////////////////////////////////////////////////////////
			//						constructor start						//
			//////////////////////////////////////////////////////////////////
			// default constructor
			explicit vector (const allocator_type& alloc = allocator_type()) : arr(NULL), noe(0), cap(0)
			{
				expand(42);
			}
			// fill constructor
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : arr(NULL), noe(0), cap(0)
			{
				std::cout << "fill constructor called" << std::endl;
			}
			// range constructor
			template <class InputIterator>
         	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type dummy = 0) : arr(NULL), noe(0), cap(0)
			{
				std::cout << "range constructor called" << std::endl;
			}
			// copy constructor
			vector (const vector& x)
			{
				std::cout << "copy constructor called" << std::endl;
			}

			~vector()
			{
				Alloc alloc;

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

			size_type capacity() const
			{
				return (this->cap);
			}

			void resize (size_type n, value_type val = value_type())
			{
				//resize
			}

			bool empty() const
			{
				return (noe == 0);
			}

			
			//////////////////////////////////////////////////////////////////
			//						capacity end							//
			//////////////////////////////////////////////////////////////////
	
			//////////////////////////////////////////////////////////////////
			//						modifiers start							//
			//////////////////////////////////////////////////////////////////
			
			iterator insert (iterator position, const value_type& val)
			{
				T* pos_ptr = position.getPtr();
				shift(pos_ptr, 1);
				*pos_ptr = val;
				noe++;
				return (pos_ptr);
			}

			void push_back (const value_type& val)
			{
				
			}

			//////////////////////////////////////////////////////////////////
			//						modifiers end							//
			//////////////////////////////////////////////////////////////////
		
	};
}

#endif