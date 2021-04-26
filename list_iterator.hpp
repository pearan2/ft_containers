/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:29:26 by honlee            #+#    #+#             */
/*   Updated: 2021/04/26 22:05:19 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ITERATOR_HPP
# define LIST_ITERATOR_HPP

namespace ft
{
	template <typename T>
	class listConstIterator;

	template <typename T>
	class listReverseConstIterator;

	template <typename T>
	class listReverseIterator;

	template <typename T>
	class listIterator;

	template <typename T>
	class node
	{
		private :
			node*	prev;
			node*	next;
			T		value;

		public	:
			//canonical form start
			node() : prev(NULL), next(NULL)
			{
				
			}
			node(node* prev, node* next) : prev(prev), next(next)
			{

			}
			node(node* prev, node* next, const T& value) : prev(prev), next(next), value(value)
			{
				
			}
			node(node const &origin) : prev(origin.prev), next(origin.next), value(origin.value)
			{
				
			}
			node &operator=(node const &origin)
			{
				this->prev = origin.prev;
				this->next = origin.next;
				this->valu = origin.value;
				return (*this);
			}
			~node()
			{
				
			}

			//getter
			node*	getPrev(void)
			{
				return (this->prev);
			}

			node*	getNext(void)
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
			void	setNext(node *next)
			{
				this->next = next;
			}
			void	setPrev(node *prev)
			{
				this->prev = prev;
			}
			void	setValue(const T& value)
			{
				this->value = value;
			}

			//new with value
			node*	clone_with_value(void)
			{
				return (new node(NULL, NULL, this->value));
			}
	};

	template <typename T>
	class listIterator
	{
		private	:
			node<T> *now;
		public	:
			listIterator(node<T> *now = NULL) : now(now)
			{
				
			}

			listIterator(const listIterator<T>& origin) : now(origin.now)
			{
				
			}

			listIterator<T>& operator=(const listIterator<T>& origin)
			{
				this->now = origin.now;
				return (*this);
			}

			~listIterator()
			{
				
			}

			//*
			T& operator*()
			{
				return (now->getValue());
			}

			//++ (전위)
			listIterator<T>& operator++()
			{
				//미리 이동시키고 보낸다.
				this->now = this->now->getNext();
				return (*this);
			}

			//++ (후위)
			//warning: reference to stack memory associated with local variable 'temp' returned [-Wreturn-stack-address
			//위는 레퍼런스를 보낼경우, 즉. temp 는 스택에 생성되기 떄문에 스택에서 생성된 변수의 레퍼런스를 보낼경우
			//워닝이 뜬다.
			listIterator<T> operator++(int)
			{
				//리턴하고 이동시킨다.
				listIterator<T> temp(*this);
				now = now->getNext();
				return (temp);
			}

			//-- (전위)
			listIterator<T>& operator--()
			{
				//미리 이동시키고 리턴.
				this->now = this->now->getPrev();
				return (*this);
			}

			//-- (후위)
			listIterator<T> operator--(int)
			{
				//리턴후 이동
				listIterator<T> temp(*this);
				now = now->getPrev();
				return (temp);
			}

			//->
			T*			  operator->()
			{
				return &(operator*());
			}

			bool		  operator==(const listIterator<T> &origin) const
			{
				return (now == origin.now);
			}

			bool		  operator==(const listConstIterator<T> &origin) const
			{
				return (now == origin.getnode());
			}

			bool		  operator!=(const listIterator<T> &origin) const
			{
				return (!operator==(origin));
			}

			bool		  operator!=(const listConstIterator<T> &origin) const
			{
				return (!operator==(origin));
			}

			//getter
			node<T>*		getnode(void) const
			{
				return (this->now);
			}
	};

	template <typename T>
	class listConstIterator
	{
		private	:
			node<T> *now;
		public	:
			listConstIterator(node<T> *now = NULL) : now(now)
			{
				
			}

			listConstIterator(const listConstIterator<T>& origin) : now(origin.now)
			{
				
			}

			listConstIterator(const listIterator<T>& origin) : now(origin.getnode())
			{
				
			}

			listConstIterator<T>& operator=(const listIterator<T>& origin)
			{
				this->now = origin.getnode();
				return (*this);
			}

			listConstIterator<T>& operator=(const listConstIterator<T>& origin)
			{
				this->now = origin.now;
				return (*this);
			}

			~listConstIterator()
			{
				
			}

			//*
			const T& operator*()
			{
				return (now->getValue());
			}

			//++ (전위)
			listConstIterator<T>& operator++()
			{
				//미리 이동시키고 보낸다.
				this->now = this->now->getNext();
				return (*this);
			}

			//++ (후위)
			//warning: reference to stack memory associated with local variable 'temp' returned [-Wreturn-stack-address
			//위는 레퍼런스를 보낼경우, 즉. temp 는 스택에 생성되기 떄문에 스택에서 생성된 변수의 레퍼런스를 보낼경우
			//워닝이 뜬다.
			listConstIterator<T> operator++(int)
			{
				//리턴하고 이동시킨다.
				listConstIterator<T> temp(*this);
				now = now->getNext();
				return (temp);
			}

			//-- (전위)
			listConstIterator<T>& operator--()
			{
				//미리 이동시키고 리턴.
				this->now = this->now->getPrev();
				return (*this);
			}

			//-- (후위)
			listConstIterator<T> operator--(int)
			{
				//리턴후 이동
				listConstIterator<T> temp(*this);
				now = now->getPrev();
				return (temp);
			}

			//->
			const T*			  operator->()
			{
				return &(operator*());
			}

			bool		  operator==(const listConstIterator<T> &origin) const
			{
				return (now == origin.now);
			}

			bool		  operator==(const listIterator<T> &origin) const
			{
				return (now == origin.getnode());
			}

			bool		  operator!=(const listConstIterator<T> &origin) const
			{
				return (!operator==(origin));
			}

			bool		  operator!=(const listIterator<T> &origin) const
			{
				return (!operator==(origin));
			}

			//getter
			node<T>*		getnode(void) const
			{
				return (this->now);
			}
	};

	////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////// reverse iterator //////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////
	template <typename T>
	class listReverseIterator
	{
		private	:
			node<T> *now;
		public	:
			listReverseIterator(node<T> *now = NULL) : now(now)
			{
				
			}

			listReverseIterator(const listReverseIterator<T>& origin) : now(origin.now)
			{
				
			}

			listReverseIterator(const listIterator<T>& origin) : now(origin.getnode()->getPrev())
			{
				
			}

			listReverseIterator<T>& operator=(const listReverseIterator<T>& origin)
			{
				this->now = origin.now;
				return (*this);
			}

			listReverseIterator<T>& operator=(const listIterator<T>& origin)
			{
				this->now = origin.getnode()->getPrev();
				return (*this);
			}

			~listReverseIterator()
			{
				
			}

			//*
			T& operator*()
			{
				return (now->getValue());
			}

			//++ (전위)
			listReverseIterator<T>& operator++()
			{
				//미리 이동시키고 보낸다.
				this->now = this->now->getPrev();
				return (*this);
			}

			//++ (후위)
			//warning: reference to stack memory associated with local variable 'temp' returned [-Wreturn-stack-address
			//위는 레퍼런스를 보낼경우, 즉. temp 는 스택에 생성되기 떄문에 스택에서 생성된 변수의 레퍼런스를 보낼경우
			//워닝이 뜬다.
			listReverseIterator<T> operator++(int)
			{
				//리턴하고 이동시킨다.
				listReverseIterator<T> temp(*this);
				now = now->getPrev();
				return (temp);
			}

			//-- (전위)
			listReverseIterator<T>& operator--()
			{
				//미리 이동시키고 리턴.
				this->now = this->now->getNext();
				return (*this);
			}

			//-- (후위)
			listReverseIterator<T> operator--(int)
			{
				//리턴후 이동
				listReverseIterator<T> temp(*this);
				now = now->getNext();
				return (temp);
			}

			//->
			T*			  operator->()
			{
				return &(operator*());
			}

			bool		  operator==(const listReverseIterator<T> &origin) const
			{
				return (now == origin.now);
			}

			bool		  operator==(const listReverseConstIterator<T> &origin) const
			{
				return (now == origin.getnode());
			}

			bool		  operator!=(const listReverseIterator<T> &origin) const
			{
				return (!operator==(origin));
			}

			bool		  operator!=(const listReverseConstIterator<T> &origin) const
			{
				return (!operator==(origin));
			}

			//getter
			node<T>*		getnode(void) const
			{
				return (this->now);
			}

			listIterator<T>		base(void)
			{
				return (listIterator<T>(now->getNext()));
			}
	};

	template <typename T>
	class listReverseConstIterator
	{
		private	:
			node<T> *now;
		public	:
			listReverseConstIterator(node<T> *now = NULL) : now(now)
			{
				
			}

			listReverseConstIterator(const listReverseConstIterator<T>& origin) : now(origin.now)
			{
				
			}

			listReverseConstIterator(const listReverseIterator<T>& origin) : now(origin.getnode())
			{
				
			}

			listReverseConstIterator(const listConstIterator<T>& origin) : now(origin.getnode()->getPrev())
			{
				
			}

			listReverseConstIterator(const listIterator<T>& origin) : now(origin.getnode()->getPrev())
			{
				
			}

			listReverseConstIterator<T>& operator=(const listReverseIterator<T>& origin)
			{
				this->now = origin.getnode();
				return (*this);
			}

			listReverseConstIterator<T>& operator=(const listReverseConstIterator<T>& origin)
			{
				this->now = origin.now;
				return (*this);
			}

			listReverseConstIterator<T>& operator=(const listConstIterator<T>& origin)
			{
				this->now = origin.getnode()->getPrev();
				return (*this);
			}

			listReverseConstIterator<T>& operator=(const listIterator<T>& origin)
			{
				this->now = origin.getnode()->getPrev();
				return (*this);
			}

			~listReverseConstIterator()
			{
				
			}

			//*
			const T& operator*()
			{
				return (now->getValue());
			}

			//++ (전위)
			listReverseConstIterator<T>& operator++()
			{
				//미리 이동시키고 보낸다.
				this->now = this->now->getPrev();
				return (*this);
			}

			//++ (후위)
			//warning: reference to stack memory associated with local variable 'temp' returned [-Wreturn-stack-address
			//위는 레퍼런스를 보낼경우, 즉. temp 는 스택에 생성되기 떄문에 스택에서 생성된 변수의 레퍼런스를 보낼경우
			//워닝이 뜬다.
			listReverseConstIterator<T> operator++(int)
			{
				//리턴하고 이동시킨다.
				listReverseConstIterator<T> temp(*this);
				now = now->getPrev();
				return (temp);
			}

			//-- (전위)
			listReverseConstIterator<T>& operator--()
			{
				//미리 이동시키고 리턴.
				this->now = this->now->getNext();
				return (*this);
			}

			//-- (후위)
			listReverseConstIterator<T> operator--(int)
			{
				//리턴후 이동
				listReverseConstIterator<T> temp(*this);
				now = now->getNext();
				return (temp);
			}

			//->
			const T*			  operator->()
			{
				return &(operator*());
			}

			bool		  operator==(const listReverseConstIterator<T> &origin) const
			{
				return (now == origin.now);
			}

			bool		  operator==(const listReverseIterator<T> &origin) const
			{
				return (now == origin.getnode());
			}

			bool		  operator!=(const listReverseConstIterator<T> &origin) const
			{
				return (!operator==(origin));
			}

			bool		  operator!=(const listReverseIterator<T> &origin) const
			{
				return (!operator==(origin));
			}

			//getter
			node<T>*		getnode(void) const
			{
				return (this->now);
			}

			listConstIterator<T>		base(void) const
			{
				return (listConstIterator<T>(now->getNext()));
			}
	};


	////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////// reverse iterator //////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////
}

#endif