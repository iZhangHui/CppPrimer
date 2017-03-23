/****************************************************************************
 *
 *   Copyright (c) 2017 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex16_19_20.cc
 *
 * Exercise 16.19
 * Write a function that takes a reference to a container and
 * prints the elements in that container. Use the container’s size_type and
 * size members to control the loop that prints the elements.
 *
 * Exercise 16.20
 * Rewrite the function from the previous exercise to use
 * iterators returned from begin and end to control the loop.
 *
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <vector>
#include <list>
#include <iostream>

template <typename Container>
std::ostream& print1(const Container& container, std::ostream& os)
{
	for (typename Container::size_type i = 0; i != container.size(); ++i) {
		os << container[i] << " ";
	}
	os << std::endl;

	return os;
}

template <typename Container>
std::ostream& print2(const Container& container, std::ostream& os)
{
	for (auto iter = container.cbegin(); iter != container.cend(); ++iter) {
		os << *iter << " ";
	}
	os << std::endl;

	return os;
}

int main(int argc, char const *argv[])
{
	std::vector<std::string> v = {"hello", "c++11", "template"};
	std::list<int> l = {1, 2, 3, 4};

	print1(v, std::cout);
	print2(l, std::cout);

	return 0;
}