/****************************************************************************
 *
 *   Copyright (c) 2017 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex16_45.cc
 *
 * Exercise 16.45
 *
 * Given the following template, explain what happens if we call g on a literal value
 * such as 42. What if we call g on a variable of type int?
 * template <typename T> void g(T&& val) { vector<T> v; }
 *
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <iostream>
#include <vector>

template <typename T>
void g(T&& val)
{
	std::vector<T> v;
}

int main(int argc, char const *argv[])
{
	/*
	ex16_45.cc:7:17: note: in instantiation of template class 'std::vector<int &, std::allocator<int &> >' requested here
        std::vector<T> v;
                       ^
	ex16_45.cc:13:2: note: in instantiation of function template specialization 'g<int &>' requested here
        g(i);
    */

	// int i = 42;
	// g(i);

	g(42);
	return 0;
}
