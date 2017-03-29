/****************************************************************************
 *
 *   Copyright (c) 2017 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex16_26.cc
 *
 * Exercise 16.26
 * Assuming NoDefault is a class that does not have a
 * default constructor, can we explicitly instantiate vector<NoDefault>?
 * If not, why not?
 *
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */


#include <vector>
using namespace std;

class NoDefault
{
public:
	NoDefault(int foo) : _foo(foo) { }
private:
	int _foo;
};

int main(int argc, char const *argv[])
{
	// vector<NoDefault> notCompiled(10);
	return 0;
}
