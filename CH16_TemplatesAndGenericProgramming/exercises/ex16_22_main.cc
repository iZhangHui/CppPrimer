#include <string>
#include <fstream>
#include <iostream>

#include <cstdlib>  // for EXIT_FAILURE

#include "TextQuery.h"
using namespace std;

void runQueries(ifstream& infile)
{
	// infile is an ifstream that is the file we want to query
	TextQuery tq(infile);  // store the file and build the query map
	// iterate with the user: prompt for a word to find and print results
	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		// stop if we hit end-of-file on the input or if a 'q' is entered
		if (!(cin >> s) || s == "q")
			break;
		// run the query and print the results
		print(cout, tq.query(s)) << endl;
	}
}

// program takes single argument specifying the file to query
int main(int argc, char const *argv[])
{
	// open the file from which user will query words
	ifstream infile;
	// open returns void, so we use the comma operator XREF(commaOp)
	// to check the state of infile after the open
	if (argc < 2 || !(infile.open(argv[1]), infile)) {
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}
	runQueries(infile);
	return 0;
}
