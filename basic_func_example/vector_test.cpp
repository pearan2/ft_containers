/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 22:48:29 by honlee            #+#    #+#             */
/*   Updated: 2021/04/27 17:51:42 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <iostream>


int			main()
{
	std::vector<int> vec;
	vec.push_back(1);
	
	std::vector<int>::iterator iter = vec.begin(); // old begin set

	for (int i=0; i<100; i++)
		vec.push_back(i);

	for (; iter != vec.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}