/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:44:46 by honlee            #+#    #+#             */
/*   Updated: 2021/04/26 22:04:12 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <limits>
#include "template_util.hpp"
#include "utils.hpp"
#include "list_iterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class list
	{
		private :
			node<T>			*base;
			size_t			number_of_node;
			
			//my private func
			//create node by alloc
			node<T>*		addBeforeNode(node<T>* pos, const T& val)
			{
				Alnod alloc;

				node<T> *new_node = alloc.allocate(1);
				alloc.construct(new_node, node<T>(NULL, NULL, val));

				node<T> *pos_prev = pos->getPrev();
				pos_prev->setNext(new_node);
				pos->setPrev(new_node);
				new_node->setPrev(pos_prev);
				new_node->setNext(pos);
				number_of_node++;
				return (new_node);
			}

			//destroy node and dealloc mem by alloc
			node<T>*			deleteNode(node<T>* pos)
			{
				if (pos == base)
					return (base);

				Alnod alloc;

				node<T> *delete_prev = pos->getPrev();
				node<T> *delete_next = pos->getNext();
				
				alloc.destroy(pos);
				alloc.deallocate(pos, 1);
				delete_prev->setNext(delete_next);
				delete_next->setPrev(delete_prev);
				number_of_node--;
				return (delete_next);
			}

			//add target node without create node
			node<T>*			recruitNode(node<T>*pos, node<T>* target)
			{
				node<T> *pos_prev = pos->getPrev();
				pos_prev->setNext(target);
				pos->setPrev(target);
				target->setPrev(pos_prev);
				target->setNext(pos);
				number_of_node++;
				return (target);
			}

			//delete target node without destroy, dealloc
			node<T>*			releaseNode(node<T>* target)
			{
				node<T>* delete_prev = target->getPrev();
				node<T>* delete_next = target->getNext();
				
				delete_prev->setNext(delete_next);
				delete_next->setPrev(delete_prev);
				number_of_node--;
				return (delete_next);
			}

			void				changePrevNextAll(node<T>* head)
			{
				if (head != base)
					changePrevNextAll(head->getNext());
				node<T> *temp = head->getPrev();
				head->setPrev(head->getNext());
				head->setNext(temp);
			}			

		public :
			//member types start
			typedef T value_type;
			typedef T &reference;
			typedef const T &const_reference;
			typedef T *pointer;
			typedef const T *const_pointer;
			typedef listIterator<T> iterator;
			typedef listConstIterator<T> const_iterator;
			typedef listReverseIterator<T> reverse_iterator;
			typedef listReverseConstIterator<T> const_reverse_iterator;
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
			explicit list (const Alloc& alloc = Alloc()) : base(NULL), number_of_node(0)
			{
				(void)alloc;
				Alnod _alloc;
				base = _alloc.allocate(1);
				_alloc.construct(base, node<T>(base, base));
			}
			
			//fill
			explicit list (size_type n, const value_type& val = value_type(), const Alloc& alloc = Alloc()) : base(NULL), number_of_node(0)
			{
				(void)alloc;
				Alnod _alloc;
				base = _alloc.allocate(1);
				_alloc.construct(base, node<T>(base, base));
				
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}

			//range
			template <class InputIterator>
  			list (InputIterator first, InputIterator last, const Alloc& alloc = Alloc(), typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type dummy = 0) : base(NULL), number_of_node(0)
			{
				dummy = 0;
				(void)alloc;
				Alnod _alloc;
				base = _alloc.allocate(1);
				_alloc.construct(base, node<T>(base, base));
				
				for (InputIterator iter = first; iter != last; iter++)
					push_back(*iter);
			}

			//copy
			list (const list& origin) : base(NULL), number_of_node(0)
			{
				Alnod _alloc;
				base = _alloc.allocate(1);
				_alloc.construct(base, node<T>(base, base));
				for (const_iterator iter = origin.begin(); iter != origin.end(); iter++)
					push_back(*iter);
			}

			//operator=
			list& operator=(const list& origin)
			{
				clear();
				for (const_iterator iter = origin.begin(); iter != origin.end(); iter++)
					push_back(*iter);
				return (*this);
			}

			~list()
			{
				clear();
				Alnod alloc;
				
				alloc.destroy(base);
				alloc.deallocate(base, 1);
			}
			//////////////////////////////////////////////////////////////////
			//						Constructor end							//
			//////////////////////////////////////////////////////////////////

			//////////////////////////////////////////////////////////////////
			//						Iterators start							//
			//////////////////////////////////////////////////////////////////

			iterator begin()
			{
				return (iterator(base->getNext()));
			}

			const_iterator begin() const
			{
				return (const_iterator(base->getNext()));
			}

			iterator end()
			{
				return (iterator(base));
			}

			const_iterator end() const
			{
				return (const_iterator(base));
			}

			reverse_iterator rbegin()
			{
				return (reverse_iterator(base->getPrev()));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(base->getPrev()));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(base));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(base));
			}
			//////////////////////////////////////////////////////////////////
			//						Iterators end							//
			//////////////////////////////////////////////////////////////////


			//////////////////////////////////////////////////////////////////
			//						Capacity start							//
			//////////////////////////////////////////////////////////////////

			bool empty() const
			{
				return (this->number_of_node == 0);
			}

			size_type size() const
			{
				return (this->number_of_node);
			}

			size_type max_size() const
			{
				return (Alnod().max_size());
			}

			//////////////////////////////////////////////////////////////////
			//						Capacity start							//
			//////////////////////////////////////////////////////////////////		

			//////////////////////////////////////////////////////////////////
			//						Element access start					//
			//////////////////////////////////////////////////////////////////
			reference front()
			{
				return (base->getNext()->getValue());
			}

			const_reference front() const
			{
				return (base->getNext()->getValue());
			}

			reference back()
			{
				return (base->getPrev()->getValue());
			}

			const_reference back() const
			{
				return (base->getPrev()->getValue());
			}
			//////////////////////////////////////////////////////////////////
			//						Element access end						//
			//////////////////////////////////////////////////////////////////

			//////////////////////////////////////////////////////////////////
			//						Modifiers start							//
			//////////////////////////////////////////////////////////////////
			//이렇게 처리 해주면 InputIer 가 들어와을 때이게 숫자라면 아래 size_type n 으로 보내 줄 수 있다. (에러가 나기 때문)
			//생성자에서 했던 방식으로 처리해주고 싶었는데, 그러면 안먹힌다. 이유는 모르겠다 이런 쉬벌벌. 아무래도 인자가 2개라서
			//아예 InputIterator 로 들어온 템플릿 말고는 검사자체를 안하기 때문인 것 같다.
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type dummy = 0)
			{
				dummy = 0;	
				clear();
				for (InputIterator iter = first; iter != last; iter++)
					push_back(*iter);
			}

			void assign (size_type n, const value_type& val)
			{
				clear();
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}

			void push_front (const value_type& val) { addBeforeNode(base->getNext(), val); }

			void pop_front() { deleteNode(base->getNext()); }

			void push_back (const value_type& val) { addBeforeNode(base, val); }

			void pop_back()	{ deleteNode(base->getPrev()); }

			//자기 앞에 넣음. 리턴은 새로 만들어져서 들어간 놈의 이터레이터
			iterator insert (iterator position, const value_type& val) { return (iterator(addBeforeNode(position.getnode(), val))); }


			void insert (iterator position, size_type n, const value_type& val)
			{
				for (size_type i = 0; i < n; i++)
					insert(position, val);
			}

			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type dummy = 0)
			{
				dummy = 0;
				for (InputIterator iter = first; iter != last; iter++)
					insert(position, *iter);
			}

			iterator erase (iterator position) { return (iterator(deleteNode(position.getnode()))); }

			iterator erase (iterator first, iterator last)
			{
				for (iterator iter = first; iter != last; iter++)
					erase(iter);
				return (last);
			}

			void swap (list& x)
			{
				node<T> *temp = x.base;
				x.base = this->base;
				this->base = temp;

				unsigned int size_temp = x.number_of_node;
				x.number_of_node = this->number_of_node;
				this->number_of_node = size_temp;
			}

			void resize (size_type n, value_type val = value_type())
			{
				//가지고 있는게 더 작다. 채워넣어야한다. 
				if (number_of_node <= n)
				{
					while (number_of_node != n)
						push_back(val);
				}
				else // 가진게 더 많다. 없애야한다.
				{
					while (number_of_node != n)
						pop_back();
				}
			}

			void clear()
			{
				while (base->getNext() != base)
					deleteNode(base->getNext());	
			}
			//////////////////////////////////////////////////////////////////
			//						Modifiers end							//
			//////////////////////////////////////////////////////////////////

			//////////////////////////////////////////////////////////////////
			//						Operations start						//
			//////////////////////////////////////////////////////////////////

			void splice (iterator position, list& x)
			{
				splice(position, x, x.begin(), x.end());
			}

			void splice (iterator position, list& x, iterator i)
			{
				iterator it2 = i;
				it2++;
				splice(position, x, i, it2);
			}

			void splice (iterator position, list& x, iterator first, iterator last)
			{
				for (iterator iter = first; iter != last;)
				{
					iterator iter_next = iter;
					iter_next++;
					node<T>* target = iter.getnode();
					node<T>* pos = position.getnode();
					x.releaseNode(target);
					this->recruitNode(pos, target);					
					iter = iter_next;
				}
			}

			void remove (const value_type& val)
			{
				node<T> *temp = base->getNext();
				node<T> *temp_next;
				while (temp != base)
				{
					temp_next = temp->getNext();
					if (temp->getValue() == val)
						deleteNode(temp);
					temp = temp_next;
				}
			}

			template <class Predicate>
  			void remove_if (Predicate pred)
			{
				node<T> *temp = base->getNext();
				node<T> *temp_next;
				while (temp != base)
				{
					temp_next = temp->getNext();
					if (pred(temp->getValue()))
						deleteNode(temp);
					temp = temp_next;
				}
			}

			void unique()
			{
				node<T>* temp = base->getNext();
				while (temp != base)
				{
					node<T>*temp2 = temp->getNext();
					node<T>*temp2_next;
					while (temp2 != base)
					{
						temp2_next = temp2->getNext();
						if (temp->getValue() == temp2->getValue())
							deleteNode(temp2);
						temp2 = temp2_next;
					}
					temp = temp->getNext();
				}
			}

			template <class BinaryPredicate>
			void unique (BinaryPredicate binary_pred)
			{
				node<T>* temp = base->getNext();
				while (temp != base)
				{
					node<T>*temp2 = temp->getNext();
					node<T>*temp2_next;
					while (temp2 != base)
					{
						temp2_next = temp2->getNext();
						if (binary_pred(temp->getValue(), temp2->getValue()))
							deleteNode(temp2);
						temp2 = temp2_next;
					}
					temp = temp->getNext();
				}
			}

			void merge (list& x)
			{
				node<T>* x_temp = x.base->getNext();
				node<T>* x_temp_next;
				node<T>* n_start = this->base->getNext();
				while (x_temp != x.base)
				{
					bool is_in = false;

					x_temp_next = x_temp->getNext();
					node<T>* n_temp = n_start;
					while (n_temp != this->base)
					{
						if (n_temp->getValue() > x_temp->getValue())
						{
							x.releaseNode(x_temp);
							this->recruitNode(n_temp, x_temp);
							is_in = true;
							n_start = x_temp->getNext();
							break ;
						}
						n_temp = n_temp->getNext();
					}
					if (is_in == false)
					{
						x.releaseNode(x_temp);
						this->recruitNode(base, x_temp);
					}
					x_temp = x_temp_next;
				}
			}

			template <class Compare>
  			void merge (list& x, Compare comp)
			{
				node<T>* x_temp = x.base->getNext();
				node<T>* x_temp_next;
				node<T>* n_start = this->base->getNext();
				while (x_temp != x.base)
				{
					bool is_in = false;

					x_temp_next = x_temp->getNext();
					node<T>* n_temp = n_start;
					while (n_temp != this->base)
					{
						if ( comp(x_temp->getValue(), n_temp->getValue()) )
						{
							x.releaseNode(x_temp);
							this->recruitNode(n_temp, x_temp);
							is_in = true;
							n_start = x_temp->getNext();
							break ;
						}
						n_temp = n_temp->getNext();
					}
					if (is_in == false)
					{
						x.releaseNode(x_temp);
						this->recruitNode(base, x_temp);
					}
					x_temp = x_temp_next;
				}
			}

			void sort()
			{
				node<T>* temp = base->getNext();
				while (temp->getNext() != base)
				{
					if (temp->getValue() > temp->getNext()->getValue())
					{
						T value_temp = temp->getValue();
						temp->setValue(temp->getNext()->getValue());
						temp->getNext()->setValue(value_temp);
						temp = base->getNext();
					}
					else
						temp = temp->getNext();
				}
			}

			template <class Compare>
  			void sort (Compare comp)
			{
				node<T>* temp = base->getNext();
				while (temp->getNext() != base)
				{
					if (!comp(temp->getValue(), temp->getNext()->getValue()))
					{
						T value_temp = temp->getValue();
						temp->setValue(temp->getNext()->getValue());
						temp->getNext()->setValue(value_temp);
						temp = base->getNext();
					}
					else
						temp = temp->getNext();
				}
			}

			void reverse() { changePrevNextAll(base->getNext()); }
			//////////////////////////////////////////////////////////////////
			//						Operations end							//
			//////////////////////////////////////////////////////////////////


	};

	template <class T, class Alloc>
  	bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class T, class Alloc>
	bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (!(lhs==rhs));
	}

	template <class T, class Alloc>
  	bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return lexicographical_less(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return ((lhs == rhs) || (lhs < rhs));
	}

	template <class T, class Alloc>
	bool operator> (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (!(lhs <= rhs));
	}

	template <class T, class Alloc>
	bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return ((lhs == rhs) || (lhs > rhs));
	}

	template <class T, class Alloc>
	void swap (list<T,Alloc>& x,list<T,Alloc>& y)
	{
		x.swap(y);
	}
}

#endif