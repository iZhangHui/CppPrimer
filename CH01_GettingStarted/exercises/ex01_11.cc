/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex01_11.cc
 * Write a program that prompts the user for two integers. Print each number
 * in the range specified by those two integers.
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void print_range(int left, int right)
{
	for (int i = left; i != right; left < right ? ++i : --i)
		cout << i << " ";
	cout << endl;
}

int main(int argc, char const *argv[])
{
	int left = 0;
	int right = 0;
	cout << "please input two integers:\n";
	cin >> left >> right;
	print_range(left, right);
	return 0;
}
