/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:56:50 by honlee            #+#    #+#             */
/*   Updated: 2021/04/23 00:29:51 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
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
};


int			main()
{
	// ft::List<int> list;
	// std::cout << "size : " << list.size() << std::endl;
	// std::cout << "empty : " << list.empty() << std::endl;
	// list.push_back(3);
	// list.push_back(5);
	// list.push_back(7);


	// std::cout << list.front() <<std::endl;
	// std::cout << list.back() <<std::endl;

	// std::cout << list.max_size() << std::endl;
	// std::cout << "size : " << list.size() << std::endl;
	// std::cout << "empty : " << list.empty() << std::endl;

	// list.clear();
	// std::cout << "size : " << list.size() << std::endl;
	// std::cout << "empty : " << list.empty() << std::endl;


	// std::cout << "==================== assign test ====================" << std::endl;
  	// std::list<int> list_real;
  	// ft::List<int> list_my;

  	// list_real.assign(7,100);                      // 7 ints with value 100
	// list_my.assign(1,3);
	// std::cout << list_my.front() << std::endl;
	// std::cout << list_my.back() << std::endl;
	// std::cout << "size : " << list_my.size() << std::endl;

	// list_my.assign(list_real.begin(), list_real.end());
	// std::cout << list_my.front() << std::endl;
	// std::cout << list_my.back() << std::endl;
	// std::cout << "size : " << list_my.size() << std::endl;
	

  	// int myints[]={1776,7,4};
  	// list_my.assign (myints,myints+3);            // assigning from array
	// std::cout << list_my.front() << std::endl;
	// std::cout << list_my.back() << std::endl;
	// std::cout << "size : " << list_my.size() << std::endl;

  	// std::cout << "Size of real: " << int (list_real.size()) << '\n';
  	// std::cout << "Size of my: " << int (list_my.size()) << '\n';
 
	// std::cout << "==================== assign test end=================" << std::endl;
  	

	// std::cout << "==================== pop_front test =================" << std::endl;
  	// ft::List<int> mylist;
  	// mylist.push_back (100);
  	// mylist.push_back (200);
  	// mylist.push_back (300);

  	// std::cout << "Popping out the elements in mylist:";
  	// while (!mylist.empty())
  	// {
  	//   std::cout << ' ' << mylist.front();
  	//   mylist.pop_front();
  	// }

  	// std::cout << "\nFinal size of mylist is " << mylist.size() << '\n';
	// std::cout << "==================== pop_front test end==============" << std::endl;

	// std::cout << "==================== pop_back test =================" << std::endl;
 

	// ft::List<int> mylist;
	// int sum (0);
	// mylist.push_back (100);
	// mylist.push_back (200);
	// mylist.push_back (300);

	// while (!mylist.empty())
	// {
	//   sum+=mylist.back();
	//   mylist.pop_back();
	// }
	// std::cout << "The elements of mylist summed " << sum << '\n';
	// std::cout << "size >> " << mylist.size() << std::endl;

	// std::cout << "==================== pop_back test =================" << std::endl;
 

	// std::cout << "==================== pop_front test =================" << std::endl;
 
	// ft::List<int> mylist (2,100);         // two ints with a value of 100
	// mylist.push_front (200);
	// mylist.push_front (300);
	
	// std::cout << "mylist contains:" << std::endl;
	// std::cout << mylist.front() << std::endl;
	// std::cout << mylist.back() << std::endl;
	// std::cout << mylist.size() << std::endl;
 
	// std::cout << "==================== pop_front test end =============" << std::endl;
 

	// std::cout << "==================== Iterator test start =============" << std::endl;
 
	// ft::List<test> list_test;
	// list_test.push_back(test(3,5));
	// list_test.push_back(test(1,7));
	// list_test.push_back(test(4,4));

	// for (ft::List<test>::iterator iter = list_test.begin(); iter != list_test.end(); iter++)
	// {
	// 	//std::cout << *iter << std::endl;
	// 	std::cout << "x : " << iter->x << " | y : " << iter->y << std::endl;
	// }
	// //ft::List<test>::iterator iter();
 

	// ft::List<double> list_double;
	// list_double.push_back(3.5);
	// list_double.push_back(3.4);
	// list_double.push_back(3.3);
	// list_double.push_back(3.2);

	// for (ft::List<double>::iterator iter = list_double.begin(); iter != list_double.end(); iter++)
	// 	std::cout << *iter << std::endl;

 	// std::cout << "==================== Iterator test end ===============" << std::endl;
 
	// for (ft::List<double>::reverse_iterator riter = list_double.rbegin(); riter != list_double.rend(); riter++)
	// 	std::cout << *riter << std::endl;

	
	// std::cout << "=================== insert test ======================" << std::endl;

	ft::List<int> list;
	list.insert(list.end(), 5);
	list.insert(list.end(), 4);
	list.insert(list.end(), 3);
	for (ft::List<int>::iterator iter = list.begin(); iter != list.end(); iter ++)
		std::cout << *iter << " ";
	std::cout << std::endl;

	ft::List<int> mylist;
	ft::List<int>::iterator it;

	// set some initial values:
	for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5

	it = mylist.begin();
	++it;       // it points now to number 2           ^

	mylist.insert (it,10);                        // 1 10 2 3 4 5

	// "it" still points to number 2                      ^
	mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5

	--it;       // it points now to the second 20            ^

	std::vector<int> myvector (2,30);
	mylist.insert (it,myvector.begin(),myvector.end());
                                                // 1 10 20 30 30 20 2 3 4 5
                                                //               ^
	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "size : " << mylist.size() << std::endl;

	// std::cout << "=================== insert test ======================" << std::endl;

	// std::cout << "=================== erase test ======================" << std::endl;

  	// ft::List<int> mylist;
  	// ft::List<int>::iterator it1,it2,it3;

  	// // set some values:
  	// for (int i=1; i<10; ++i) mylist.push_back(i*10);

  	//                             // 10 20 30 40 50 60 70 80 90
  	// it1 = it2 = mylist.begin(); // ^^
	// it2++;
	// it2++;
	// it2++;
	// it2++;
	// it2++;
	// it2++;

  	// ++it1;                      //    ^              ^



  	// it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
  	//                             //    ^           ^
	
	// std::cout << *it2 << std::endl;
	// it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
  	//                             //    ^           ^

  	// ++it1;                      //       ^        ^
  	// --it2;                      //       ^     ^

  	// mylist.erase (it1,it2);     // 10 30 60 80 90
  	//                             //        ^

	// it3 = mylist.erase(mylist.begin());
	// mylist.erase(it3);
	// //mylist.erase(mylist.end());

  	// std::cout << "mylist contains:";
  	// for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
  	//   std::cout << ' ' << *it1;
  	// std::cout << '\n';

	// std::cout << "=================== erase test end===================" << std::endl;

	// std::cout << "=================== swap test ======================" << std::endl;

	// ft::List<int> first (3,100);   // three ints with a value of 100
	// ft::List<int> second (5,200);  // five ints with a value of 200

	// first.swap(second);
	// std::cout << "first contains:";

	// for (ft::List<int>::iterator it=first.begin(); it!=first.end(); it++)
	//   std::cout << ' ' << *it;
	// std::cout << '\n';
	// std::cout << "second contains:";

	// for (ft::List<int>::iterator it=second.begin(); it!=second.end(); it++)
	//   std::cout << ' ' << *it;
	// std::cout << '\n';

	// std::cout << "=================== erase test end===================" << std::endl;

	// std::cout << "=================== resize test ======================" << std::endl;
	// ft::List<int> mylist;
	// 	// set some initial content:
	// for (int i=1; i<10; ++i) mylist.push_back(i);
	
	// mylist.resize(5);
	// mylist.resize(8,100);
	// mylist.resize(12);
	// 	std::cout << "mylist contains:";
	// for (ft::List<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
	//   std::cout << ' ' << *it;
	// 	std::cout << '\n';

	// std::cout << "=================== resize test end===================" << std::endl;
	

	return 0;



}