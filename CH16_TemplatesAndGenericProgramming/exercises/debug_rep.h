#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define DEBUG 1

// overloaded, not specialized, function templates
template <typename T> std::string debug_rep(const T& t);
template <typename T> std::string debug_rep(T* p);
template <typename T> std::string debug_rep(T b, T e);
template <typename T> std::string debug_rep(const std::vector<T>& v);

std::string debug_rep(const std::string& s);
std::string debug_rep(char* p);
std::string debug_rep(const char* cp);

// print any type we don't otherwise handle
template <typename T>
std::string debug_rep(const T& t)
{
#ifdef DEBUG
	std::cout << "const T&" << "\t";
#endif
	std::ostringstream ret;
	ret << t; // uses T's output operator to print a representation of t
	return ret.str();  // return a copy of the string to which ret is bound
}

// print pointers as their pointer value
// followed by the object to which the pointer points
// NB: this function will not work properly with char*
template <typename T>
std::string debug_rep(T* p)
{
#ifdef DEBUG
	std::cout << "T*" << "\t";
#endif
	std::ostringstream ret;
	ret << "pointer: " << p;         // print the pointer's own value
	if (p)
		ret << " " << debug_rep(*p); // print the value to which p points
	else
		ret << " null pointer";      // or indicate that the p is null
	return ret.str(); // return a copy of the string to which ret is bound
}

template <typename T>
std::string debug_rep(T b, T e)
{
	std::ostringstream ret;
	for (T it = b; it != e; ++it) {
		if (it != b)
			ret << ",";            // put comma before all but the first element
		ret << debug_rep(*it);     // print the element
	}
	return ret.str();
}

template <typename T>
std::string debug_rep(const std::vector<T>& v)
{
	std::ostringstream ret;
	ret << "vector: [";
	ret << debug_rep(v.begin(), v.end());
	ret << "]";
	return ret.str();
}


// print strings inside double quotes
std::string debug_rep(const std::string& s)
{
#ifdef DEBUG
	std::cout << "const string &" << "\t";
#endif
	return '"' + s + '"';
}

// convert the character pointers to string and call the string version of debug_rep
std::string debug_rep(char* p)
{
	return debug_rep(std::string(p));
}

std::string debug_rep(const char* p)
{
	return debug_rep(std::string(p));
}
