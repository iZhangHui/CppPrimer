#include <iostream>
#include <string>
#include "ex16_12_13.h"

int main(int argc, char const *argv[])
{
	Blob<int> blob{1, 2, 3};
	blob.push_back(4);

	// for (auto item : blob) {
	// 	std::cout << item << " "
	// }
	// std::cout << std::endl;
	for (size_t i = 0; i != blob.size(); ++i) {
		std::cout << blob[i] << " ";
	}
	std::cout << std::endl;

	// int ret = blob.back();
	int& ret = blob.back();
	ret = 5;

	for (size_t i = 0; i != blob.size(); ++i) {
		std::cout << blob[i] << " ";
	}
	std::cout << std::endl;


	Blob<std::string> b1; // empty Blob
	std::cout << b1.size() << std::endl;
	{  // new scope
		Blob<std::string> b2 = {"a", "an", "the"};
		b1 = b2;  // b1 and b2 share the same elements
		b2.push_back("about");
		std::cout << b1.size() << " " << b2.size() << std::endl;
	} // b2 is destroyed, but the elements it points to must not be destroyed
	std::cout << b1.size() << std::endl;
	for(auto p = b1.begin(); p != b1.end(); ++p)
		std::cout << *p << std::endl;

	for(auto item : b1)
		std::cout << item << std::endl;

	return 0;
}