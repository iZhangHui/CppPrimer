#include <vector>
#include <memory>
#include <initializer_list>
#include <iterator>
#include "shared_ptr.h"

template <typename>
class Blob; // needed for parameters in operator==

template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T>
class Blob
{
	// each instantiation of Blob grants access to the version of
	// BlobPtr and the equality operator instantiated with the same type
	// friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
	using size_type = typename std::vector<T>::size_type;

	// constructors
	Blob() : data(new std::vector<T>) { }
	Blob(std::initializer_list<T> il)
		: data(new std::vector<T>(il)) { }
	Blob(T* p, std::size_t n) : data(new std::vector<T>(p, p + n)) { };

	template <typename It>
	Blob(It b, It e) : data(new std::vector<T>(b, e)) { };

	// number of elements in the Blob
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	// add and remove elements
	// void push_back(const T& t) { data->push_back(t); }
	// void push_back(T&& t) { data->push_back(std::move(t)); }
	void push_back(T&& t) { data->push_back(std::forward<T>(t)); }
	void pop_back();

	// element access
	T& front();
	T& back();
	T& at(size_type);
	T& operator[](size_type i);
	const T& front() const;
	const T& back() const;
	const T& at(size_type) const;
	const T& operator[](size_type i) const;

	void swap(Blob& b) { data.swap(b.data); }

	// return BlobPtr to the first and one past the last elements
	// BlobPtr<T> begin() { return BlobPtr<T>(*this); }
	// BlobPtr<T> end() { return BlobPtr<T>(*this, data->size()); }

private:
	cpp_primer::shared_ptr<std::vector<T>> data;
	// throw msg if data[i] isn't valid
	void check(size_type i, const std::string& msg) const;
};

// check member
template <typename T>
void Blob<T>::check(size_type i, const std::string& msg) const
{
	if (i >= data->size()) {
		throw std::out_of_range(msg);
	}
}

template <typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

// element access members
template <typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
const T& Blob<T>::back() const
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
T& Blob<T>::front()
{
	// if the vector is empty, check will throw
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
const T& Blob<T>::front() const
{
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
	// if i is too big, check will throw, preventing access to a nonexistent element
	check(i, "subscript out of range");
	return (*data)[i]; // (*data) is the vector to which this object points
}

template <typename T>
const T& Blob<T>::operator[](size_type i) const
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
T& Blob<T>::at(size_type i)
{
	// if i is too big, check will throw, preventing access to a nonexistent element
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
const T& Blob<T>::at(size_type i) const
{
	check(i, "subscript out of range");
	return (*data)[i];
}

// operators
template <typename T>
std::ostream& operator<<(std::ostream& os, const Blob<T>& a)
{
	os << "< ";
	for (size_t i = 0; i != a.size(); ++i)
		os << a[i] << " ";
	os << " >";
	return os;
}

template <typename T>
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs)
{
	if (rhs.size() != lhs.size())
		return false;
	for (size_t i = 0; i < lhs.size(); ++i)
		if (lhs[i] != rhs[i])
			return false;

	return true;
}
