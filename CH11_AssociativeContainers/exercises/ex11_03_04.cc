/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex11_03_04.cc
 *
 * Exercise 11.3 Write your own version of the word-counting program.
 *
 * Exercise 11.4 Extend your program to ignore case and punctuation. For
 * example, “example.” “example,” and “Example” should all increment the
 * same counter.
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <map>
using std::map;

#include <string>
using std::string;

#include <utility>
using std::pair;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <algorithm>
using std::remove_if;

#include <cctype>

int main(int argc, char const *argv[])
{
	// count the number of times each word occurs in the input
	map<string, size_t> word_count; // empty map from string to size_t
	string word;
	while (cin >> word) {
		for (auto& ch : word)
			ch = tolower(ch);

		// strip - iterator erase(iterator __first, iterator __last)
		word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
		++word_count[word];
	}

	for (const auto& w : word_count)
		cout <<  w.first << " occurs " << w.second << " times" << endl;

	// get an iterator positioned on the first element
	auto map_it = word_count.cbegin();
	// compare the current iterator to the off-the-end iterator
	while (map_it != word_count.cend()) {
		// dereference the iterator to print the element key--value pairs
		cout << map_it->first << " occurs "
			 << map_it->second << " times" << endl;
		++map_it;  // increment the iterator to denote the next element
	}

	return 0;
}