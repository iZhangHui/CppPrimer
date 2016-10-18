/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex12_13.cpp
 * What happens if we execute the following code?
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <memory>
using std::make_shared;

int main(int argc, char const *argv[])
{
	{
		auto sp = std::make_shared<int>();
		auto p = sp.get();
		delete p;
	}

	return 0;
}