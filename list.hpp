/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:44:46 by honlee            #+#    #+#             */
/*   Updated: 2021/04/22 13:51:14 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef List_HPP
# define List_HPP

#include <algorithm>
#include <cstddef>
#include <iostream>
#include "template_util.hpp"
#include <limits>

namespace ft
{
	template <typename T>
	class Node
	{
		private :
			Node*	prev;
			Node*	next;
			T		value;

		public	:
			//canonical form start
			Node() : prev(NULL), next(NULL)
			{
				
			}
			Node(Node* prev, Node* next) : prev(prev), next(next)
			{

			}
			Node(Node* prev, Node* next, const T& value) : prev(prev), next(next), value(value)
			{
				
			}
			Node(Node const &origin) : prev(origin.prev), next(origin.next), value(origin.value)
			{
				
			}
			Node &operator=(Node const &origin)
			{
				this->prev = origin.prev;
				this->next = origin.next;
				this->valu = origin.value;
				return (*this);
			}
			~Node()
			{
				//std::cout << " Noooooo ! value " << this->value << "  Node detroyed :(" << std::endl;
			}
			//canonical form end

			//getter
			Node*	getPrev(void)
			{
				return (this->prev);
			}

			Node*	getNext(void)
			{
				return (this->next);
			}

			const T&getValue(void) const
			{
				return (this->value);
			}

			T&		getValue(void)
			{
				return (this->value);
			}

			//setter
			void	setNext(Node *next)
			{
				this->next = next;
			}
			void	setPrev(Node *prev)
			{
				this->prev = prev;
			}
			void	setValue(const T& value)
			{
				this->value = value;
			}

			//new with value
			Node*	clone_with_value(void)
			{
				return (new Node(NULL, NULL, this->value));
			}
	};

	template <class T, class Alloc = std::allocator<T> >
	class List
	{
		private :
			Node<T>			*head;
			Node<T>			*tail;
			size_t			number_of_Node;

		public :
			//member types start
			typedef T value_type;
			typedef T &reference;
			typedef const T &const_reference;
			typedef T *pointer;
			typedef const T *const_pointer;
			//typedef ListIterator<T> iterator;
			//typedef ListIterator<const T> const_iterator;
			//typedef ReverseIterator<iterator> reverse_iterator;
			//typedef ReverseIterator<const_iterator> const_reverse_iterator;
			typedef std::ptrdiff_t difference_type;
			typedef size_t size_type;
			//rebind
			typedef typename Alloc::template rebind< Node<T> >::other Alnod;
			//rebind end
			//member types end
			
			//////////////////////////////////////////////////////////////////
			//						constructor start						//
			//////////////////////////////////////////////////////////////////
			//default
			explicit List (const Alloc& alloc = Alloc()) : head(NULL), tail(NULL), number_of_Node(0)
			{
				std::cout << "default constructor called" << std::endl;
			}
			
			//fill
			explicit List (size_type n, const value_type& val = value_type(), const Alloc& alloc = Alloc()) : head(NULL), tail(NULL), number_of_Node(0)
			{
				std::cout << "fill constructor called" << std::endl;
			}

			//range
			template <class InputIterator, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type>
  			List (InputIterator first, InputIterator last, const Alloc& alloc = Alloc()) : head(NULL), tail(NULL), number_of_Node(0)
			{
				std::cout << "range constructor called" << std::endl;
			}

			//copy
			List (const List& origin) : head(NULL), tail(NULL), number_of_Node(0)
			{
				std::cout << "copy constructor called" << std::endl;
			}
			//////////////////////////////////////////////////////////////////
			//						constructor end							//
			//////////////////////////////////////////////////////////////////

			//////////////////////////////////////////////////////////////////
			//						Capacity start							//
			//////////////////////////////////////////////////////////////////

			bool empty() const
			{
				return (this->number_of_Node == 0);
			}

			size_type size() const
			{
				return (this->number_of_Node);
			}

			size_type max_size() const
			{
				return (std::numeric_limits<difference_type>::max());
			}

			//////////////////////////////////////////////////////////////////
			//						Capacity start							//
			//////////////////////////////////////////////////////////////////		

			//////////////////////////////////////////////////////////////////
			//						Element access start					//
			//////////////////////////////////////////////////////////////////
			reference front()
			{
				return (head->getValue());
			}

			const_reference front() const
			{
				return (head->getValue());
			}

			reference back()
			{
				return (tail->getValue());
			}

			const_reference back() const
			{
				return (tail->getValue());
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

			void push_back (const value_type& val)
			{
				Alnod alloc;

				Node<T> Node_stack(NULL, NULL, val);
				Node<T> * Node_tmp = alloc.allocate(1);
				alloc.construct(Node_tmp, Node_stack);

				if (this->number_of_Node == 0)
				{
					this->head = Node_tmp;
					this->tail = Node_tmp;
				}
				else
				{
					this->tail->setNext(Node_tmp);
					Node_tmp->setPrev(this->tail);
					this->tail = Node_tmp;
				}
				this->number_of_Node++;
			}

			void pop_front()
			{
				Alnod alloc = Alnod();

				if (this->number_of_Node == 0)
					return ;
				else if (this->number_of_Node == 1)
				{
					alloc.destroy(head);
					alloc.deallocate(head, 1);
					this->head = NULL;
					this->tail = NULL;
					this->number_of_Node = 0;
				}
				else
				{
					Node<T> *head_temp = this->head->getNext();
					head_temp->setPrev(NULL);
					alloc.destroy(head);
					alloc.deallocate(head, 1);
					this->head = head_temp;
					this->number_of_Node -= 1;
				}
			}

			void pop_back()
			{
				Alnod alloc;
				
				if (this->number_of_Node == 0)
					return ;
				else if (this->number_of_Node == 1)
					pop_front();
				else
				{
					Node<T> *tail_temp = this->tail->getPrev();
					tail_temp->setNext(NULL);
					alloc.destroy(tail);
					alloc.deallocate(tail, 1);
					this->tail = tail_temp;
					this->number_of_Node -= 1;
				}
			}

			void clear()
			{
				Alnod alloc = Alnod();

				Node<T> *temp = head;
				Node<T> *temp_next;
				while (temp != NULL)
				{
					temp_next = temp->getNext();
					alloc.destroy(temp);
					alloc.deallocate(temp, 1);
					temp = temp_next;
				}
				this->number_of_Node = 0;
				this->head = NULL;
				this->tail = NULL;
			}
			//////////////////////////////////////////////////////////////////
			//						Modifiers end							//
			//////////////////////////////////////////////////////////////////
	};
}

#endif