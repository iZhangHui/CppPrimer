/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex01_08.cc
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */
#include <iostream>

int main(int argc, char const *argv[])
{
	std::cout << "/*";
	std::cout << "*/";
	std::cout << /* "*/" */";
	std::cout << /* "*/" /* "/*" */;
	return 0;
}