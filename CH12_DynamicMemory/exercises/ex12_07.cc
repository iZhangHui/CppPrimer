/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex12_07.cpp
 * Redo the previous exercise(ex12_06), this time using shared_ptr.
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <vector>
#include <memory>
#include <iostream>
using namespace std;

shared_ptr<vector<int>> alloc()
{
	return make_shared<vector<int>>();
}

shared_ptr<vector<int>> populate(shared_ptr<vector<int>> vec)
{
	int item;

	while (cin >> item) {
		vec->push_back(item);
	}

	return vec;
}

ostream& print(shared_ptr<vector<int>> vec)
{
	for (auto item : *vec) {
		cout << item << " ";
	}

	return cout;
}

int main(int argc, char const *argv[])
{
	auto pvec = populate(alloc());

	print(pvec) << endl;

	return 0;
}