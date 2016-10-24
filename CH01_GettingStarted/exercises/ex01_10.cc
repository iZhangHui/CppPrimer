/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex01_10.cc
 * In addition to the ++ operator that adds 1 to its operand, there is a decrement
 * operator (--) that subtracts 1. Use the decrement operator to write a while that
 * prints the numbers from ten down to zero.
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <iostream>

int main(int argc, char const *argv[])
{
	// int num = 10;
	// do {
	// 	std::cout << num << " ";
	// } while (--num >= 0);

	for (int num = 10; num >= 0; --num) {
		std::cout << num << " ";
	}

	std:: cout << std::endl;
	return 0;
}