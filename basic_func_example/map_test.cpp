/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:35:28 by honlee            #+#    #+#             */
/*   Updated: 2021/04/27 22:16:21 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <map>

int		main()
{
	std::map<int, int> m;
	m[7] = 7;
	m[3] = 3;
	m[1] = 1;
	m[5] = 5;
	m[9] = 9;
	m[8] = 8;
	m[10] = 10;
	std::map<int, int>::iterator iter = m.begin();
	// iter++;
	// iter++;
	for (; iter != m.end(); iter++)
		std::cout << iter->second << " ";
	std::cout << std::endl;
}