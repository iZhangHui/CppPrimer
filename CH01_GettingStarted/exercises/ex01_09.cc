/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex01_09.cc
 * Write a program that uses a while to sum the numbers from 50 to 100.
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */
#include <iostream>

int main(int argc, char const *argv[])
{
	int sum = 0;
	int value = 50;
	while (value <= 100) {
		sum += value++;
	}
	std::cout << "sum = " << sum << std::endl;
	return 0;
}