#include <vector>
#include <memory>
#include <initializer_list>
#include <iterator>

// forward declarations needed for friend decalarations in Blob
template <typename>
class BlobPtr;

template <typename>
class Blob; // needed for parameters in operator==

template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T>
class Blob
{
	// each instantiation of Blob grants access to the version of
	// BlobPtr and the equality operator instantiated with the same type
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
	using size_type = typename std::vector<T>::size_type;

	// constructors
	Blob() : data(std::make_shared<std::vector<T>>()) { }
	Blob(std::initializer_list<T> il)
		: data(std::make_shared<std::vector<T>>(il)) { }
	Blob(T* p, std::size_t n) : data(std::make_shared<std::vector<T>>(p, p + n)) { };

	template <typename It>
	Blob(It b, It e) : data(std::make_shared<std::vector<T>>(b, e)) { };

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
	BlobPtr<T> begin() { return BlobPtr<T>(*this); }
	BlobPtr<T> end() { return BlobPtr<T>(*this, data->size()); }

private:
	std::shared_ptr<std::vector<T>> data;
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

/////////////////////////////////////////////////////////////////////////////

// BlobPtr throws an exception on attempts to access a nonexistent element
template <typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T>
class BlobPtr //: public std::iterator<std::bidirectional_iterator_tag, T>
{
	friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
	BlobPtr() : curr(0) { }
	BlobPtr(Blob<T>& a, size_t sz = 0):
		wptr(a.data), curr(sz) { }

	T& operator[](std::size_t i)
	{
		auto p = check(i, "subscript out of range");
		return (*p)[i];
	}

	const T& operator[](std::size_t i) const
	{
		auto p = check(i, "subscript out of range");
		return (*p)[i];
	}

	T& operator*() const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}

	T* operator->()
	{
		// delegate the real work to the dereference operator
		return & this->operator*();
	}

	// increment and decrement
	// prefix
	BlobPtr& operator++();
	BlobPtr& operator--();

	// postfix
	BlobPtr operator++(int);
	BlobPtr operator--(int);
private:
	std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};

// equality operators
template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	// std::shared_ptr<T> lock() const;(since C++11)
	// Creates a new std::shared_ptr that shares ownership of the managed object.
	// If there is no managed object, i.e. *this is empty, then the returned shared_ptr also is empty.
	// Effectively returns expired() ? shared_ptr<T>() : shared_ptr<T>(*this), executed atomically.
	return lhs.wptr.lock().get() == rhs.wptr.lock().get() && lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return !(lhs == rhs);
}


template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string& msg) const
{
	// is the vector still around?
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");

	if (i >= ret->size())
		throw std::out_of_range(msg);

	// otherwise, return a shared_ptr to the vector
	return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "increment past end of BlobPtr");
	++curr;
	return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	--curr;
	check(curr, "decrement past begin of BlobPtr");
	return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	BlobPtr ret = *this;
	++*this;
	return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
	BlobPtr ret = *this;
	--*this;
	return ret;
}