/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex12_24.cpp
 * Write a program that reads a string from the standard input into a dynamically
 * allocated character array. Describe how your program handles varying size inputs.
 * Test your program by giving it a string of data that is longer than the array size
 * you’ve allocated.
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */
#include <iostream>

int main(int argc, char const *argv[])
{
	char* cs;
	std::string str;

	while (std::cin >> str) {
		cs = new char[str.size()];
		str.copy(cs, str.size());

		std::cout << cs << std::endl;
		delete [] cs;
	}

	return 0;
}