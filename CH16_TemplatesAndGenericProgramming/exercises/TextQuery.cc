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
#include <cstddef>

#include "TextQuery.h"
#include "DebugDelete.h"

using namespace std;

// read the input file and build the map of lines to lines numbers
// custom deleter may not use with std::make_shared, as it has an internal
// deleter which may not be replaced. As a result, keyword new is the only
// option to use with DebugDelete.
TextQuery::TextQuery(ifstream& is):
					file(new vector<string>(), DebugDelete())
{
	string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			word = cleanup_str(word);
			auto& lines = wm[word];
			if (lines == nullptr)
				lines.reset(new set<line_no>(), DebugDelete());
			lines->insert(n);
		}
	}
}

// int ispunct(int ch);
// Checks if the given character is a punctuation character in the current C locale.
// The default C locale classifies the characters !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~ as punctuation.
// The behavior is undefined if the value of ch is not representable as unsigned char and is not equal to EOF.
string TextQuery::cleanup_str(const string& word)
{
	string ret;
	for (auto it = word.begin(); it != word.end(); ++it) {
		if (!ispunct(*it)) {
			ret += tolower(*it);
		}
	}
	return ret;
}

QueryResult TextQuery::query(const string& sought) const
{
	// we will return a pointer to this set if we dont't find sought
	static auto nodata = make_shared<set<line_no>>();

	// use find and not a subscript to avoid adding words to wm!
	auto loc = wm.find(cleanup_str(sought));

	if (loc == wm.end()){
		return QueryResult(sought, nodata, file);
	} else {
		return QueryResult(sought, loc->second, file);
	}
}

void TextQuery::display_map()
{
	// auto iter = wm.cbegin();
	// auto iter_end = wm.cend();
	for (auto iter = wm.cbegin(); iter != wm.cend(); ++iter) {
		cout << "word: " << iter->first << " {";
		// fetch location vector as a cosnt reference to avoid coping it
		auto text_locs = iter->second;
		auto loc_iter = text_locs->cbegin();
		auto loc_iter_end = text_locs->cend();
		// print all line number for this word
		while (loc_iter != loc_iter_end) {
			cout << *loc_iter;

			if (++loc_iter != loc_iter_end)
				cout << ", ";
		}
		cout << "}\n";
	}

	cout << endl;
}

ostream& print(ostream& os, const QueryResult& qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
	   << "time(s)" << endl;

	// print each line in chich the word appeared
	for (auto num : *qr.lines) {
		os << "\t(line " << num + 1 << ") "
		   << *(qr.file->begin() + num) << endl;
	}

	return os;
}
