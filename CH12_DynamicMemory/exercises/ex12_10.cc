/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex12_10.cpp
 * Explain whether the following call to the process function
 * defined on page 464 is correct. If not, how would you correct the call?
 * shared_ptr<int> p(new int(42));
 * process(shared_ptr<int>(p));
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

#include <iostream>
using std::cout;
using std::endl;

void process(shared_ptr<int> ptr)
{
	cout << "insided the process function: " << ptr.use_count() << endl;
}

int main(int argc, char const *argv[])
{
	shared_ptr<int> p(new int(42));

	cout << p.use_count() << endl;
	process(shared_ptr<int>(p));
	cout << p.use_count() << endl;

	return 0;
}