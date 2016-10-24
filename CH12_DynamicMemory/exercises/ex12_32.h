/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex12_32.h
 * Rewrite the TextQuery and QueryResult classes to use a StrBlob
 * instead of a vector<string> to hold the input file.
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>

#include "StrBlob.h"

class QueryResult;

class TextQuery
{
public:
	using line_no = StrBlob::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
	void display_map();
private:
	// std::shared_ptr<std::vector<std::string>> file;
	StrBlob file;

	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;

	static std::string clean_str(const std::string&);
};

class QueryResult
{
public:
	friend std::ostream& print(std::ostream&, const QueryResult&);
	using line_no = StrBlob::size_type;
	using line_it = std::set<line_no>::const_iterator;

	QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
				const StrBlob& f) :
		sought(s), lines(p), file(f) { }

	std::set<line_no>::size_type size() const { return lines->size(); }

private:
	// word this query represents
	std::string sought;
	// lines it's on
	std::shared_ptr<std::set<line_no>> lines;
	// input file
	// std::shared_ptr<std::vector<std::string>> file;
	StrBlob file;
};

std::ostream& print(std::ostream&, const QueryResult&);