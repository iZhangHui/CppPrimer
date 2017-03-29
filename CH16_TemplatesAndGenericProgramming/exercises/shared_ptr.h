#pragma once

#include <functional>
#include "DebugDelete.h"

namespace cpp_primer {
// forward declarations needed for friendship
template<typename T>
class shared_ptr;

template<typename T>
void swap(shared_ptr<T>& lhs, shared_ptr<T>& rhs);

// DebugDelete is the default deleter which can be replaced at run time
template <typename T>
class shared_ptr
{
	friend void swap<T>(shared_ptr<T>& lhs, shared_ptr<T>& rhs);
public:
	// default constructor
	shared_ptr() = default;

	// constructor taking raw pointer.
	// set the refCount as 1
	explicit shared_ptr(T* p, std::function<void(T*)> d = DebugDelete()):
		ptr(p), refCount(new std::size_t(1)), deleter(d) { }

	// copy constructor. increment useCount for each Copy
	shared_ptr(const shared_ptr& sp):
		ptr(sp.ptr), refCount(sp.refCount), deleter(sp.deleter)
	{
		++*refCount;
	}

	// copy assignment
	shared_ptr& operator=(const shared_ptr& rhs);

	// move constructor
	shared_ptr(shared_ptr&& sp) noexcept;

	// move assignment
	shared_ptr& operator=(shared_ptr&& rhs) noexcept;

	// conversion operator
	operator bool() const { return ptr ? true : false;}

	// dereference
	T& operator* () const { return *ptr; }

	// arrow
	T* operator->() const { return &this->operator*(); }

	// return useCount
	std::size_t use_count() const { return *refCount; }

	// get the underlying pointer
	T* get() const noexcept { return ptr; }

	// check if the unique user
	bool unique() const noexcept { return *refCount == 1;}

	// swap
	void swap(shared_ptr& rhs) { cpp_primer::swap(*this, rhs); }

	// if unique user, free the object pointed to
	void reset() noexcept { decrement_n_destroy(); }

	// make prt point where p pointing and create a new coount for it
	void reset(T* p)
	{
		if (ptr != p) {
			decrement_n_destroy();
			ptr = p;
			refCount = new std::size_t(1);
		}
	}

	// reset to point where p is pointing and change deleter to d.
	void reset(T* p, const std::function<void(T*)>& d)
	{
		reset(p);
		deleter = d;
	}

	// destructor
	~shared_ptr()
	{
		decrement_n_destroy();
	}

private:
	// data structure
	T* ptr = nullptr;
	std::size_t* refCount = new std::size_t(0);

	// any functor lambda or function pointer that matched this
	// signature can replace the default one at run time.
	std::function<void(T*)> deleter{DebugDelete()};
	//  signature ^^^^^^^^         ^~~~~~~~~~~~~~^
	//                          here: = doesn't work, another way is initializing it in constructor.
	//  utilities
	void decrement_n_destroy();
};

template <typename T>
inline void swap(shared_ptr<T>& lhs, shared_ptr<T>& rhs)
{
	// using std::swap;
	std::swap(lhs.ptr, rhs.ptr);
	std::swap(lhs.refCount, rhs.refCount);
	std::swap(lhs.deleter, rhs.deleter);
}

// move constructor
template<typename T>
inline shared_ptr<T>::shared_ptr(shared_ptr&& sp) noexcept:
	ptr(sp.ptr), refCount(sp.refCount), deleter(std::move(sp.deleter))
{
	sp.ptr = nullptr;
	sp.refCount = nullptr;
}

// copy assignment
template<typename T>
inline shared_ptr<T>& shared_ptr<T>::operator=(const shared_ptr& rhs)
{
	// increment rhs.refCount first to ensure safty when self-assignment
	++*rhs.refCount;

	// for lhs:
	decrement_n_destroy();

	// copy datastructure from rhs to this.
	ptr = rhs.ptr;
	refCount = rhs.refCount;
	deleter  = rhs.deleter;

	return *this;
}


// move assignment
template<typename T>
inline shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr&& rhs) noexcept
{
	// for lhs
	decrement_n_destroy();

	// swap two sides
	cpp_primer::swap(*this, rhs);

	// std::cout << "shared_ptr::move=\n";
	return *this;
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, shared_ptr<T> p)
{
	os << p.get();
	return os;
}


// utilities for decrement and delete using deleter.
template <typename T>
inline void shared_ptr<T>::decrement_n_destroy()
{
	if (ptr != nullptr) {
		if (--*refCount == 0) {
			delete refCount;
			deleter(ptr);
		}
		refCount = nullptr;
		ptr = nullptr;
	}
}

} // namespace cpp_primer
