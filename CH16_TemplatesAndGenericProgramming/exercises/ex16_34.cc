// #include "../examples/compare.h"

template <typename T>
int compare(const T& v1, const T& v2)
{
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

int main(int argc, char const *argv[])
{
	// candidate template ignored: deduced conflicting types for parameter 'T' ('char [3]' vs. 'char [6]')
	// compare("hi", "world");
	compare("bye", "dad");
	return 0;
}
