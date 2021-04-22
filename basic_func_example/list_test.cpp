/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:47:59 by honlee            #+#    #+#             */
/*   Updated: 2021/04/22 13:45:09 by honlee           ###   ########.fr       */
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
	list.pop_back();
	//list.pop_front();
}