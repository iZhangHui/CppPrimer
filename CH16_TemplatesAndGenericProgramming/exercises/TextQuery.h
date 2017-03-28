#pragma once
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include "QueryResult.h"

// declaration needed for return type in the query funciton
class QueryResult;
class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
	void display_map(); // debugging aid: print the map
private:
	std::shared_ptr<std::vector<std::string>> file; // input file
	// maps each word to the set of the lines in which that word appears
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;

	// canonicalizes text: removes punctuation and make everything lower case
	static std::string cleanup_str(const std::string&);
};
