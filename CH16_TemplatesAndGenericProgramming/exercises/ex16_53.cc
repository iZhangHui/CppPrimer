#include <iostream>
#include <string>

// Have no << operator
class Foo { };

class Str
{
	friend std::ostream& operator<<(std::ostream& os, const Str& str);
public:
	Str(): content("empty string") { }
private:
	std::string content;
};

std::ostream& operator<<(std::ostream& os, const Str& str)
{
	os << str.content;
	return os;
}


// function to end the recursion and print the last element
template<typename T>
std::ostream& print(std::ostream& os, const T& t)
{
	// no separator after the last element in the pack
	return os << t;
}

template <typename T, typename... Args>
std::ostream& print(std::ostream &os, const T& t, const Args&... rest) //expand Args
{
	os << t << ", ";
	return print(os, rest...); //expand rest
}

int main(int argc, char const *argv[])
{
	int i = 0;
	double d = 3.14;
	std::string s = "Hello World!";
	Foo foo;
	Str str;
	// error: cannot bind ‘std::ostream {aka std::basic_ostream<char>}’ lvalue to ‘std::basic_ostream<char>&&’
	// return os << t;
	// print(std::cout, foo);
	print(std::cout, 1) << std::endl;
	print(std::cout, 1, 2.0f) << std::endl;
	print(std::cout, 1, 2.0f, s, str) << std::endl;
	return 0;
}