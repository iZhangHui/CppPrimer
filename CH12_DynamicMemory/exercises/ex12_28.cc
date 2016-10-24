/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex12_28.cpp
 * Write a program to implement text queries without defining classes to manage
 * the data. Your program should take a file and interact with a user to query
 * for words in that file. Use vector, map, and set containers to hold the data
 * for the file and to generate the results for the queries.
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <sstream>
using std::istringstream;

#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <set>
using std::set;

#include <algorithm>
using std::remove_copy_if;

#include <cstdlib>

int main(int argc, char const *argv[])
{
	ifstream infile;
	vector<string> file;
	map<string, set<decltype(file.size())>> wm;

	// Test data CH12_DynamicMemory/examples/data/storyDataFile
	if (argc < 2 || !(infile.open(argv[1]), infile)) {
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}

	string text;
	while (getline(infile, text)) {
		file.push_back(text);
		istringstream line(text);
		string str;
		while (line >> str) {
			string word;
			remove_copy_if(str.cbegin(), str.cend(), back_inserter(word), ispunct);
			wm[word].insert(file.size());
		}
	}

	while (true) {
		cout << "enter word to look for, or q to quite: ";
		string s;

		if (!(cin >> s) || s == "q")
			break;

		auto found = wm.find(s);
		if (found != wm.end()) {
			cout << s << " occurs " << found->second.size() << "time(s)" << endl;
			for (auto num : found->second) {
				cout << "\t(line " << num  << ") " << file[num - 1] << endl;
			}
		} else {
			cout << s << " occurs 0 time" << endl;
		}
	}
	return 0;
}
