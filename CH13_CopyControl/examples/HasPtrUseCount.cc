/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 *
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 *
 *
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 *
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address:
 *
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/

// reference counted version of HasPtr
#include <string>

#include <cstddef>

#include <iostream>

class HasPtr {
public:
	// constructor allocates a new string and a new counter,
	// which it sets to 1
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0), use(new std::size_t(1))
	{
		std::cout << "default constructor." << std::endl;
	}

	// copy constructor copies all three data members
	// and increments the counter
	HasPtr(const HasPtr& p) :
		ps(p.ps), i(p.i), use(p.use)
	{
		std::cout << "copy constructor" << std::endl;
		++*use;
	}

	HasPtr& operator=(const HasPtr&);

	~HasPtr();

	// move constructor takes over the pointers from its argument
	// and makes the argument safe to delete
	HasPtr(HasPtr&& p): ps(p.ps), i(p.i), use(p.use)
	{
		std::cout << "move constructor." << std::endl;
		p.ps = nullptr;
		++*p.use;
	}

	HasPtr& operator=(HasPtr&&);

private:
	std::string* ps;
	int    i;
	std::size_t* use;  // member to track how many objects share *ps
};

HasPtr::~HasPtr()
{
	std::cout << "deconstructor." << std::endl;
	if (--*use == 0) {   // if the reference count goes to 0
		std::cout << "delete memory." << std::endl;
		delete ps;       // delete the string
		delete use;      // and the counter
	}
}

HasPtr& HasPtr::operator=(HasPtr&& rhs)
{
	std::cout << "move assign." << std::endl;
	if (this != &rhs) {
		if (--*use == 0) {   // do the work of the destructor
			delete ps;
			delete use;
		}
		ps = rhs.ps;         // do the work of the move constructor
		i = rhs.i;
		use = rhs.use;

		rhs.ps = nullptr;
		++*rhs.use;
	}
	return *this;
}

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	std::cout << "copy assign." << std::endl;
	++*rhs.use;  // increment the use count of the right-hand operand
	if (--*use == 0) {   // then decrement this object's counter
		delete ps;       // if no other users
		delete use;      // free this object's allocated members
	}
	ps = rhs.ps;         // copy data from rhs into this object
	i = rhs.i;
	use = rhs.use;
	return *this;        // return this object
}

HasPtr f(HasPtr hp) // HasPtr passed by value, so it is copied
{
	HasPtr ret;
	ret = hp;        // assignment copies the given HasPtr
	// proces ret
	return ret;      // ret and hp are destroyed
}

int main()
{
	HasPtr h("hi mom!");

	// no new memory is allocated,
	// h and h2 share the same underlying string
	HasPtr h2 = h;

	HasPtr h3 = std::move(h2);

}

