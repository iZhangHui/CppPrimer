/****************************************************************************
 *
 *   Copyright (c) 2017 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex16_05.cc
 *
 * Write a template version of the print function from § 6.2.4
 * (p. 217) that takes a reference to an array and can handle arrays of any size
 * and any element type.
 *
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */


#include <iostream>
#include <string>
#include <array>

template<typename T>
void print(const T& array)
{
	for (auto const& elem : array)
		std::cout << elem << std::endl;
}

int main(int argc, char const *argv[])
{
	std::array<std::string, 3> array= {"HELLO", "CPLUSPLUS", "PRIMER"};
	std::string s[] = {"hello", "cplusplus", "primer"};
	char c[] = { 'a', 'b', 'c', 'd' };
	int  i[] = { 1 };

	print(i);
	print(c);
	print(s);
	print(array);

	return 0;
}
