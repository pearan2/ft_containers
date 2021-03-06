/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:07:41 by honlee            #+#    #+#             */
/*   Updated: 2021/05/01 09:55:44 by honlee           ###   ########seoul.kr  */
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
				
				if ( cmp(root->ip.first, tk) ) // ??????????????? ????????????.
				{
					if (root->right == NULL) // ???????????? ??????????????? ?????????.
						return (NULL);
					return (find(root->right, tk));
				}
				else		// ???????????? ????????????.
				{
					if (root->left == NULL)
						return (NULL);
					return (find(root->left, tk));
				}
			}

			//tk ??? ?????? ???????????? ????????? ?????? ?????? ????????? tv ??? ??????.
			//tk ??? ???????????? ???????????? ????????? ????????????
			node<TK, TV, Compare>* mergeInsert(node<TK, TV, Compare> *root, const TK& tk, const TV& tv = TV())
			{
				node<TK, TV, Compare>* child;

				if ((cmp(root->ip.first, tk) == false) && (cmp(tk, root->ip.first) == false))
				{
					root->ip.second = tv;
					return (root);
				}
				
				if ( cmp(root->ip.first, tk) ) // ??????????????? ????????????.
				{
					if (root->right == NULL) // ???????????? ??????????????? ?????????.
					{
						child = new node<TK, TV, Compare>(tk, tv);
						root->right = child;
						child->parent = root;
						return (child);
					}
					return (mergeInsert(root->right, tk, tv));
				}
				else		// ???????????? ????????????.
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

			//key ?????? ????????? ?????? ?????? ???
			node<TK, TV, Compare>* getUpperBound(node<TK, TV, Compare> *root, const TK& key)
			{		
				if (isFirstEqualOrSmall(root->ip.first, key)) // key ??? ??? ??? -> ???????????? ????????? ?????????.
				{
					if (root->right == NULL)
						return (NULL);
					else 
						return (getUpperBound(root->right, key));
				}
				else // key ??? ??? ??????.
				{
					if (root->left == NULL)
						return (root);
					else
						return (getUpperBound(root->left, key));
				}
			}

			//key ?????? ????????? ?????? ????????? ?????? ???
			node<TK, TV, Compare>* getLowerBound(node<TK, TV, Compare> *root, const TK& key)
			{
				if (isSame(root->ip.first, key)) // ?????? ????????? ?????? ??????
					return (root);
				
				if (isFirstSmall(root->ip.first, key)) // key ??? ??? ??? -> ???????????? ????????? ?????????.
				{
					if (root->right == NULL)
						return (NULL);
					else 
						return (getLowerBound(root->right, key));
				}
				else // key ??? ??? ??????.
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

			//????????? tk ??? ????????? ????????????. // ?????? ???????????? ?????? tk ??? ??????????????? UB ??????..?
			void deleteNode(node<TK, TV, Compare>**real_root, node<TK, TV, Compare> *root, const TK& tk)
			{
				node<TK, TV, Compare> *newRoot;

				if ((cmp(root->ip.first, tk) == false) && (cmp(tk, root->ip.first) == false))
				{
					if (root->left != NULL)
					{
						newRoot = getRightest(root->left);
						newRoot->makeParentChildToMyChild(); // ????????? ??????????????? ????????? ????????????. (?????? newRoot ??? ????????? ????????? ??????????????? ????????? ????????????.)
						
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
						newRoot->makeParentChildToMyChild(); // ????????? ??????????????? ????????? ????????????. (?????? newRoot ??? ????????? ????????? ??????????????? ????????? ????????????.)
						
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
					else // ?????? ?????? ?????? ??????. (????????? ????????? ???????????????. ????????? ???????????? ??????)
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

	template <typename TK, typename TV, class Compare = ft::less<TK> >
	class saver
	{
		public	:
			node<TK, TV, Compare>* root;
		
			saver(node<TK, TV, Compare>* root = NULL) : root(root){}
			~saver(){}
			saver(const saver<TK, TV, Compare>& origin) : root(origin.root){}
			saver& operator=(const saver<TK, TV, Compare>& origin)
			{
				this->root = origin.root;
				return (*this);
			}
	};
}

#endif