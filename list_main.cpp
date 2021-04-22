/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:56:50 by honlee            #+#    #+#             */
/*   Updated: 2021/04/22 13:52:12 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"

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

	std::cout << "==================== pop_back test =================" << std::endl;
 

	ft::List<int> mylist;
	int sum (0);
	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);

	while (!mylist.empty())
	{
	  sum+=mylist.back();
	  mylist.pop_back();
	}
	std::cout << "The elements of mylist summed " << sum << '\n';
	std::cout << "size >> " << mylist.size() << std::endl;

	std::cout << "==================== pop_back test =================" << std::endl;
 
	return 0;

}