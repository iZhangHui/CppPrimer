/****************************************************************************
 *
 *   Copyright (c) 2017 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex16_02_03.cc
 *
 * Write and test your own versions of the compare functions.
 *
 * Call your compare function on two Sales_data objects to see how your
 * compiler handles errors during instantiation.
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <iostream>
#include <vector>

using namespace std;

class Sales_data { };

template<typename T>
int compare(const T& lhs, const T& rhs)
{
	if (lhs < rhs) return -1;
	if (rhs < lhs) return 1;

	return 0;
}

int main(int argc, char const *argv[])
{
	cout << compare(1.1f, 1.2f) << endl;

	std::vector<int> vect1{1, 2, 3};
	std::vector<int> vect2{4, 5, 6};
	cout << compare(vect1, vect2) << endl;

	// Sales_data data1, data2;
	// cout << compare(data1, data2) << endl;

	return 0;
}
