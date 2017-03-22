#include <iostream>
#include "ex16_14_15.h"

int main(int argc, char const *argv[])
{
	Screen<5, 5> scr('c');

	scr.display(std::cout);

	// output src to the screen
	std::cout << scr;

	std::cin >> scr;

	std::cout << scr;

	return 0;
}