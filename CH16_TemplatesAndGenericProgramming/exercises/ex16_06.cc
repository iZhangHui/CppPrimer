/****************************************************************************
 *
 *   Copyright (c) 2017 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex16_06.cc
 *
 * How do you think the library begin and end functions that take an
 * array argument work? Define your own versions of these functions.
 *
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

// #include <vector>
// #include <list>
// #include <array>
#include <string>
#include <iostream>

template<typename T, size_t size>
T* begin_custom(T(&array)[size])
{
	return array;
}

template<typename T, size_t size>
T* end_custom(T(&array)[size])
{
	return array + size;
}

int main(int argc, char const *argv[])
{
	// std::array<std::string, 3> sa = {"hello", "c++", "primer"};
	std::string sa[] = {"hello", "c++", "primer"};
	std::cout << *(begin_custom(sa) + 1) << std::endl;
	std::cout << *(end_custom(sa) - 1) << std::endl;
	return 0;
}
