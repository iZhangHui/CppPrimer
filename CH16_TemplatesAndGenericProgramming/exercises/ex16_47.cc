
/****************************************************************************
 *
 *   Copyright (c) 2017 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex16_47.cc
 *
 * Exercise 16.47
 *
 * Write your own version of the flip function and test it by
 * calling functions that have lvalue and rvalue reference parameters.
 *
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */

#include <utility>
#include <memory>
#include <iostream>
using namespace std;


// template< class T >
// constexpr typename std::remove_reference<T>::type&& move( T&& t );

// template< class T >
// constexpr T&& forward( typename std::remove_reference<T>::type&& t ) noexcept;



// template that takes a callable and two parameters
// and calls the given callable with the parameters ``flipped''
template <typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2)
{
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f(int v1, int& v2)  // note v2 is a reference
{
	cout << v1 << " " << ++v2 << endl;
}

void g(int&& i, int& j)
{
	cout << i << " " << j << endl;
}

// flip1 is an incomplete implementation: top-level const and references are lost
template <typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2)
{
	f(t2, t1);
}

template <typename F, typename T1, typename T2>
void flip2(F f, T1&& t1, T2&& t2)
{
	f(t2, t1);
}

/////////////////////////////////////////////////////////////////////////////////
void func_lvalue(std::string& lhs, std::string& rhs)
{
	lhs = "Primer";
	rhs = "C++";
}

void func_rvalue(int&& lhs, int&& rhs)
{
	// allocate enough space
	std::allocator<int> alloc;
	int* data = alloc.allocate(3);

	// move into the spaced newly allocated
	alloc.construct(data     , lhs);
	alloc.construct(data + 1 , 0);
	alloc.construct(data + 2 , rhs);

	// print
	for (auto p = data; p != data + 3;  ++p)
		std::cout << *p << "\n";

	// destroy and deallocation
	for (auto p = data + 3; p != data; --p)
		alloc.destroy(p);

	alloc.deallocate(data, 3);
}

int main(int argc, char const *argv[])
{
	int i = 0, j = 0, k = 0, l = 0;
	cout << i << " " << j << " " << k << " " << l << endl;

	f(42, i);        // f changes its argument i
	flip1(f, j, 42); // f called through flip1 leaves j unchanged
	flip2(f, k, 42); // ok: k is changed
	cout << "=========================================" << endl;
	g(1, i);
	flip(g, i, 42);  // ok: rvalue-ness of the third argument is preserved
	cout << i << " " << j << " " << k << " " << l << endl;
	cout << "=========================================" << endl;

	// test for lvalue reference
	string s1;
	string s2;
	flip(func_lvalue, s1, s2);
	cout << s1 << " " << s2 << endl;

	// test for rvalue reference
	flip(func_rvalue, 99, 88);

	// void flip1(F, T1, T2) [with F = void (*)(int&&, int&&); T1 = int; T2 = int]’:
	// ex16_47.cc:88:27:   required from here
	// ex16_47.cc:28:3: error: cannot bind ‘int’ lvalue to ‘int&&’
	// f(t2, t1);
	// ^
	// flip1(func_rvalue, 99, 88);

	return 0;
}
