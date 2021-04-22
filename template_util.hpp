/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template_util.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 23:05:55 by honlee            #+#    #+#             */
/*   Updated: 2021/04/22 13:35:39 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_UTIL_HPP
# define TEMPLATE_UTIL_HPP

namespace ft
{
	//출저 : https://github.com/llefranc/42_ft_containers/blob/main/templates/stl_like.hpp

    //들어온 bool 이 false 일경우 아무 맴버가 없다. 따라서 이를 이용해 에러를 발생시킬 수 있고,
    //오버로드 함수 후보에서 제외 시킬 수 있다.
	template <bool B>
    struct enable_if {};

	//들어온 bool 값이 true 인경우에만 type 이라는 맴버를 갖는다.
    template <>
    struct enable_if<true> { typedef int type; };

	//bool , char, short 등 integer 로 바뀔수있는 것들에 대해서는 value 가 true, 아닐경우 false
    template <typename T>
    struct is_integral { static const bool value = false; };

    template <>
    struct is_integral<bool> { static const bool value = true; };
        
    template <>
    struct is_integral<char> { static const bool value = true; };

    template <>
    struct is_integral<short> { static const bool value = true; };

    template <>
    struct is_integral<int> { static const bool value = true; };

    template <>
    struct is_integral<long> { static const bool value = true; };

    template <>
    struct is_integral<long long> { static const bool value = true; };

    template <>
    struct is_integral<unsigned char> { static const bool value = true; };

    template <>
    struct is_integral<unsigned short> { static const bool value = true; };

    template <>
    struct is_integral<unsigned int> { static const bool value = true; };

    template <>
    struct is_integral<unsigned long> { static const bool value = true; };

    template <>
    struct is_integral<unsigned long long> { static const bool value = true; };
}

#endif