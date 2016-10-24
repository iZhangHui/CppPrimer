/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex12_17.cpp
 * Which of the following unique_ptr declarations are illegal or likely to
 * result in subsequent program error? Explain what the problem is with each one.
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <iostream>
using std::cout;
using std::endl;

void process(shared_ptr<int> ptr)
{
	cout << "inside the process function:" << ptr.use_count() << endl;
}

int main(int argc, char const *argv[])
{
	auto p = new int();
	auto sp = make_shared<int>();

	/** @brief
	 *  legal. Just copy sp which is a shared_ptr to process().
	 */
	// process(sp);

	/** @brief
	 *  illegale.plain pointer can not convert to smart pointer implicitly.
	 */
	// process(new int());

	/** @brief
	 *  illegale.plain pointer can not convert to smart pointer implicitly.
	 */
	// process(p);

	/** @brief
	 *  Legal. But it's a bad practice to do so.
	 *  Because using smart pointer together with raw pointer could potentially cause problems.
	 *  For example double free as shown in exe12_11.cpp
	 *
	 */
	// process(shared_ptr<int>(p));
}