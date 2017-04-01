# Chapter 16. Templates and Generic Programming

## Exercise 16.1:
>Define instantiation.

When the compiler instantiates a template, it creates a new “instance”
of the template using the actual template argument(s) in place of the
corresponding template parameter(s).

## [Exercise 16.2](ex16_02_03.cc)
>Write and test your own versions of the compare functions.

## [Exercise 16.3](ex16_02_03.cc)
>Call your compare function on two Sales_data objects to see how your
compiler handles errors during instantiation.

## [Exercise 16.4](ex16_04.cc)
>Write a template that acts like the library find algorithm.
The function will need two template type parameters, one to represent the
function’s iterator parameters and the other for the type of the value. Use
your function to find a given value in a vector<int> and in a
list<string.

## [Exercise 16.5](ex16_05.cc)
>Write a template version of the print function from § 6.2.4
(p. 217) that takes a reference to an array and can handle arrays of any size
and any element type.

## [Exercise 16.6](ex16_06.cc)
>How do you think the library begin and end functions that
take an array argument work? Define your own versions of these functions.

## [Exercise 16.7](ex16_07.cc)
>Write a constexpr template that returns the size of a given
array.

## Exercise 16.8
>In the “Key Concept” box on page 108, we noted that as a
matter of habit C++ programmers prefer using != to using <. Explain the
rationale for this habit.

The reason is that more class defines "!=" rather than "<". Doing so can
reduce the number of requirement of the class used with a template class.

## Exercise 16.9
>What is a function template? What is a class template?

A function template is a formula from which we can generate type-specific
versions of that function.

A class template is a blueprint for generating classes. Class templates
differ from function templates in that the compiler cannot deduce the
template parameter type(s) for a class template. Instead, as we’ve seen
many times, to use a class template we must supply additional information
inside angle brackets following the template’s name (§ 3.3, p. 97).

## Exercise 16.10
>What happens when a class template is instantiated?

The compiler uses these template arguments to instantiate a specific
class from the template.

## [Exercise 16.11](ex16_11.cc)
>The following definition of List is incorrect. How would
you fix it?
```cpp
template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
	List<elemType>();
	List<elemType>(const List<elemType>&);
	List<elemType>& operator=(const List<elemType>&);
	~List();
	void insert(ListItem* ptr, elemType value);
private:
	ListItem *front, *end;
};
```

## [Exercise 16.12](ex16_12_13.h)
>Write your own version of the Blob and BlobPtr
templates. including the various const members that were not shown in the
text.

## [Exercise 16.13](ex16_12_13.h)
>Explain which kind of friendship you chose for the equality
and relational operators for BlobPtr.

## [Exercise 16.14](ex16_14_15.h)
>Write a Screen class template that uses nontype
parameters to define the height and width of the Screen.

## [Exercise 16.15](ex16_14_15.h)
>Implement input and output operators for your Screen
template. Which, if any, friends are necessary in class Screen to make the
input and output operators work? Explain why each friend declaration, if any,
was needed.

## [Exercise 16.16](ex16_16.h)
>Rewrite the StrVec class (§ 13.5, p. 526) as a template
named Vec.

## Exercise 16.17
>What, if any, are the differences between a type parameter
that is declared as a typename and one that is declared as a class? When
must typename be used?

There is no difference. typename and class are interchangeable in the
declaration of a type template parameter.
If we want to use a type member of a template type parameter,
we must explicitly tell the compiler that the name is a type.
We do so by using the keyword typename.

## [Exercise 16.18](ex16_18.cc)
>Explain each of the following function template declarations
and identify whether any are illegal. Correct each error that you find.
```cpp
(a) template <typename T, U, typename V> void f1(T, U, V);
(b) template <typename T> T f2(int &T);
(c) inline template <typename T> T foo(T, unsigned int*);
(d) template <typename T> f4(T, T);
(e) typedef char Ctype;
template <typename Ctype> Ctype f5(Ctype a);
```

## [Exercise 16.19](ex16_19_20.cc)
>Write a function that takes a reference to a container and
prints the elements in that container. Use the container’s size_type and
size members to control the loop that prints the elements.

## [Exercise 16.20](ex16_19_20.cc)
>Rewrite the function from the previous exercise to use
iterators returned from begin and end to control the loop.

## [Exercise 16.21](DebugDelete.h)
>Write your own version of DebugDelete.

## [Exercise 16.22](TextQuery.cc)
>Revise your TextQuery programs from § 12.3 (p. 484) so
that the shared_ptr members use a DebugDelete as their deleter (§
12.1.4, p. 468).

## Exercise 16.23
>Predict when the call operator will be executed in your
main query program. If your expectations and what happens differ, be sure
you understand why.

## [Exercise 16.24](ex16_24.h)
>Add a constructor that takes two iterators to your Blob
template.

## Exercise 16.25
>Explain the meaning of these declarations:
```cpp
extern template class vector<string>;
template class vector<Sales_data>;
```

```
cppextern template class vector<string>;
```
instantiation declaration. The definition of it is somewhere else
```cpp
template class vector<Sales_data>;
```
instantiation definition. The compiler will generate codes for it.

## [Exercise 16.26](ex16_26.cc)
>Assuming NoDefault is a class that does not have a
default constructor, can we explicitly instantiate vector<NoDefault>? If
not, why not?

C++11 introduces a new constructor, vector(size_type n),
and "obviously" that constructor can't be instantiated unless the value_type is default-constructible.
It was vector(size_type n, const T & = T(), const Allocator& alloc = Allocator()) in C++03,
but they changed it to two separate constructors. A similar change was made to resize().

In GCC and as far as I know also per the standard: the vector template can be at least implicitly instantiated
without the elements being default constructible. Implicit template class instantiation only instantiates the member functions you use.

In C++03 only the default arguments use default construction. You can explicitly instantiate the template,
but you won't be able to call those functions without providing a value for that parameter.

So I'm pretty sure that change is what prevents vector<NoDefault> being explicitly instantiated in C++11
(and I suppose the allocator type needs to be default-constructible too). But I might have missed something.
It seems a little odd to make that change given that it introduces this backward incompatibility.
There's probably a proposal somewhere that justifies it if you want a deeper reason why this no longer
works as opposed to just why this doesn't work :-)

Answer above is copied from [StackOverflow](http://stackoverflow.com/questions/21525169/while-explicitly-instantiating-vectorsometype-what-is-the-sometype-default-co)

## Exercise 16.27
>For each labeled statement explain what, if any,
instantiations happen. If a template is instantiated, explain why; if not,
explain why not.
```
template <typename T> class Stack { };
void f1(Stack<char>); // (a)
class Exercise {
	Stack<double> &rsd; // (b)
	Stack<int> si; // (c)
};
int main() {
	Stack<char> *sc; // (d)
	f1(*sc); // (e)
	int iObj = sizeof(Stack< string >); // (f)
}
```

## [Exercise 16.28](shared_ptr.h)
>Write your own versions of shared_ptr and unique_ptr.

## [Exercise 16.29](Blob.h)
>Revise your Blob class to use your version of shared_ptr rather than the library version.

## [Exercise 16.30](ex16_30_31.cc)
>Rerun some of your programs to verify your shared_ptr
and revised Blob classes. (Note: Implementing the weak_ptr type is
beyond the scope of this Primer, so you will not be able to use the BlobPtr
class with your revised Blob.)

## [Exercise 16.31](ex16_30_31.cc)
>Explain how the compiler might inline the call to the deleter
if we used DebugDelete with unique_ptr.

## Exercise 16.32
>What happens during template argument deduction?

The process of determining the template arguments from the function arguments
is known as template argument deduction. During template argument deduction,
the compiler uses types of the arguments in the call to find the template
arguments that generate a version of the function that best matches the given
call.

## Exercise 16.33
>Name two type conversions allowed on function arguments
involved in template argument deduction.

• const conversions: A function parameter that is a reference (or pointer)
  to a const can be passed a reference (or pointer) to a nonconst object
  (§ 4.11.2, p. 162).

• Array- or function-to-pointer conversions: If the function parameter is
  not a reference type, then the normal pointer conversion will be applied
  to arguments of array or function type. An array argument will be converted
  to a pointer to its first element. Similarly, a function argument will be
  converted to a pointer to the function’s type (§ 4.11.2, p. 161).

## [Exercise 16.34](ex16_34.cc)
>Given only the following code, explain whether each of
these calls is legal. If so, what is the type of T? If not, why not?
```cpp
template <class T> int compare(const T&, const T&);
(a) compare("hi", "world");
(b) compare("bye", "dad");
```
```cpp
template <class T>
int compare(const T&, const T&);
compare("hi", "world");
```
It didn't complie, as two types are different, the first type being char[3] , second char[6]
```cpp
compare("bye", "dad");
```
the type should be pointer to char i.e. char*

## Exercise 16.35
>Which, if any, of the following calls are errors? If the call is
legal, what is the type of T? If the call is not legal, what is the problem?
```cpp
template <typename T> T calc(T, int);
template <typename T> T fcn(T, T);
double d; float f; char c;
(a) calc(c, 'c');
(b) calc(d, f);
(c) fcn(c, 'c');
(d) fcn(d, f);
```
(a) calc(c, 'c');   -- legal, T is a char

(b) calc(d, f);     -- legal, T is a double

(c) fcn(c, 'c');    -- legal, T is a char

(d) fcn(d, f);      -- illegal, arguments d and f are double and float repectively

## Exercise 16.36
>What happens in the following calls:
```cpp
template <typename T>
f1(T, T);
template <typename T1, typename T2)
f2(T1, T2);
int i = 0, j = 42, *p1 = &i, *p2 = &j;
const int *cp1 = &i, *cp2 = &j;
(a) f1(p1, p2);
(b) f2(p1, p2);
(c) f1(cp1, cp2);
(d) f2(cp1, cp2);
(e) f1(p1, cp1);
(f) f2(p1, cp1);
```

(a) f1(p1, p2);     // f1<int*>(int*, int*)

(b) f2(p1, p2);     // f2<int*, int*>(int*, int*)

(c) f1(cp1, cp2);   // f1<int const*>(int const*, int const*)

(d) f2(cp1, cp2);   // f2<int const*, int const*>(int const*, int const*)

(e) f1(p1, cp1);    // deduced conflicting types for parameter 'T'

(f) f2(p1, cp1);    // f2<int*, int const*>(int*, int const*)

## [Exercise 16.37](ex16_37.cc)
>The library max function has two function parameters and returns the larger of its arguments.
This function has one template type parameter. Could you call max passing it an int and a double?
If so, how? If not, why not?

If we explicitly specify the template parameter type, normal
conversions apply. Thus, the call to max<long> is equivalent to calling a
function taking two const long& parameters. The int parameter is automatically
converted to long.

## Exercise 16.38
>When we call make_shared (§ 12.1.1, p. 451), we have to
provide an explicit template argument. Explain why that argument is needed
and how it is used.

without specified type given, make_shared has no possibility to to determine
how big the size it should allocate, which is the reason.

Depending on the type specified, make_shared allocates proper size of memory
space and returns a proper type of shared_ptr pointing to it.

## [Exercise 16.39](ex16_39.cc)
>Use an explicit template argument to make it sensible to
pass two string literals to the original version of compare from § 16.1.1 (p.
652).

## [Exercise 16.40](ex16_40.cc)
>Is the following function legal? If not, why not? If it is
legal, what, if any, are the restrictions on the argument type(s) that can be
passed, and what is the return type?
```cpp
template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
	// process the range
	return *beg; // return a copy of an element from the range
}
```

legal. Only type that support this + 0 operation can be passed.
the return type depends on the what type the operator + returns.


## [Exercise 16.41](ex16_41.cc)
>Write a version of sum with a return type that is
guaranteed to be large enough to hold the result of the addition.

## Exercise 16.42
>Determine the type of T and of val in each of the
following calls:
```cpp
template <typename T> void g(T&& val);
int i = 0; const int ci = i;
(a) g(i);
(b) g(ci);
(c) g(i * ci);
```

(a) g(i);

since i is lvalue, T is deduced as int&, val is int& && collapsing to int&

(b) g(ci);

since ci is lvaue, T is deduced as const int&, val is const int& && collapsing to const int&

(c) g(i * ci);

since i * ci is rvalue, T is deduced as int, val is int&& && colapsing to int&&


## Exercise 16.43
>Using the function defined in the previous exercise, what
would the template parameter of g be if we called g(i = ci)?

(i = ci) returns lvalue refering to the object i.
Hence T is deduced as int& val is int& && .
any change on val changes the object i.


## Exercise 16.44
>Using the same three calls as in the first exercise,
determine the types for T if g’s function parameter is declared as T (not
T&&). What if g’s function parameter is const T&?

if g’s function parameter is declared as T (not T&&).
                                         ^
- g(i);       --  T is deduced as int
- g(ci);      --  T is deduced as int, const is ignored.
- g(i * ci);  --  T is deduced as int, (i * ci) returns rvalue which is copied to T

What if g’s function parameter is const T&?
                                    ^^^^^^^^
- g(i)        --  T is deduced as int  , val : const int&
- g(ci)       --  T is deduced as int  , val : const int&
- g(i * ci)   --  T is deduced as int  , val : const int&(see example on page 687)


## Exercise 16.45
>Given the following template, explain what happens if we
call g on a literal value such as 42. What if we call g on a variable of type
int?
```cpp
template <typename T> void g(T&& val) { vector<T> v; }
```

When we pass an lvalue (e.g., i) to a function parameter that is an rvalue reference to a
template type parameter (e.g, T&&), the compiler deduces the template type parameter as the
argument’s lvalue reference type. So, when we call f3(i), the compiler deduces the type of
T as int&, not int.        --  P.688

In this case, when calling on a literal value, say 42. int&& && will collapse to int&&. At last
T is deduced as int. Hence std::vector<T> is instantiated as std::vector<int> which is legal.

When calling on a variable int. T will be deduced as int&. int & && will collapse to int&.
std::vector<int&> is illegal. The reason why int& can't be element of a vector can be found at:

http://stackoverflow.com/questions/922360/why-cant-i-make-a-vector-of-references

The component type of containers like vectors must be Assignable.
References are not assignable (you can only initialize them once
when they are declared, and you cannot make them reference something else later).
Other non-assignable types are also not allowed as components of containers,
e.g. vector<const int> is not allowed.

## Exercise 16.46
>Explain this loop from StrVec::reallocate in § 13.5 (p.
530):
```cpp
for (size_t i = 0; i != size(); ++i)
	alloc.construct(dest++, std::move(*elem++));
```

In each iteration, the dereference operator * returns a lvalue which is changed to rvalue by
std::move , becasue the member function construct takes rvalue reference rather than lvalue
reference.
```
template< class U, class... Args >
void construct( U* p, Args&&... args );
```

## [Exercise 16.47](ex16_47.cc)
>Write your own version of the flip function and test it by
calling functions that have lvalue and rvalue reference parameters.

## [Exercise 16.48](ex16_48.c)
>Write your own versions of the debug_rep functions.

## Exercise 16.49
>Explain what happens in each of the following calls:
```cpp
template <typename T> void f(T);
template <typename T> void f(const T*);
template <typename T> void g(T);
template <typename T> void g(T*);
int i = 42, *p = &i;
const int ci = 0, *p2 = &ci;
g(42); g(p); g(ci); g(p2);
f(42); f(p); f(ci); f(p2);
```

g(42);   g(p);  // g(T) g(T*)

g(ci);   g(p2); // g(T) g(T*)

f(42);   f(p);  // f(T) f(T)

f(ci);   f(p2); // f(T) f(T*)

## [Exercise 16.50](../examples/special.cc)
>Define the functions from the previous exercise so that they
print an identifying message. Run the code from that exercise. If the calls
behave differently from what you expected, make sure you understand why.

## Exercise 16.51
>Determine what sizeof...(Args) and
sizeof...(rest) return for each call to foo in this section.

## Exercise 16.52
>Write a program to check your answer to the previous
question.

## Exercise 16.53
>Write your own version of the print functions and test
them by printing one, two, and five arguments, each of which should have
different types.

## Exercise 16.54
>What happens if we call print on a type that doesn’t have
an << operator?

## Exercise 16.55
>Explain how the variadic version of print would execute if
we declared the nonvariadic version of print after the definition of the
variadic version.

## Exercise 16.56
>Write and test a variadic version of errorMsg.

## Exercise 16.57
>Compare your variadic version of errorMsg to the
error_msg function in § 6.2.6 (p. 220). What are the advantages and
disadvantages of each approach?

## Exercise 16.58
>Write the emplace_back function for your StrVec class
and for the Vec class that you wrote for the exercises in § 16.1.2 (p. 668).

## Exercise 16.59
>Assuming s is a string, explain svec.emplace_back(s).

## Exercise 16.60
>Explain how make_shared (§ 12.1.1, p. 451) works.

## Exercise 16.61
>Define your own version of make_shared.

## Exercise 16.62
>Define your own version of hash<Sales_data> and define an unordered_multiset of Sales_data objects.
Put several transactions into the container and print its contents.

## Exercise 16.63
>Define a function template to count the number of occurrences of a given value in a vector.
Test your program by passing it a vector of doubles, a vector of ints, and a vector of strings.

## Exercise 16.64
>Write a specialized version of the template from the previous exercise to handle
vector<const char*> and a program that uses this specialization.

## Exercise 16.65
>In § 16.3 (p. 698) we defined overloaded two versions of debug_rep one had a const char* and
the other a char* parameter. Rewrite these functions as specializations.

## Exercise 16.66
>What are the advantages and disadvantages of overloading these debug_rep functions as compared to defining specializations?

## Exercise 16.67
>Would defining these specializations affect function matching for debug_rep? If so, how? If not, why not?





