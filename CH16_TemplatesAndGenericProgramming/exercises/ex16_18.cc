/****************************************************************************
 *
 *   Copyright (c) 2017 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex16_18.cc
 *
 * Explain each of the following function template declarations
 * and identify whether any are illegal. Correct each error that you find.
 *
	*	(a) template <typename T, U, typename V> void f1(T, U, V);
	*	(b) template <typename T> T f2(int &T);
	*	(c) inline template <typename T> T foo(T, unsigned int*);
	*	(d) template <typename T> f4(T, T);
	*	(e) typedef char Ctype;
	*	template <typename Ctype> Ctype f5(Ctype a);

 *
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */


template <typename T, typename U, typename V> void f1(T, U, V);
//                   ^^^^^^^^ added to fix the error

template <typename T> T f2(T&);
//                        ^^

template <typename T> inline T foo(T, unsigned int*);
//                   ^^^^^^ inline must be after template

template <typename T> T f4(T, T);
//                   ^ -- return type must be provided

typedef char Ctype;
//          ^^^^^
//the template declatation below hides this typedef
template <typename Ctype> Ctype f5(Ctype a);

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
