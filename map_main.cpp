/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:50:10 by honlee            #+#    #+#             */
/*   Updated: 2021/04/28 14:11:18 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BST.hpp"
#include <string>
#include <iostream>

#ifndef TEST_NS
# define TEST_NS ft
#endif

#ifndef TEST_TK
# define TEST_TK int
#endif

#ifndef TEST_TV
# define TEST_TV int
#endif

// 중위순회
void		show(TEST_NS::node<TEST_TK, TEST_TV>* root)
{
	if (root == NULL)
		return ;
	show(root->getLeft());
	std::cout << root->first << "	|	" << root->second << std::endl;
	show(root->getRight());
}

int			main()
{
	
}