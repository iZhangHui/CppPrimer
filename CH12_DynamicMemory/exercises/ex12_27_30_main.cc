/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex12_27_30_main.cpp
 * Define your own versions of the TextQuery and Define your own
 * versions of the TextQuery and QueryResult classes and execute
 * the runQueries function from § 12.3.1 (p. 486).
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#include <cstdlib>

#include "ex12_27_30.h"

void runQueries(ifstream& infile)
{
	TextQuery tq(infile);

	while (true) {
		cout << "enter word to look for, or q to quite: ";
		string s;

		if (!(cin >> s) || s == "q")
			break;
		print(cout, tq.query(s)) << endl;
	}
}

int main(int argc, char const *argv[])
{
	ifstream infile;

	// Test data CH12_DynamicMemory/examples/data/storyDataFile
	if (argc < 2 || !(infile.open(argv[1]), infile)) {
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}
	runQueries(infile);
	return 0;
}
