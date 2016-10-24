/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex12_32.cpp
 * Rewrite the TextQuery and QueryResult classes to use a StrBlob
 * instead of a vector<string> to hold the input file.
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include "ex12_32.h"

#include <cstddef>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <utility>

using std::size_t;
using std::shared_ptr;
using std::istringstream;
using std::string;
using std::getline;
using std::vector;
using std::map;
using std::set;
using std::cerr;
using std::cout;
using std::cin;
using std::ostream;
using std::endl;
using std::ifstream;
using std::ispunct;
using std::tolower;
using std::strlen;
using std::pair;
using std::make_shared;

TextQuery::TextQuery(ifstream& is)
{
	string text;
	while (getline(is, text)) {
		file.push_back(text);
		int n = file.size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			word = clean_str(word);
			/**
			 * if the key is not already present,
			 * a new element is created and inserted
			 * into the map for that key.
			*/
			auto& lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

string TextQuery::clean_str(const string& word)
{
	string ret;
	for (auto it = word.begin(); it != word.end(); ++it) {
		if (!ispunct(*it))
			ret += tolower(*it);
	}
	return ret;
}

QueryResult TextQuery::query(const string& sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	auto loc = wm.find(clean_str(sought));

	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

ostream& print(ostream& os, const QueryResult& qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< "time(s)" << endl;

	for (auto num : *qr.lines) {
		ConstStrBlobPtr p(qr.file, num + 1);
		os << "\t(line " << num + 1 << ") "
			<< p.deref() << endl;
	}

	return os;
}

void TextQuery::display_map()
{
	// auto iter = wm.cbegin();
	// auto iter_end = wm.cend();

	for (auto iter = wm.cbegin(); iter != wm.cend(); ++iter) {
		cout << "word: " << iter->first << " {";

		// auto text_locs = iter->second;
		// auto loc_iter = text_locs->cbeing()

		for (auto loc_iter = iter->second->cbegin();
			loc_iter != iter->second->cend(); ++loc_iter) {

			cout << *loc_iter << ", ";
		}

		cout << "}\n";

	}
	cout << endl;
}