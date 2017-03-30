#pragma once

#include <DebugDelete.h>

namespace cplusplus_primer {
//! forward declarations for friendship
template<typename T, typename D>
class unique_ptr;
template<typename T, typename D>
void swap(unique_ptr<T, D>& lhs, unique_ptr<T, D>& rhs);

template <typename T, typename D = DebugDelete>
class unique_ptr
{
	friend void swap<T, D>(unique_ptr<T, D>& lhs, unique_ptr<T, D>& rhs);
public:
	// preventing copy and assignment
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator = (const unique_ptr&) = delete;

	// default constructor and one taking T*
	unique_ptr() = default;
	explicit unique_ptr(T* up): ptr(up) { }

	// move constructor
	unique_ptr(unique_ptr&& up) noexcept
		: ptr(up.ptr)   { up.ptr = nullptr; }

	// move assignment
	unique_ptr& operator=(unique_ptr&& rhs) noexcept;

	// std::nullptr_t assignment
	unique_ptr& operator=(std::nullptr_t n) noexcept;



	// operator overloaded :  *  ->  bool
	T& operator*() const   { return *ptr; }
	T* operator->() const   { return &this->operator*(); }
	operator bool() const   { return ptr ? true : false; }

	// return the underlying pointer
	T* get() const noexcept { return ptr; }

	// swap member using swap friend
	void swap(unique_ptr<T, D>& rhs) { cplusplus_primer::swap(*this, rhs); }

	// free and make it point to nullptr or to p's pointee.
	void reset() noexcept { deleter(ptr); ptr = nullptr; }
	void reset(T* p) noexcept { deleter(ptr); ptr = p; }

	// return ptr and make ptr point to nullptr.
	T* release();

	~unique_ptr() { deleter(ptr); }
private:
	T* ptr = nullptr;
	D  deleter = D();
};

// swap
template<typename T, typename D>
inline void swap(unique_ptr<T, D>& lhs, unique_ptr<T, D>& rhs)
{
	// using std::swap;
	std::swap(lhs.ptr, rhs.ptr);
	std::swap(lhs.deleter, rhs.deleter);
}

//! move assignment
template<typename T, typename D>
inline unique_ptr<T,D>& unique_ptr<T,D>::operator=(unique_ptr&& rhs) noexcept
{
	//! prevent self-assignment
	if (this->ptr != rhs.ptr) {
		deleter(ptr);
		ptr = nullptr;
		cplusplus_primer::swap(*this, rhs);
	}
	return *this;
}


//! std::nullptr_t assignment
template<typename T, typename D>
inline unique_ptr<T,D>& unique_ptr<T,D>::operator=(std::nullptr_t nptr) noexcept
{
	if (nptr == nullptr) {
		deleter(ptr);
		ptr = nullptr;
	}
	return *this;
}

 // relinquish contrul by returnning ptr and making ptr point to nullptr.
template<typename T, typename D>
inline T* unique_ptr<T, D>::release()
{
	T* ret = ptr;
	ptr = nullptr;
	return ret;
}

} // namespace cplusplus_primer

