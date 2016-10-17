/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex12_06.cpp
 *
 * Write a function that returns a dynamically allocated vector
 * of ints. Pass that vector to another function that reads the standard input
 * to give values to the elements. Pass the vector to another function to print
 * the values that were read. Remember to delete the vector at the
 * appropriate time.
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <vector>
#include <iostream>
using namespace std;

vector<int>* alloc()
{
	return new vector<int>();
}

vector<int>* populate(vector<int>* vec)
{
	int item;

	while (cin >> item) {
		vec->push_back(item);
	}

	return vec;
}

ostream& print(vector<int>* vec)
{
	for (auto item : *vec) {
		cout << item << " ";
	}

	return cout;
}

int main(int argc, char const *argv[])
{
	auto pvec = alloc();

	populate(pvec);

	print(pvec) << endl;

	delete pvec;

	return 0;
}