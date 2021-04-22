/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:47:59 by honlee            #+#    #+#             */
/*   Updated: 2021/04/23 00:25:37 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <list>
#include <iostream>
#include <limits>
#include <cstddef>
#include <vector>

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
		~test()
		{
			std::cout << "test class destroyed :(" << std::endl;
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

	// std::list<test> list_test;
	// list_test.push_back(test(3,5));
	// list_test.push_back(test(1,7));
	// list_test.push_back(test(4,4));

	// for (std::list<test>::iterator iter = list_test.begin(); iter != list_test.end(); iter++)
	// {
	// 	//std::cout << *iter << std::endl;
	// 	std::cout << "x : " << iter->x << " | y : " << iter->y << std::endl;
	// }
	// std::list<test>::iterator iter = list_test.begin();

	// std::list<double> list_double;
	
	// list_double.push_back(1.1);
	// list_double.push_back(1.2);
	// list_double.push_back(2.3);

	// std::list<double>::iterator iter_double = list_double.begin();

	// std::cout << *iter_double << std::endl;
	// iter_double--;
	// std::cout << *iter_double << std::endl;
	// iter_double--;
	// std::cout << *iter_double << std::endl;

	// std::cout << "===========================" << std::endl;
	// iter_double++;
	// std::cout << *iter_double << std::endl;
	// iter_double++;
	// std::cout << *iter_double << std::endl;
	// iter_double++;
	// std::cout << *iter_double << std::endl;
	// iter_double++;
	// std::cout << *iter_double << std::endl;

	// std::cout << "===========================" << std::endl;
  	// std::vector<int> myvector;
 	// for (int i=0; i<10; i++) myvector.push_back(i);  // myvector: 0 1 2 3 4 5 6 7 8 9

 	// typedef std::vector<int>::iterator iter_type;

  	// std::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

	// std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';


	// std::list<int> list_int;
	// list_int.push_back(10);
	// list_int.push_back(15);
	// list_int.push_back(20);
	// list_int.push_back(25);

	// for (std::list<int>::iterator iter = list_int.begin(); iter!= list_int.end(); iter++)
	// 	std::cout << *iter << " ";
	// std::cout << std::endl;

	// std::list<int>::iterator iter_begin = list_int.begin();
	// std::list<int>::iterator iter_begin_2 = iter_begin;
	// iter_begin_2++;
	// iter_begin_2++;
	

	// std::list<int>::iterator iter_ret = list_int.erase(iter_begin, iter_begin_2);
	// std::cout << *iter_ret << std::endl;


	// for (std::list<int>::iterator iter = list_int.begin(); iter!= list_int.end(); iter++)
	// 	std::cout << *iter << " ";
	// std::cout << std::endl;
  	// return 0;

	// std::list<test> list_test;
	// list_test.push_back(test(1,2));
	// list_test.erase(list_test.begin());

	std::list<int> list;
	list.insert(list.end(), 5);
	list.insert(list.end(), 4);
	list.insert(list.end(), 3);
	for (std::list<int>::iterator iter = list.begin(); iter != list.end(); iter ++)
		std::cout << *iter << " ";
	std::cout << std::endl;


	std::list<int> list1;
	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);
	list1.push_back(4);

	std::list<int> list2;
	list2.push_back(77);
	list2.push_back(66);
	std::list<int>::iterator it_2 = list2.begin();

	list2.splice(list2.end(), list1);
	for (std::list<int>::iterator iter = list1.begin(); iter != list1.end(); iter ++)
		std::cout << *iter << " ";
	std::cout << std::endl;

	for (std::list<int>::iterator iter = list2.begin(); iter != list2.end(); iter ++)
		std::cout << *iter << " ";
	std::cout << std::endl;

	std::cout << list1.size() << std::endl;
	std::cout << list2.size() << std::endl;

}