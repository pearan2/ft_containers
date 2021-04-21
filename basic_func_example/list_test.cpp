/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:47:59 by honlee            #+#    #+#             */
/*   Updated: 2021/04/21 21:22:30 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <list>
#include <iostream>
#include <limits>
#include <cstddef>

int		main()
{
	std::list<int> list(3,5);
	for (std::list<int>::iterator iter = list.begin(); iter != list.end(); iter++ )
		std::cout << *iter << std::endl;	
}