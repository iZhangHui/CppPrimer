
/****************************************************************************
 *
 *   Copyright (c) 2017 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex16_51_52.cc
 *
 * Exercise 16.51
 *
 * Determine what sizeof...(Args) and sizeof...(rest) return for each
 * call to foo in this section.
 *
 * Exercise 16.52
 * Write a program to check your answer to the previous question.
 *
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */


#include <iostream>
#include <string>

template <typename T, typename... Args>
void foo(const T& t, const Args&... rest)
{
	std::cout << sizeof...(Args) << std::endl;
	std::cout << sizeof...(rest) << std::endl;
}

int main(int argc, char const *argv[])
{
	int i = 0;
	double d = 3.14;
	std::string s = "how now brown cow?";
	foo(i, s, 42, d);
	foo(s, 42, "hi");
	foo(d, s);
	foo("hi");

	return 0;
}