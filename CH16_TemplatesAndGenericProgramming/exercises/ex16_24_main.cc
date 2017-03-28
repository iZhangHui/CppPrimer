#include <string>
#include <vector>
#include <iostream>
#include "ex16_24.h"
using namespace std;

int main(int argc, char const *argv[])
{
	Blob<string> b1; // empty Blob
	cout << b1.size() << endl;
	{  // new scope
		Blob<string> b2 = {"a", "an", "the"};
		b1 = b2;  // b1 and b2 share the same elements
		b2.push_back("about");
		cout << b1.size() << " " << b2.size() << endl;
	} // b2 is destroyed, but the elements it points to must not be destroyed
	cout << b1.size() << endl;

	for(auto p = b1.begin(); p != b1.end(); ++p)
		cout << *p << endl;

	vector<string> vs = {"hello", "c++", "primer"};
	Blob<string> bs(begin(vs), end(vs));
	for (auto item : bs)
		cout << item << endl;

	return 0;
}
