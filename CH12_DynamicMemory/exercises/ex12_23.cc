/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex12_23.cpp
 * Write a program to concatenate two string literals, putting the result in
 * a dynamically allocated array of char.
 * Write a program to concatenate two library strings that have the same value
 * as the literals used in the first program.
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */
#include <cstddef>
using std::size_t;
#include <cstring>

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

char* literal_strcat(const char* str1, const char* str2)
{
	// dynamically allocated array of char
	char* ret = new char[strlen(str1) + strlen(str2) + 1];
	strcat(ret, str1);
	strcat(ret, str2);
	return ret;
}

string library_strcat(const string& str1, const string& str2)
{
	return str1 + str2;
}


int main(int argc, char const *argv[])
{
	const char* str1 = "Hello ";
	const char* str2 = "World!";

	char* str3 = literal_strcat(str1, str2);
	cout << str3 << endl;
	delete [] str3;

	string str4 = "Hello ";
	string str5 = "World!";

	cout << library_strcat(str4, str5) << endl;
	return 0;
}