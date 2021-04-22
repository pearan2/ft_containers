/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:47:59 by honlee            #+#    #+#             */
/*   Updated: 2021/04/22 16:12:06 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <list>
#include <iostream>
#include <limits>
#include <cstddef>

class test
{
	public:
		int x;
		int y;
		test(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
};

int		main()
{
	// std::list<int> list;
	// std::cout << list.size() << std::endl;
	
	// for (int i = 0; i<5; i++)
	// 	list.push_back(i);

	// for (std::list<int>::reverse_iterator iter = list.rbegin(); iter != list.rend(); iter++)
	// 	std::cout << *iter << std::endl;
	// std::list<int>::iterator iter = list.begin();
	// std::list<int>::reverse_iterator rev_iter = list.rbegin();
	// std::list<int>::iterator *iter_ptr = &iter;

	// std::cout << *(++iter) << std::endl;
	// std::cout << *(rev_iter.operator+=(2)) << std::endl;

	// iter--;
	// std::cout << *iter << std::endl;
	// iter--;
	// std::cout << *iter << std::endl;

	std::list<test> list_test;
	list_test.push_back(test(3,5));
	list_test.push_back(test(1,7));
	list_test.push_back(test(4,4));

	for (std::list<test>::iterator iter = list_test.begin(); iter != list_test.end(); iter++)
	{
		//std::cout << *iter << std::endl;
		std::cout << "x : " << iter->x << " | y : " << iter->y << std::endl;
	}
	std::list<test>::iterator iter;
}