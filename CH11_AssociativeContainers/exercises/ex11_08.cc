/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex11_08.cc
 *
 * Exercise 11.08 // Write a program that stores the excluded words in a vector
 * instead of in a set. What are the advantages to using a set?
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
	std::vector<std::string> exclude = { "aa", "bb", "bb", "cc", "dd", "ee", "ff" };
	for (std::string word; std::cout << "Enter plz:\n", std::cin >> word; ) {
		auto is_excluded = std::binary_search(exclude.cbegin(), exclude.cend(), word);
		auto reply = is_excluded ? "excluded" : "not excluded";
		std::cout << reply << std::endl;
	}

	return 0;
}
