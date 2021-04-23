/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:56:50 by honlee            #+#    #+#             */
/*   Updated: 2021/04/23 14:36:48 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <vector>
#include <iterator>

class test
{
	public:
		int x;
		int y;
		test()
		{
			
		}
		test(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
		~test()
		{
			//std::cout << "test class deleted :(" << std::endl;
		}
};

int			main()
{
	std::cout << "=========================== push_back test ============================" << std::endl;


	ft::list<int> list_push_back1;

	list_push_back1.push_back(1);
	list_push_back1.push_back(2);
	list_push_back1.push_back(3);
	list_push_back1.push_back(4);
	list_push_back1.push_back(5);

	for (ft::list<int>::iterator iter = list_push_back1.begin(); iter != list_push_back1.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
	std::cout << "list_push_back1 stores " << list_push_back1.size() << " numbers.\n";
	
	
	ft::list<test> list_push_back2;
	
	list_push_back2.push_back(test(3,5));
	list_push_back2.push_back(test(1,22));
	list_push_back2.push_back(test(2,33));
	list_push_back2.push_back(test(5,511));

	// std::cout << "=============" << std::endl;

	list_push_back2.clear();

	for (ft::list<test>::iterator iter = list_push_back2.begin(); iter != list_push_back2.end(); iter++)
		std::cout << iter->x << ", " << iter->y << " || ";
	std::cout << std::endl;
	
	std::cout << "list_push_back2 stores " << list_push_back2.size() << " numbers.\n";
	
	list_push_back2.push_back(test(3,5));
	list_push_back2.push_back(test(2,33));
	list_push_back2.push_back(test(5,511));
	
	for (ft::list<test>::iterator iter = list_push_back2.begin(); iter != list_push_back2.end(); iter++)
		std::cout << iter->x << ", " << iter->y << " || ";
	std::cout << std::endl;
	
	std::cout << "list_push_back2 stores " << list_push_back2.size() << " numbers.\n";
	

	std::cout << "=========================== push_back test end=========================" << std::endl;


	std::cout << "=========================== push_front test ===========================" << std::endl;

	ft::list<int> list_push_front1 (2,100);         // two ints with a value of 100
	list_push_front1.push_front (200);
	list_push_front1.push_front (300);

	std::cout << "mylist contains:";
	for (ft::list<int>::iterator it=list_push_front1.begin(); it!=list_push_front1.end(); ++it)
	  std::cout << ' ' << *it;

  	std::cout << '\n';

	std::cout << "list_push_front1 stores " << list_push_front1.size() << " numbers.\n";
	
	std::cout << "=========================== push_front test end========================" << std::endl;


	std::cout << "=========================== insert test ========================" << std::endl;

	ft::list<int> list_insert_test;
	ft::list<int>::iterator it_insert_test;

  // set some initial values:
	for (int i=1; i<=5; ++i) list_insert_test.push_back(i); // 1 2 3 4 5

	it_insert_test = list_insert_test.begin();
	++it_insert_test;       // it points now to number 2           ^

	list_insert_test.insert (it_insert_test,10);                        // 1 10 2 3 4 5

  // "it" still points to number 2                      ^
	list_insert_test.insert (it_insert_test,2,20);                      // 1 10 20 20 2 3 4 5

	--it_insert_test;       // it points now to the second 20            ^

	std::vector<int> vector_insert_test (2,30);
	list_insert_test.insert (it_insert_test,vector_insert_test.begin(),vector_insert_test.end());
                                                // 1 10 20 30 30 20 2 3 4 5
                                                //               ^



	it_insert_test = list_insert_test.begin();
	it_insert_test++;
	it_insert_test = list_insert_test.insert(it_insert_test, 778);
	std::cout << * it_insert_test << std::endl;


	std::cout << "mylist contains:";
	for (it_insert_test=list_insert_test.begin(); it_insert_test!=list_insert_test.end(); ++it_insert_test)
		std::cout << ' ' << *it_insert_test;
	std::cout << '\n';

	std::cout << "=========================== insert test end=====================" << std::endl;

	std::cout << "=========================== resize test ========================" << std::endl;

	ft::list<int> list_resize_test;

	// set some initial content:
	for (int i=1; i<10; ++i) list_resize_test.push_back(i);

	list_resize_test.resize(5);
	list_resize_test.resize(8,100);
	list_resize_test.resize(12);

  	std::cout << "list_resize_test contains:";
  	for (ft::list<int>::iterator it=list_resize_test.begin(); it!=list_resize_test.end(); ++it)
   	std::cout << ' ' << *it;

 	std::cout << '\n';

	std::cout << "=========================== resize test end=====================" << std::endl;

	std::cout << "=========================== splice test ========================" << std::endl;

	ft::list<int> list_splice_test1;

	list_splice_test1.push_back(2);
	list_splice_test1.push_back(3);
	list_splice_test1.push_back(4);

	ft::list<int>::iterator iter_splice_test1 = list_splice_test1.begin();
	iter_splice_test1++;
	
	ft::list<int> list_splice_test2;

	list_splice_test2.push_back(22);
	list_splice_test2.push_back(23);
	list_splice_test2.push_back(24);

	ft::list<int>::iterator iter_splice_test2 = list_splice_test2.begin();
	iter_splice_test2++;

	list_splice_test1.splice(iter_splice_test1, list_splice_test2, list_splice_test2.begin(), iter_splice_test2);
	
	list_splice_test1.insert(iter_splice_test1, 5);

	std::cout << "size : " <<list_splice_test1.size() << std::endl;



	for(ft::list<int>::iterator iter = list_splice_test1.begin(); iter != list_splice_test1.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;


	ft::list<int> list_splice_test3, list_splice_test4;
	ft::list<int>::iterator iter_splice_test3;

  // set some initial values:
	for (int i=1; i<=4; ++i)
	   list_splice_test3.push_back(i);      // list_splice_test3: 1 2 3 4
	for (int i=1; i<=3; ++i)
	   list_splice_test4.push_back(i*10);   // list_splice_test4: 10 20 30

	iter_splice_test3 = list_splice_test3.begin();
	++iter_splice_test3;                         // points to 2
	list_splice_test3.splice (iter_splice_test3, list_splice_test4); // list_splice_test3: 1 10 20 30 2 3 4
	                              // list_splice_test4 (empty)
	                              // "it" still points to 2 (the 5th element)
	
	list_splice_test4.splice (list_splice_test4.begin(),list_splice_test3, iter_splice_test3);
	                              // list_splice_test3: 1 10 20 30 3 4
	                              // list_splice_test4: 2
	                              // "it" is now invalid.
	iter_splice_test3 = list_splice_test3.begin();

	iter_splice_test3++;
	iter_splice_test3++;
	iter_splice_test3++;       // "it" points now to 30
	list_splice_test3.splice ( list_splice_test3.begin(), list_splice_test3, iter_splice_test3, list_splice_test3.end());
	                              // list_splice_test3: 30 3 4 1 10 20
	std::cout << "list_splice_test3 contains:";
	for (iter_splice_test3=list_splice_test3.begin(); iter_splice_test3!=list_splice_test3.end(); ++iter_splice_test3)
	  std::cout << ' ' << *iter_splice_test3;
	std::cout << '\n';
	std::cout << "list_splice_test4 contains:";
	for (iter_splice_test3=list_splice_test4.begin(); iter_splice_test3!=list_splice_test4.end(); ++iter_splice_test3)
	  std::cout << ' ' << *iter_splice_test3;
	std::cout << '\n';

	std::cout << "=========================== splice test end=====================" << std::endl;

	return 0;

}