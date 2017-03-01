
/****************************************************************************
 *
 *   Copyright (c) 2017 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex16_04.cc
 *
 * Write a template that acts like the library find algorithm.
 * The function will need two template type parameters, one to represent the
 * function’s iterator parameters and the other for the type of the value. Use
 * your function to find a given value in a vector<int> and in a
 * list<string.
 *
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */


#include <iostream>
#include <vector>
#include <list>
#include <string>

template<typename InputIt, typename T>
InputIt find(InputIt first, InputIt last, const T& value)
{
	for (; first != last; ++first)
		if (*first == value)
			return first;
	return first;
}

int main(int argc, char const *argv[])
{
	std::vector<int> v = {1, 2, 3, 4, 5, 6};
	auto iterv = find(v.begin(), v.end(), 3);
	std::cout << (iterv != v.end() ? "found\n" : "not found\n");

	std::list<std::string> l = {"hello", "world", "cplusplus", "primer"};
	auto iterl = find(l.begin(), l.end(), "cplusplus");
	std::cout << (iterl != l.end() ? "found\n" : "not found\n");

	return 0;
}
