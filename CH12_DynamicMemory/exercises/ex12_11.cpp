/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex12_11.cpp
 * Explain whether the following call to the process function
 * defined on page 464 is correct. If not, how would you correct the call?
 * shared_ptr<int> p(new int(42));
 * process(shared_ptr<int>(p.get()));
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
	process(shared_ptr<int>(p.get()));
	cout << p.use_count() << endl;


	// cout << *p << endl; //undefined,  the memory to which p points was freed

	// why execute p.reset() won't corrupt.
	// p.reset(); // double freed or corruption was generated.

	// delete p.get(); // double freed or corruption was generated.

	return 0;
}


// int main(int argc, char const *argv[])
// {
// 	{
// 		shared_ptr<int> p(new int(42));

// 		cout << p.use_count() << endl;
// 		process(shared_ptr<int>(p.get()));
// 		cout << p.use_count() << endl;
// 	}

// 	return 0;
// }

// class Test
// {
// public:
// 	Test() : i(0) { cout << "Test constructor." << endl; }
// 	~Test() { cout << "Test destructor." << endl; }
// private:
// 	int i;
// };

// void process(shared_ptr<Test> ptr)
// {
// 	cout << "insided the process function: " << ptr.use_count() << endl;
// }

// int main(int argc, char const *argv[])
// {
// 	{
// 		shared_ptr<Test> p(new Test());

// 		cout << p.use_count() << endl;
// 		process(shared_ptr<Test>(p.get()));
// 		cout << p.use_count() << endl;

// 		// delete p.get();
// 	}


// 	return 0;
// }
