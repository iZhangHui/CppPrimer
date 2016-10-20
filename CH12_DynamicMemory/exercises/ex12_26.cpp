/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex12_26.cpp
 * Rewrite the program on page 481 using an allocator.
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */
#include <string>
#include <iostream>
#include <memory>

using namespace std;
const int SIZE = 10;

int main(int argc, char const *argv[])
{
	allocator<string> alloc;
	string* const p = alloc.allocate(SIZE);

	string s;
	auto q = p;

	while (cin >> s && q != p + SIZE) {
		alloc.construct(q++, s);
	}

	for (auto r = p; r != q; ++r) {
		cout << *r << endl;
		alloc.destroy(r);
	}

	alloc.deallocate(p, SIZE);
	return 0;
}