/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:50:10 by honlee            #+#    #+#             */
/*   Updated: 2021/04/29 14:05:55 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BST.hpp"
#include <string>
#include <iostream>
#include "map_iterator.hpp"
#include <map>
#include "map.hpp"

#ifndef TEST_NS
# define TEST_NS ft
#endif

#ifndef TEST_TK
# define TEST_TK char
#endif

#ifndef TEST_TV
# define TEST_TV int
#endif


TEST_TV			main()
{
	std::cout << "==================== insert test ===========================" << std::endl;

	TEST_NS::map<TEST_TK,TEST_TV> map_insert1;

	// first insert function version (single parameter):
	map_insert1.insert ( TEST_NS::pair<TEST_TK,TEST_TV>('a',100) );
	map_insert1.insert ( TEST_NS::pair<TEST_TK,TEST_TV>('z',200) );

	TEST_NS::pair<TEST_NS::map<TEST_TK,TEST_TV>::iterator,bool> ret_insert1;
	ret_insert1 = map_insert1.insert ( TEST_NS::pair<TEST_TK,TEST_TV>('z',500) );
	if (ret_insert1.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret_insert1.first->second << '\n';
	}

	// second insert function version (with hTEST_TV position):
	TEST_NS::map<TEST_TK,TEST_TV>::iterator it = map_insert1.begin();
	map_insert1.insert (it, TEST_NS::pair<TEST_TK,TEST_TV>('b',300));	// max efficiency inserting
	map_insert1.insert (it, TEST_NS::pair<TEST_TK,TEST_TV>('c',400));	// no max efficiency inserting

	// third insert function version (range insertion):
	TEST_NS::map<TEST_TK,TEST_TV> map_insert2;
	map_insert2.insert(map_insert1.begin(),map_insert1.find('c'));

	// showing contents:
	std::cout << "map_insert1 contains:\n";
	for (it=map_insert1.begin(); it!=map_insert1.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "map_insert2 contains:\n";
	for (it=map_insert2.begin(); it!=map_insert2.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "==================== insert test end ===========================" << std::endl;


	std::cout << "==================== erase test start =======================" << std::endl;
	TEST_NS::map<TEST_TK,TEST_TV> map_erase1;
	TEST_NS::map<TEST_TK,TEST_TV>::iterator iter_erase1;

	// insert some values:
	map_erase1['a']=10;
	map_erase1['b']=20;
	map_erase1['c']=30;
	map_erase1['d']=40;
	map_erase1['e']=50;
	map_erase1['f']=60;

	iter_erase1=map_erase1.find('b');
	map_erase1.erase (iter_erase1);									 // erasing by iter_erase1erator

	std::cout << "size : " << map_erase1.size() << std::endl;

	map_erase1.erase ('c');									// erasing by key
	std::cout << "size : " << map_erase1.size() << std::endl;


	iter_erase1=map_erase1.find ('e');
	map_erase1.erase ( iter_erase1, map_erase1.end() );		// erasing by range
	std::cout << "size : " << map_erase1.size() << std::endl;

	// show content:
	for (iter_erase1=map_erase1.begin(); iter_erase1!=map_erase1.end(); ++iter_erase1)
		std::cout << iter_erase1->first << " => " << iter_erase1->second << '\n';
	
	std::cout << "==================== erase test end ===========================" << std::endl;


	std::cout << "==================== swap test start ==========================" << std::endl;

	TEST_NS::map<TEST_TK,TEST_TV> map_swap1,map_swap2;

	map_swap1['x']=100;
	map_swap1['y']=200;

	map_swap2['a']=11;
	map_swap2['b']=22;
	map_swap2['c']=33;

	map_swap1.swap(map_swap2);

	std::cout << "map_swap1 contains:\n";
	for (TEST_NS::map<TEST_TK,TEST_TV>::iterator iter_swap = map_swap1.begin(); iter_swap != map_swap1.end(); ++iter_swap)
		std::cout << iter_swap->first << " => " << iter_swap->second << '\n';

	std::cout << "map_swap2 contains:\n";
	for (TEST_NS::map<TEST_TK,TEST_TV>::iterator iter_swap = map_swap2.begin(); iter_swap != map_swap2.end(); ++iter_swap)
		std::cout << iter_swap->first << " => " << iter_swap->second << '\n';

	std::cout << "==================== swap test end ===========================" << std::endl;

	std::cout << "==================== clear test start ===========================" << std::endl;
	TEST_NS::map<TEST_TK,TEST_TV> map_clear1;

	map_clear1['x']=100;
	map_clear1['y']=200;
	map_clear1['z']=300;

	std::cout << "map_clear1 contains:\n";
	for (TEST_NS::map<TEST_TK,TEST_TV>::iterator iter_clear1=map_clear1.begin(); iter_clear1!=map_clear1.end(); ++iter_clear1)
		std::cout << iter_clear1->first << " => " << iter_clear1->second << '\n';

	map_clear1.clear();
	map_clear1['a']=1101;
	map_clear1['b']=2202;

	std::cout << "map_clear1 contains:\n";
	for (TEST_NS::map<TEST_TK,TEST_TV>::iterator iter_clear1=map_clear1.begin(); iter_clear1!=map_clear1.end(); ++iter_clear1)
		std::cout << iter_clear1->first << " => " << iter_clear1->second << '\n';
	
	std::cout << "==================== clear test end =============================" << std::endl;

	std::cout << "==================== key_comp test start ===========================" << std::endl;

	TEST_NS::map<TEST_TK,TEST_TV> map_key_comp1;

	TEST_NS::map<TEST_TK,TEST_TV>::key_compare mycomp = map_key_comp1.key_comp();

	map_key_comp1['a']=100;
	map_key_comp1['b']=200;
	map_key_comp1['c']=300;

	std::cout << "map_key_comp1 contains:\n";

	TEST_TK highest = map_key_comp1.rbegin()->first;		 // key value of last element

	TEST_NS::map<TEST_TK,TEST_TV>::iterator iter_kc1 = map_key_comp1.begin();
	do {
		std::cout << iter_kc1->first << " => " << iter_kc1->second << '\n';
	} while ( mycomp((*iter_kc1++).first, highest) );

	std::cout << '\n';

	std::cout << "==================== key_comp test end =============================" << std::endl;
}