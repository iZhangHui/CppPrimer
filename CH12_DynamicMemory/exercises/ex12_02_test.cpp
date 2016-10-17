/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex12_02_test.cpp
 *
 * Write your own version of the StrBlob class including the const versions of
 * front and back.
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */
#include <iostream>
#include "ex12_02.h"

int main(int argc, char const *argv[])
{
	StrBlob sb = { "Hello", "C++ Primer" };

	std::cout << sb.front() << " " << sb.back() << std::endl;
	sb.back() = "C++ Primer 5th";
	std::cout << sb.front() << " " << sb.back() << std::endl;

	const StrBlob csb = { "StrBlob", "Test" };
	std::cout << csb.front() << " " << csb.back() << std::endl;
	// csb.back() = "error";
	// std::cout << csb.front() << " " << csb.back() << std::endl;

	return 0;
}