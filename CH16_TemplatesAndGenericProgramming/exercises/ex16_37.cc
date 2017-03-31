/****************************************************************************
 *
 *   Copyright (c) 2017 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex16_37.cc
 *
 * Exercise 16.37
 * The library max function has two function parameters and returns the larger of its arguments.
 * This function has one template type parameter. Could you call max passing it an int and a double?
 * If so, how? If not, why not?
 *
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */


#include <algorithm>
#include <iostream>

int main(int argc, char const *argv[])
{
	int a = 1;
	long b = 2;
	// std::cout << std::max(a, b) << std::endl;
	std::cout << std::max<long>(a, b) << std::endl;

	// std::cout << std::max<int>(a, b) << std::endl;
	return 0;
}