#pragma once

//#include <cstddef>
#include <string>
#include <iostream>

// function-object class that clls delete on a given pointer
class DebugDelete {
public:
	DebugDelete(const std::string& s = "unique_ptr",
				std::ostream& os = std::cerr):
		os(os), type(s) { }

	// as with any function template, the type of T is duduced by compiler
	template <typename T>
	void operator()(T* p) const
	{
		os << "deleting " << type << std::endl;
		delete p;
	}

private:
	std::ostream& os;
	std::string type;
};
