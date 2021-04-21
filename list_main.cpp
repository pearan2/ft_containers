/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:56:50 by honlee            #+#    #+#             */
/*   Updated: 2021/04/22 00:30:28 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"

int			main()
{
	ft::list<int> list;
	list.push_back(3);
	list.push_back(5);
	list.push_back(7);

	std::cout << list.front() <<std::endl;
	std::cout << list.back() <<std::endl;

}