/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:07:41 by honlee            #+#    #+#             */
/*   Updated: 2021/04/28 05:19:10 by honlee           ###   ########.fr       */
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
			pair(){}

		public	:
			TK			first;
			TV			second;

			pair(const TK& first, const TV& second) : first(first), second(second)
			{
				
			}
			pair(const pair<TK, TV>& origin) : first(origin.first), second(origin.second)
			{
				
			}
			pair<TK, TV>& operator=(const pair<TK, TV>& origin)
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

			node(){}
			node<TK, TV>& operator=(const node<TK, TV>& origin)
			{
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
				if (left == NULL)
					parent->childChange(this, right);
				else
					parent->childChange(this, left);
			}

		public	:
			const TK	first;
			TV			second;
			node(TK first, TV second) : parent(NULL), left(NULL), right(NULL), first(first), second(second)
			{
				
			}
			node(const pair<TK, TV>& pair) : parent(NULL), left(NULL), right(NULL), first(pair.first), second(pair.second)
			{
				
			}

			node(const node<TK, TV>& origin) : parent(origin.parent), left(origin.left), right(origin.right), first(origin.first), second(origin.second)
			{
				
			}
			~node()
			{
				std::cout << first << " | " << second << "   valued node destroyed :(" << std::endl;
			}

			//tk 가 이미 존재하는 키라면 해당 키의 벨류를 tv 로 변경.
			//tk 가 존재하지 않는다면 만들어 집어넣음
			//따라서 이것으로 search 까지 대신할 수 있다. (변경되거나 만들었으면 해당 노드의 포인터를 리턴하기 때문)
			node<TK, TV>* mergeInsert(node<TK, TV> *root, const TK& tk, const TV& tv = TV())
			{
				node<TK, TV>* child;

				if ((cmp(root->first, tk) == false) && (cmp(tk, root->first) == false))
				{
					root->second = tv;
					return (root);
				}
				
				if ( cmp(root->first, tk) ) // 오른쪽으로 가야한다.
				{
					if (root->right == NULL) // 오른쪽이 비어있다면 넣는다.
					{
						child = new node<TK, TV>(tk, tv);
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
						child = new node<TK, TV>(tk, tv);
						root->left = child;
						child->parent = root;
						return (child);
					}
					return (mergeInsert(root->left, tk, tv));
				}
			}

			node<TK, TV>* getLeftest(node<TK, TV> *root)
			{
				if (root->left == NULL)
					return (root);
				return (getLeftest(root->left));
			}

			node<TK, TV>* getRightest(node<TK, TV> *root)
			{
				if (root->right == NULL)
					return (root);
				return (getRightest(root->right));
			}

			//여기서 tk 는 반드시 존재한다.
			void deleteNode(node<TK, TV>**real_root, node<TK, TV> *root, const TK& tk)
			{
				node<TK, TV> *newRoot;

				if ((cmp(root->first, tk) == false) && (cmp(tk, root->first) == false))
				{
					if (root->left != NULL)
					{
						newRoot = getRightest(root->left);
						newRoot->makeParentChildToMyChild(); // 부모와 자신자식의 라인을 이어준다. (이떄 newRoot 는 반드시 자식이 하나이므로 반드시 연결된다.)
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
				if (cmp(root->first, tk) == false)
					deleteNode(real_root, root->left, tk);
				else if (cmp(root->first, tk))
					deleteNode(real_root, root->right, tk);
			}

			//getter
			node<TK, TV>*		getLeft()
			{
				return (this->left);
			}

			node<TK, TV>*		getRight()
			{
				return (this->right);
			}

			node<TK, TV>*		getParent()
			{
				return (this->parent);
			}
	};
}

#endif