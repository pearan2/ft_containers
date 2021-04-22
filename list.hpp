/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:44:46 by honlee            #+#    #+#             */
/*   Updated: 2021/04/23 00:29:23 by honlee           ###   ########.fr       */
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

	template <typename T>
	class ListIterator
	{
		private	:
			Node<T> *now;
		public	:
			ListIterator(Node<T> *now = NULL) : now(now)
			{
				
			}

			ListIterator(const ListIterator& origin) : now(origin.now)
			{
				
			}

			ListIterator& operator=(const ListIterator& origin)
			{
				this->now = origin.now;
				return (*this);
			}

			~ListIterator()
			{
				
			}

			//*
			T& operator*() const
			{
				return (now->getValue());
			}

			//++ (전위)
			ListIterator& operator++()
			{
				//미리 이동시키고 보낸다.
				this->now = this->now->getNext();
				return (*this);
			}

			//++ (후위)
			//warning: reference to stack memory associated with local variable 'temp' returned [-Wreturn-stack-address
			//위는 레퍼런스를 보낼경우, 즉. temp 는 스택에 생성되기 떄문에 스택에서 생성된 변수의 레퍼런스를 보낼경우
			//워닝이 뜬다.
			ListIterator operator++(int)
			{
				//리턴하고 이동시킨다.
				ListIterator temp(*this);
				now = now->getNext();
				return (temp);
			}

			//-- (전위)
			ListIterator& operator--()
			{
				//미리 이동시키고 리턴.
				this->now = this->now->getPrev();
				return (*this);
			}

			//-- (후위)
			ListIterator operator--(int)
			{
				//리턴후 이동
				ListIterator temp(*this);
				now = now->getPrev();
				return (temp);
			}

			//->
			T*			  operator->() const
			{
				return &(operator*());
			}

			bool		  operator==(const ListIterator &origin) const
			{
				return (now == origin.now);
			}

			bool		  operator!=(const ListIterator &origin) const
			{
				return (!operator==(origin));
			}

			//getter
			Node<T>*		getNode(void)
			{
				return (this->now);
			}
	};

	template <typename T>
	class ListReverseIterator
	{
		private	:
			Node<T> *now;
		public	:
			ListReverseIterator(Node<T> *now = NULL) : now(now)
			{
				
			}

			ListReverseIterator(const ListReverseIterator& origin) : now(origin.now)
			{
				
			}

			ListReverseIterator& operator=(const ListReverseIterator& origin)
			{
				this->now = origin.now;
				return (*this);
			}

			~ListReverseIterator()
			{
				
			}

			//*
			T& operator*() const
			{
				return (now->getValue());
			}			

			//++ (전위)
			ListReverseIterator& operator++()
			{
				this->now = this->now->getPrev();
				return (*this);
			}

			//++ (후위)
			ListReverseIterator operator++(int)
			{
				//리턴하고 이동시킨다.
				ListReverseIterator temp(*this);
				now = now->getPrev();
				return (temp);
			}

			//-- (전위)
			ListReverseIterator& operator--()
			{
				//미리 이동시키고 리턴.
				this->now = this->now->getNext();
				return (*this);
			}

			//-- (후위)
			ListReverseIterator operator--(int)
			{
				//리턴후 이동
				ListReverseIterator temp(*this);
				now = now->getNext();
				return (temp);
			}

			//->
			T*			  operator->() const
			{
				return &(operator*());
			}

			bool		  operator==(const ListReverseIterator &origin) const
			{
				return (now == origin.now);
			}

			bool		  operator!=(const ListReverseIterator &origin) const
			{
				return (!operator==(origin));
			}

			//getter
			Node<T>*		getNode(void)
			{
				return (this->now);
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
			typedef ListIterator<T> iterator;
			typedef ListIterator<const T> const_iterator;
			typedef ListReverseIterator<T> reverse_iterator;
			typedef ListReverseIterator<const T> const_reverse_iterator;
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
				
			}
			
			//fill
			explicit List (size_type n, const value_type& val = value_type(), const Alloc& alloc = Alloc()) : head(NULL), tail(NULL), number_of_Node(0)
			{
				(void) alloc;
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}

			//range
			template <class InputIterator, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type>
  			List (InputIterator first, InputIterator last, const Alloc& alloc = Alloc()) : head(NULL), tail(NULL), number_of_Node(0)
			{
				(void) alloc;
				for (InputIterator iter = first; iter != last; iter++)
					push_back(*iter);
			}

			//copy
			List (const List& origin) : head(NULL), tail(NULL), number_of_Node(0)
			{
				assign(origin.begin(), origin.end());
			}
			//////////////////////////////////////////////////////////////////
			//						Constructor end							//
			//////////////////////////////////////////////////////////////////

			//////////////////////////////////////////////////////////////////
			//						Iterators start							//
			//////////////////////////////////////////////////////////////////

			iterator begin()
			{
				return (iterator(head));
			}

			const_iterator begin() const
			{
				return (iterator(head));
			}

			iterator end()
			{
				return (iterator(NULL));
			}

			const_iterator end() const
			{
				return (iterator(NULL));
			}

			reverse_iterator rbegin()
			{
				return (reverse_iterator(tail));
			}

			const_reverse_iterator rbegin() const
			{
				return (reverse_iterator(tail));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(NULL));
			}

			const_reverse_iterator rend() const
			{
				return (reverse_iterator(NULL));
			}
			//////////////////////////////////////////////////////////////////
			//						Iterators end							//
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

			void push_front (const value_type& val)
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
					this->head->setPrev(Node_tmp);
					Node_tmp->setNext(this->head);
					this->head = Node_tmp;
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

			iterator insert (iterator position, const value_type& val)
			{
				Alnod alloc;

				Node<T> Node_stack(NULL, NULL, val);
				Node<T> * Node_tmp = alloc.allocate(1);
				alloc.construct(Node_tmp, Node_stack);

				if (position == begin())
				{
					if (number_of_Node == 0)
					{
						head = Node_tmp;
						tail = Node_tmp;
					}
					else
					{
						head->setPrev(Node_tmp);
						Node_tmp->setNext(head);
						head = Node_tmp;
					}
				}
				else if (position == end())
				{
					//tail 뒤에 추가.
					tail->setNext(Node_tmp);
					Node_tmp->setPrev(tail);
					tail = Node_tmp;
				}
				else
				{
					//head 와 tail 과 모두 관련없는 상황
					Node<T> * pos_node = position.getNode();
					Node<T> * pos_node_before = pos_node->getPrev();
					Node_tmp->setPrev(pos_node_before);
					Node_tmp->setNext(pos_node);
					pos_node->setPrev(Node_tmp);
					pos_node_before->setNext(Node_tmp);
				}
				number_of_Node++;
				return (iterator(Node_tmp));
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				for (size_type i = 0; i < n; i++)
					insert(position, val);
			}

			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type dummy = 0)
			{
				for (InputIterator iter = first; iter != last; iter++)
					insert(position, *iter);
			}

			iterator erase (iterator position)
			{
				Alnod alloc;

				//자기자신을 지우고 뒤에있는놈을 리턴한다.
				Node<T>* deleted_node = position.getNode();
				if (deleted_node == head) // 지워져야 할 것이 헤드란 소리
					pop_front();
				else // 헤드가 아닌상황 즉, 자기가 지워져도 바로 앞에 한놈이 반드시 있다.
				{
					Node<T>* deleted_node_next = deleted_node->getNext();
					Node<T>* deleted_node_prev = deleted_node->getPrev();
					deleted_node_prev->setNext(deleted_node_next);
					if (deleted_node_next != NULL)
						deleted_node_next->setPrev(deleted_node_prev);
					alloc.destroy(deleted_node);
					alloc.deallocate(deleted_node, 1);
					number_of_Node--;
				}
				return (++position);
			}

			iterator erase (iterator first, iterator last)
			{
				for (iterator iter = first; iter != last; iter++)
					erase(iter);
				return (last);
			}

			void swap (List& x)
			{
				Node<T> *head_tmp = x.head;
				Node<T> *tail_tmp = x.tail;
				unsigned int num = x.number_of_Node;
				x.head = this->head;
				x.tail = this->tail;
				x.number_of_Node = this->number_of_Node;
				this->head = head_tmp;
				this->tail = tail_tmp;
				this->number_of_Node = num;
			}

			void resize (size_type n, value_type val = value_type())
			{
				unsigned int num = number_of_Node;

				if (num <= n) // 더 채워야 한다.
				{
					for (size_type i = num; i < n; i++)
						push_back(val);
				}
				else // 버려야한다.
				{
					for (size_type i = n; i < num; i++)
						pop_back();
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

			//////////////////////////////////////////////////////////////////
			//						Operations start						//
			//////////////////////////////////////////////////////////////////

			void splice (iterator position, List& x)
			{
				//position : 자기자신한테 어디서부터 저장할것인지
				//x : element 를 뺏길 제물 ㅎ

				//원소들의 생성/ 파괴가 일어나지 않고 단지 전달만함.
				//position 의 앞에 전달이 이루어짐 즉, position 이 헤더인지 아닌지 판별하면 될듯.

				//좀 복잡하게 나뉠것 같은데 고민을 더 해볼것. 우선은 
				Node<T> *pos_node = position.getNode();
				if (position == begin()) // 가장 앞에 줄줄이 붙음
				{

				}
			}

			void splice (iterator position, List& x, iterator i)
			{
				
			}

			//////////////////////////////////////////////////////////////////
			//						Operations end							//
			//////////////////////////////////////////////////////////////////

	};
}

#endif