#include <iostream>
#include <string>
#include <map>
#include <cstddef>
#include "debug_rep.h"
#include "Sales_data.h"

using namespace std;

// function to end the recursion and print the last element
template<typename T>
ostream& print(ostream& os, const T& t)
{
	return os << t; // no separator after the last element in the pack
}

template <typename T, typename... Args>
ostream& print(ostream &os, const T& t, const Args&... rest)//expand Args
{
	os << t << ", ";
	return print(os, rest...);                     //expand rest
}

// call debug_rep on each argument in the call to print
template <typename... Args>
ostream& errorMsg(ostream& os, const Args&... rest)
{
	// print(os, debug_rep(a1), debug_rep(a2), ..., debug_rep(an)
	return print(os, debug_rep(rest)...);
}

struct ErrorCode {
	ErrorCode(size_t n = 0): e(n) { }
	size_t e;
	size_t num() const { return e; }
	string lookup() const { return errors[e]; }
	static map<size_t, string> errors;
};

map<size_t, string>
ErrorCode::errors = { {42, "some error"}, { 1024, "another error"} };

int main(int argc, char const *argv[])
{
	Sales_data item("978-0590353403", 25, 15.99);
	string fcnName("itemProcess");
	ErrorCode code(42);
	string otherData("invalid ISBN");

	errorMsg(cerr, fcnName, code.num(), otherData, "other", item);
	cerr << endl;

	print(cerr, debug_rep(fcnName), debug_rep(code.num()),
				debug_rep(otherData), debug_rep("otherData"),
				debug_rep(item));
	cerr << endl;

	return 0;
}
