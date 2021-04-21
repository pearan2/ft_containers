/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:47:59 by honlee            #+#    #+#             */
/*   Updated: 2021/04/22 00:25:36 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <list>
#include <iostream>
#include <limits>
#include <cstddef>

int		main()
{
	std::list<int> list;
	std::cout << list.size() << std::endl;

	list.front() =5;
	std::cout << list.front() << std::endl;
	std::cout << list.size() << std::endl;

	// std::list<int> list(3,5);
	// list.front() = 4;

	for (std::list<int>::iterator iter = list.begin(); iter != list.end(); iter++ )
		std::cout << *iter << std::endl;	
}