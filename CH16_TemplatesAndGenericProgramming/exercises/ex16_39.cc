/****************************************************************************
 *
 *   Copyright (c) 2017 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex16_39.cc
 *
 * Exercise 16.39
 * Use an explicit template argument to make it sensible to pass two string
 * literals to the original version of compare from § 16.1.1 (p.652).
 *
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <iostream>

template <typename T>
int compare(const T& t1, const T& t2)
{
	if (t1 < t2) return -1;
	if (t2 < t1) return 1;
	return 0;
}

int main(int argc, char const *argv[])
{
	std::cout << compare<std::string>("abc", "abd") << std::endl;
	return 0;
}