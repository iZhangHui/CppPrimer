#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;

#include "ex16_16.h"

void print(const Vec<string>& svec)
{
	for (auto it : svec)
		cout << it << " " ;
	cout <<endl;
}

Vec<string> getVec(istream& is)
{
	Vec<string> svec;
	string s;
	while (is >> s)
		svec.push_back(s);
	return svec;
}

int main(int argc, char const *argv[])
{
	Vec<string> svec = getVec(cin);
	print(svec);

	cout << "copy " << svec.size() << endl;
	auto svec2 = svec;
	print(svec2);

	cout << "assign" << endl;
	Vec<string> svec3;
	svec3 = svec2;
	print(svec3);

	Vec<string> v1, v2;
	Vec<string> getVec(istream &);
	v1 = v2;           // copy assignment
	v2 = getVec(cin);  // move assignment

	return 0;
}
