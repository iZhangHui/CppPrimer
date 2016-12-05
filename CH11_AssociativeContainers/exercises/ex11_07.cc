/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex11_07.cc
 *
 * Exercise 11.7:
 * Define a map for which the key is the family’s last name and
 * the value is a vector of the children’s names. Write code to
 * add new families and to add new children to an existing family.
 *
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <map>
using std::map;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;



int main(int argc, char const *argv[])
{
	map<string, vector<string>> families;

	for (string last_name; cout << "Input family's last name:" << endl, cin >> last_name;) {
		for (string child_name; cout << "Input children's name:" << endl, cin >> child_name;) {
			families[last_name].push_back(child_name);
		}
		cin.clear();
	}
	cout << "===========================" << endl;

	for (const auto& family : families) {
		cout << family.first << ":" << endl;
		for (const auto& child : family.second)
			cout << child << " ";
		cout << endl;
	}
	return 0;
}
