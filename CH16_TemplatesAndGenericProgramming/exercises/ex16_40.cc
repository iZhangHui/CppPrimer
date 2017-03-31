/****************************************************************************
 *
 *   Copyright (c) 2017 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex16_40.cc
 *
 * Exercise 16.40
 * Is the following function legal? If not, why not? If it is legal, what,
 * if any, are the restrictions on the argument type(s) that can be passed,
 * and what is the return type?
 *
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <iostream>
#include <vector>
#include <string>

class Foo { };

Foo operator+(Foo lhs, int)
{
	return lhs;
}

template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
	return *beg;  // return a copy of an element from the range
}

int main(int argc, char const *argv[])
{
	Foo b;
	std::vector<Foo> v;
	v.push_back(Foo());
	b = fcn3(v.begin(), v.end());
	return 0;
}
