/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:50:10 by honlee            #+#    #+#             */
/*   Updated: 2021/04/28 06:01:32 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BST.hpp"
#include <string>
#include <iostream>
#include "map_iterator.hpp"

#ifndef TEST_NS
# define TEST_NS ft
#endif

#ifndef TEST_TK
# define TEST_TK int
#endif

#ifndef TEST_TV
# define TEST_TV int
#endif


int			main()
{
	TEST_NS::node<TEST_TK, TEST_TV> *root = new TEST_NS::node<TEST_TK, TEST_TV>(5, 5);

	root->mergeInsert(root, 3, 3);
	root->mergeInsert(root, 7, 7);
	root->mergeInsert(root, 1, 1);
	root->mergeInsert(root, 123,123);
	root->mergeInsert(root, -13,-13);
	root->mergeInsert(root,4, 4);
	root->mergeInsert(root,-1,-1);

	TEST_NS::mapIterator<TEST_TK, TEST_TV> b_iter;
	TEST_NS::mapIterator<TEST_TK, TEST_TV> e_iter; 

	b_iter = TEST_NS::mapIterator<TEST_TK, TEST_TV>(root->getLeftest(root));
	e_iter = TEST_NS::mapIterator<TEST_TK, TEST_TV>(NULL);
	for (TEST_NS::mapIterator<TEST_TK, TEST_TV> iter = b_iter; iter != e_iter; iter++)
		std::cout << iter->first << "	|	" << iter->second << std::endl;
	
	root->deleteNode(&root, root, 5);
	

	b_iter = TEST_NS::mapIterator<TEST_TK, TEST_TV>(root->getLeftest(root));
	e_iter = TEST_NS::mapIterator<TEST_TK, TEST_TV>(NULL);
	for (TEST_NS::mapIterator<TEST_TK, TEST_TV> iter = b_iter; iter != e_iter; iter++)
		std::cout << iter->first << "	|	" << iter->second << std::endl;



	root->deleteNode(&root, root, 3);
	

	b_iter = TEST_NS::mapIterator<TEST_TK, TEST_TV>(root->getLeftest(root));
	e_iter = TEST_NS::mapIterator<TEST_TK, TEST_TV>(NULL);
	for (TEST_NS::mapIterator<TEST_TK, TEST_TV> iter = b_iter; iter != e_iter; iter++)
		std::cout << iter->first << "	|	" << iter->second << std::endl;


}