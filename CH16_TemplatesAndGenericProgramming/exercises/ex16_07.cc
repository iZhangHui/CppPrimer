/****************************************************************************
 *
 *   Copyright (c) 2017 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex16_07.cc
 *
 * Write a constexpr template that returns the size of a given
 * array.
 *
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <iostream>
#include <vector>
#include <list>
#include <string>

template<typename T, size_t size>
constexpr size_t getSize(const T(&)[size])
{
	return size;
}

int main(int argc, char const *argv[])
{
	std::string s[] = { "sss" };
	std::cout << getSize(s) << std::endl;

	char c[] = "s";
	std::cout << getSize(c) << std::endl;
	// the output is 2, as '\0' is added at the end of the array
	return 0;
}
