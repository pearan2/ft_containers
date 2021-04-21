/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:38:47 by honlee            #+#    #+#             */
/*   Updated: 2021/04/21 14:21:59 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include "allocator.hpp"

class Test
{
	public :
		unsigned int n;

		Test(){}
		Test(unsigned int n) : n(n){}
		~Test()
		{
			std::cout << "destroyed!! "<< std::endl;
		}
};

int		main()
{
	std::allocator<int> alloc;

	int *arr_int = alloc.allocate(5); // int 타입 5개가 들어가는 메모리를 만들어서 그 포인터를 반환
									  // 초기화가 전혀 이루어지지 않아서 new 보다 훨씬 빠르다.
									  
	alloc.construct(arr_int, -123); // 첫번째 매개변수가 가르키는 곳을 두번째 매개변수 값으로 초기화한다.
									// 이 행위가 첫번째 초기화이다
									// 초기화 되지 않은 공간에 * 를 사용하여 값을 할당하면 에러가 발생하는데,
									// 이 함수를 통하여 에러없이 값을 저장할 수 있다.


	for(int i=0; i<5; i++)
	 	std::cout << arr_int[i] << " ";	
	std::cout << std::endl <<  "==========================" << std::endl;


	alloc.deallocate(arr_int, 5);	// 해당 메모리를 dealloc 한다.


	for(int i=0; i<5; i++)
	 	std::cout << arr_int[i] << " ";	
	std::cout << std::endl <<  "==========================" << std::endl;

	
	alloc.destroy(arr_int);			// 해당 메모리의 할당은 그대로 유지한채로 존재하는 객체만 삭제한다. (소멸자 호출)

	for(int i=0; i<5; i++)
	 	std::cout << arr_int[i] << " ";	
	std::cout << std::endl <<  "==========================" << std::endl;


	std::cout << "==================== class test ======================== " << std::endl;
	
	std::allocator<Test> test_alloc;

	Test t(42);
	Test *test = test_alloc.allocate(1);

	std::cout << test->n << std::endl;
	test_alloc.construct(test, t);
	std::cout << test->n << std::endl;
	
	//test_alloc.deallocate(test, 1);
	test_alloc.destroy(test); // 메모리에 있는 객체 소멸, 메모리는 아직 유지되고 있다.
	test_alloc.deallocate(test, 1);

	std::cout << test->n << std::endl;

	std::cout << "==================== class test end===================== " << std::endl;


	std::cout << "==================== rebind test ======================== " << std::endl;


	std::cout << "==================== rebind test end===================== " << std::endl;
}