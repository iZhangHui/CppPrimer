/****************************************************************************
 *
 *   Copyright (c) 2017 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex16_41.cc
 *
 * Exercise 16.41
 * Write a version of sum with a return type that is
 * guaranteed to be large enough to hold the result of the addition.
 *
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <limits>
#include <iostream>
#include <typeinfo>

// template<typename T>
// auto sum(T lhs, T rhs) -> decltype(lhs + rhs)
// {
// 	return lhs + rhs;
// }

// // C++14
// // template<typename T>
// // auto sum(T lhs, T rhs)
// // {
// // 	return lhs + rhs;
// // }

// int main(int argc, char const *argv[])
// {
// 	unsigned int a = std::numeric_limits<unsigned int>::max();
// 	unsigned int b = std::numeric_limits<unsigned int>::max();
// 	// unsigned long c;

// 	auto s = sum(a, b);
// 	std::cout << typeid(a).name() << std::endl;
// 	// std::cout << typeid(c).name() << std::endl;
// 	std::cout << typeid(s).name() << std::endl;
// 	return 0;
// }

template<std::size_t, bool>
struct promote;

template<> struct promote<sizeof(std::uint8_t ), false> { using type = std::uint16_t; };
template<> struct promote<sizeof(std::uint16_t), false> { using type = std::uint32_t; };
template<> struct promote<sizeof(std::uint32_t), false> { using type = std::uint64_t; };

template<> struct promote<sizeof(std::int8_t ), true> { using type = std::int16_t; };
template<> struct promote<sizeof(std::int16_t), true> { using type = std::int32_t; };
template<> struct promote<sizeof(std::int32_t), true> { using type = std::int64_t; };

template<typename T> using promote_t = typename promote<sizeof(T), std::is_signed<T>::value>::type;

template <typename T>
promote_t<T> my_sum(T first, T second)
{
	return static_cast<promote_t<T>>(first) + second; // promotion
}

int main(int argc, char const *argv[])
{
	using namespace std;
	auto a = numeric_limits<int>::min();
	cout << a << " + " << a << " = " << my_sum(a, a) << endl;

	auto b = numeric_limits<unsigned int>::max();
	cout << b << " + " << b << " = " << my_sum(b, b) << endl;
	return 0;
}
