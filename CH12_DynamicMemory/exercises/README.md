# Chapter 12. Dynamic Memory

## Exercise 12.1:
>How many elements do b1 and b2 have at the end of this code?
```cpp
StrBlob b1;
{
	StrBlob b2 = { "a", "an", "the" };
	b1 = b2;
	b2.push_back("about");
}
```

At the end of this code,
 * `b1` holds 4 elements;
 * `b2` has been destroyed automatically. So it's meaningless to say how many elements in `b2`.

## Exercise 12.2
>Write your own version of the StrBlob class including the
const versions of front and back.

[StrBlob](ex12_02.h) | [Test](ex12_02_test.cpp)

## Exercise 12.3
>Does this class need const versions of push_back and pop_back? If so, add them. If not, why aren’t they needed?
You can certainly do this if you want to, but there doesn't seem to be any
logical reason. The compiler doesn't complain because this doesn't modify
data (which is a pointer) but rather the thing data points to, which is
perfectly legal to do with a const pointer. by David Schwartz.

-----

Discussion over this exercise on [Stack Overflow](http://stackoverflow.com/questions/20725190/operating-on-dynamic-memory-is-it-meaningful-to-overload-a-const-memeber-functi)

Discussion over this exercise more on [douban](http://www.douban.com/group/topic/61573279/)(chinese)

## Exercise 12.4
>In our check function we didn’t check whether i was greater than zero. Why is it okay to omit that check?

Because the type of `i` is `std::vector<std::string>::size_type` which
is an `unsigned`.When any argument less than 0 is passed in, it will convert
to a number greater than 0. In short `std::vector<std::string>::size_type`
will ensure it is a positive number or 0.

## Exercise 12.5
>We did not make the constructor that takes an initializer_list explicit (§ 7.5.4, p. 296). Discuss the pros and ons of this design choice

keyword `explicit` prevents automatic conversion from an `initializer_list` to `StrBlob`.
This design choice would easy to use but hard to debug.

**Pros**

- The compiler will not use this constructor **in an automatic conversion**.
- We can realize clearly which class we have used.

**Cons**

- We always uses the constructor to construct **a temporary StrBlob object**.
- cannot use the copy form of initialization with an explicit constructor. not easy to use.

```cpp
string null_book = "9-999-99999-9";
// constructs a temporary Sales_data object
// with units_sold and revenue equal to 0 and bookNo equal to null_book
item.combine(null_book);
....

Sales_data& Sales_data::combine(const Sales_data& rhs)
{ ... }
```

##[Exercise 12.6](ex12_06.cpp)
>Write a function that returns a dynamically allocated vector
of ints. Pass that vector to another function that reads the standard input
to give values to the elements. Pass the vector to another function to print
the values that were read. Remember to delete the vector at the appropriate time.

##[Exercise 12.7](ex12_07.cpp)
>Redo the previous exercise, this time using shared_ptr.

## Exercise 12.8
>Explain what if anything is wrong with the following function.

```cpp
bool b() {
int* p = new int;
// ...
return p;
}
```

The p will convert to a bool , which means that the dynamic memory allocated has no chance to be freed. As a result, memory leakage will occur.

## Exercise 12.9
>Explain what happens in the following code:

```cpp
int *q = new int(42), *r = new int(100);
r = q;
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
```
- to `q` and `r`:

Memory leakage happens. Because after `r = q` was executed, no pointer points to the int `r` had pointed to. It implies that no chance to free the memory for it.

- to `q2` and `r2`:

It's safe. Because after 'r2 = q2', the reference count belongs to r2 reduce to 0 and the reference count belongs to q2 increase to 2, then the memory allocated by r2 will be released automatically.


## [Exercise 12.10](ex12_10.cpp)
>Explain whether the following call to the process function
defined on page 464 is correct. If not, how would you correct the call?

```cpp
shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));
```

Correct.

## [Exercise 12.11](ex12_11.cpp)
>What would happen if we called process as follows?

```cpp
process(shared_ptr<int>(p.get()));
```

shared_ptr<int>(p.get()) construct a temporary shared_ptr and copy it
to the parameter.However it is not a copy of p. As a result, at end of this
main function p will free the memory that has been freed inside process ().
That's why "double freed or corruption" was generated.

## [Exercise 12.12](ex12_12.cpp)
>Using the declarations of p and sp explain each of the following calls to process.
If the call is legal, explain what it does. If the call is illegal, explain why:

```cpp
auto p = new int();
auto sp = make_shared<int>();
(a) process(sp);
(b) process(new int());
(c) process(p);
(d) process(shared_ptr<int>(p));
```

(a) legal. Just copy sp which is a shared_ptr to process().
(b) illegale. plain pointer can not convert to smart pointer implicitly.
(c) illegale. plain pointer can not convert to smart pointer implicitly.
(d) Legal. But it's a bad practice to do so. Because using smart pointer
together with raw pointer could potentially cause problems.
For example double free as shown in [Exercise 12.11](ex12_11.cpp)


## [Exercise 12.13](ex12_13.cpp)
>What happens if we execute the following code?

```cpp
auto sp = make_shared<int>();
auto p = sp.get();
delete p;
```

generate a runtime error : double free

## [Exercise 12.14](ex12_14.cpp)
>Write your own version of a function that uses a shared_ptr to manage a connection.

## [Exercise 12.15](ex12_15.cpp)
>Rewrite the first exercise to use a lambda (§ 10.3.2, p.388) in place of the end_connection function.


