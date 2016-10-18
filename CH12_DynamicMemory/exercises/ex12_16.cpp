/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex12_16.cpp
 * Compilers don’t always give easy-to-understand error messages
 * if we attempt to copy or assign a unique_ptr. Write a program
 * that contains these errors to see how your compiler diagnoses them.
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <memory>
using std::unique_ptr;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	unique_ptr<string> p1 (new string("Henry"));

	/* error: call to deleted constructor of 'unique_ptr<string>' */
	// unique_ptr<string> p2(p1); // copy

	/**
	 * error: overload resolution selected deleted operator '='
	 * note: candidate function has been explicitly deleted
     * unique_ptr& operator=(const unique_ptr&) = delete;
     */
	// unique_ptr<string> p3;
	// p3 = p1; //assign

	cout << *p1 << endl;
	return 0;
}
