/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:07:41 by honlee            #+#    #+#             */
/*   Updated: 2021/04/29 23:59:48 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP

# include <iostream>
# include <string>
# include "utils.hpp"
namespace ft
{
	template <typename TK, typename TV>
	class pair
	{
		private	:

		public	:
			TK			first;
			TV			second;

			pair(){}

						
			pair(const TK& first, const TV& second) : first(first), second(second)
			{
				
			}

			pair(const pair<TK, TV>& origin) : first(origin.first), second(origin.second)
			{
				
			}
			
			// pair<int ,int> <=> pair<const int, int>
			template <typename CTK, typename CTV>
			pair(const pair<CTK, CTV>& origin) : first(origin.first), second(origin.second)
			{
				
			}

			pair<TK, TV>& operator=(const pair<TK, TV>& origin)
			{
				first = origin.first;
				second = origin.second;
				return (*this);
			}
			
			template <typename CTK, typename CTV>
			pair<TK, TV>& operator=(const pair<CTK, CTV>& origin)
			{
				first = origin.first;
				second = origin.second;
				return (*this);
			}

			~pair()
			{
				
			}
	};

	template <typename TK, typename TV, class Compare = ft::less<TK> >
	class node
	{
		private :
			node*	parent;
			node*	left;
			node*	right;
			Compare cmp;
			
			node<TK, TV, Compare>& operator=(const node<TK, TV, Compare>& origin)
			{
				delete (parent);
				parent = new node<TK, TV, Compare>(origin.parent);
				delete (left);
				left = new node<TK, TV, Compare>(origin.left);
				delete (right);
				right = new node<TK, TV, Compare>(origin.right);

				ip = origin.ip;

				return (*this);
			}
			void childChange(node *from, node *to)
			{
				if (left == from)
					left = to;
				if (right == from)
					right = to;
			}

			void makeParentChildToMyChild()
			{
				if (parent == NULL)
					return ;
				if (left == NULL)
					parent->childChange(this, right);
				else
					parent->childChange(this, left);
			}

			bool isFirstSmall(const TK& t1, const TK& t2)
			{
				return (cmp(t1, t2));
			}

			bool isFirstEqualOrSmall(const TK& t1, const TK& t2)
			{
				return (!cmp(t2, t1));
			}

			bool isSame(const TK& t1, const TK& t2)
			{
				return ( (!cmp(t1, t2)) && (!cmp(t2, t1)) );
			}

		public	:
			pair<const TK, TV>	ip;

			node() : parent(NULL), left(NULL), right(NULL)
			{

			}

			node(TK first, TV second = TV()) : parent(NULL), left(NULL), right(NULL), ip(first, second)
			{
				
			}
			node(const pair<TK, TV>& pair) : parent(NULL), left(NULL), right(NULL), ip(pair)
			{
				
			}
			//deep copy
			node(const node<TK, TV, Compare>& origin, node<TK, TV, Compare>* parent = NULL) : parent(parent), left(NULL), right(NULL), ip(origin.ip)
			{
				if (origin.left != NULL)
					left = new node<TK, TV, Compare>(*origin.left, this);
				if (origin.right != NULL)
					right = new node<TK, TV, Compare>(*origin.right, this);				
			}

			~node()
			{
				
			}

			node<TK, TV, Compare>* getRoot(node<TK, TV, Compare>* root)
			{
				if (root->parent == NULL)
					return (root);
				return (getRoot(root->parent));
			}

			void deleteAll(node<TK, TV, Compare>* root)
			{
				if (root == NULL)
					return ;
				if (root->left != NULL)
					deleteAll(root->left);
				if (root->right != NULL)
					deleteAll(root->right);
				delete(root);				
			}

			node<TK, TV, Compare>* find(node<TK, TV, Compare> *root, const TK& tk)
			{
				if ((cmp(root->ip.first, tk) == false) && (cmp(tk, root->ip.first) == false))
					return (root);
				
				if ( cmp(root->ip.first, tk) ) // 오른쪽으로 가야한다.
				{
					if (root->right == NULL) // 오른쪽이 비어있다면 넣는다.
						return (NULL);
					return (find(root->right, tk));
				}
				else		// 왼쪽으로 가야한다.
				{
					if (root->left == NULL)
						return (NULL);
					return (find(root->left, tk));
				}
			}

			//tk 가 이미 존재하는 키라면 해당 키의 벨류를 tv 로 변경.
			//tk 가 존재하지 않는다면 만들어 집어넣음
			node<TK, TV, Compare>* mergeInsert(node<TK, TV, Compare> *root, const TK& tk, const TV& tv = TV())
			{
				node<TK, TV, Compare>* child;

				if ((cmp(root->ip.first, tk) == false) && (cmp(tk, root->ip.first) == false))
				{
					root->ip.second = tv;
					return (root);
				}
				
				if ( cmp(root->ip.first, tk) ) // 오른쪽으로 가야한다.
				{
					if (root->right == NULL) // 오른쪽이 비어있다면 넣는다.
					{
						child = new node<TK, TV, Compare>(tk, tv);
						root->right = child;
						child->parent = root;
						return (child);
					}
					return (mergeInsert(root->right, tk, tv));
				}
				else		// 왼쪽으로 가야한다.
				{
					if (root->left == NULL)
					{
						child = new node<TK, TV, Compare>(tk, tv);
						root->left = child;
						child->parent = root;
						return (child);
					}
					return (mergeInsert(root->left, tk, tv));
				}
			}

			//key 보다 큰값중 가장 작은 값
			node<TK, TV, Compare>* getUpperBound(node<TK, TV, Compare> *root, const TK& key)
			{		
				if (isFirstEqualOrSmall(root->ip.first, key)) // key 가 더 큼 -> 더큰놈을 찾으러 가야함.
				{
					if (root->right == NULL)
						return (NULL);
					else 
						return (getUpperBound(root->right, key));
				}
				else // key 가 더 작음.
				{
					if (root->left == NULL)
						return (root);
					else
						return (getUpperBound(root->left, key));
				}
			}

			//key 보다 큰값중 가장 작거나 같은 값
			node<TK, TV, Compare>* getLowerBound(node<TK, TV, Compare> *root, const TK& key)
			{
				if (isSame(root->ip.first, key)) // 값이 같다면 즉시 리턴
					return (root);
				
				if (isFirstSmall(root->ip.first, key)) // key 가 더 큼 -> 더큰놈을 찾으러 가야함.
				{
					if (root->right == NULL)
						return (NULL);
					else 
						return (getLowerBound(root->right, key));
				}
				else // key 가 더 작음.
				{
					if (root->left == NULL)
						return (root);
					else
						return (getLowerBound(root->left, key));
				}
			}

			node<TK, TV, Compare>* getLeftest(node<TK, TV, Compare> *root)
			{
				if (root == NULL || root->left == NULL)
					return (root);
				return (getLeftest(root->left));
			}

			node<TK, TV, Compare>* getRightest(node<TK, TV, Compare> *root)
			{
				if (root == NULL || root->right == NULL)
					return (root);
				return (getRightest(root->right));
			}

			//여기서 tk 는 반드시 존재한다. // 만약 존재하지 않는 tk 가 들어온다면 UB 이다..?
			void deleteNode(node<TK, TV, Compare>**real_root, node<TK, TV, Compare> *root, const TK& tk)
			{
				node<TK, TV, Compare> *newRoot;

				if ((cmp(root->ip.first, tk) == false) && (cmp(tk, root->ip.first) == false))
				{
					if (root->left != NULL)
					{
						newRoot = getRightest(root->left);
						newRoot->makeParentChildToMyChild(); // 부모와 자신자식의 라인을 이어준다. (이떄 newRoot 는 반드시 자식이 하나이므로 반드시 연결된다.)
						
						////////////
						if (newRoot->left != NULL)
							newRoot->left->parent = newRoot->parent;
						if (newRoot->right != NULL)
							newRoot->right->parent = newRoot->parent;
						///////////
						
						newRoot->left = root->left;
						newRoot->right = root->right;
						newRoot->parent = root->parent;
						if (root->parent != NULL)
							root->parent->childChange(root, newRoot);
						if (root->left != NULL)
							root->left->parent = newRoot;
						if (root->right != NULL)
							root->right->parent = newRoot;
						if (root == *real_root)
							*real_root = newRoot;
						delete (root);
					}
					else if (root->right != NULL)
					{
						newRoot = getLeftest(root->right);
						newRoot->makeParentChildToMyChild(); // 부모와 자신자식의 라인을 이어준다. (이떄 newRoot 는 반드시 자식이 하나이므로 반드시 연결된다.)
						
						////////////
						if (newRoot->left != NULL)
							newRoot->left->parent = newRoot->parent;
						if (newRoot->right != NULL)
							newRoot->right->parent = newRoot->parent;
						///////////
						
						newRoot->left = root->left;
						newRoot->right = root->right;
						newRoot->parent = root->parent;
						if (root->parent != NULL)
							root->parent->childChange(root, newRoot);
						if (root->left != NULL)
							root->left->parent = newRoot;
						if (root->right != NULL)
							root->right->parent = newRoot;
						if (root == *real_root)
							*real_root = newRoot;
						delete (root);
					}
					else // 양쪽 자식 모두 없다. (부모쪽 링크만 없애주면됨. 아래에 아무것도 없다)
					{
						root->makeParentChildToMyChild();
						delete root;
					}
					return ;
				}
				if (cmp(root->ip.first, tk) == false)
					deleteNode(real_root, root->left, tk);
				else if (cmp(root->ip.first, tk))
					deleteNode(real_root, root->right, tk);
			}

			//getter
			node<TK, TV, Compare>*		getLeft()
			{
				return (this->left);
			}

			node<TK, TV, Compare>*		getRight()
			{
				return (this->right);
			}

			node<TK, TV, Compare>*		getParent()
			{
				return (this->parent);
			}
	};
}

#endif