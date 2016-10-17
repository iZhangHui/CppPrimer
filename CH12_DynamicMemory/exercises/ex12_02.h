/****************************************************************************
 *
 *   Copyright (c) 2016 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex12_02.h
 *
 * Write your own version of the StrBlob class including the const versions of
 * front and back.
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>

class StrBlob {
public:
	// typedef std::vector<std::string>::size_type size_type;
	using size_type = std::vector<std::string>::size_type;
	StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
	StrBlob(std::initializer_list<std::string> il)
			: data(std::make_shared<std::vector<std::string>>(il)) { }
	size_type size() const { return data->size(); }
	bool empty() const {return data->empty(); }

	// add and remove elements
	void push_back(const std::string& t) { data->push_back(t); }
	void pop_back()
	{
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}

	//elements access
	std::string& front()
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}
	const std::string& front() const
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}

	std::string& back()
	{
		check(0, "front on empty StrBlob");
		return data->back();
	}

	const std::string& back() const
	{
		check(0, "front on empty StrBlob");
		return data->back();
	}
private:
	std::shared_ptr<std::vector<std::string>> data;
	// throws msg if data[i] isn't valid
	void check(size_type i, const std::string& msg) const
	{
		if (i >= data->size()) {
			throw std::out_of_range(msg);
		}
	}
};
