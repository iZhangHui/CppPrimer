##Exercise 1.1

> Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the main program from page 2.

 * [GCC and File Extensions](http://labor-liber.org/en/gnu-linux/development/extensions)

##[Exercise 1.2](ex01_02.cc)

> Exercise 1.2: Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from main.

###Linux

![linux](https://cloud.githubusercontent.com/assets/6889915/19635145/db47c61a-99f2-11e6-9a92-9605e266cf30.png)

**255**? why? please look at [this](http://www.tldp.org/LDP/abs/html/exitcodes.html)

##Exercise 1.3
> Write a program to print Hello, World on the standard output.

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, World" << std::endl;
    return 0;
}
```

##Exercise 1.4
> Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, *, to print the product instead.

```cpp
#include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product is " << v1 * v2 << std::endl;

    return 0;
}
```

##Exercise 1.5

> We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.

```cpp
#include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 * v2;
    std::cout << std::endl;
    return 0;
}
```

##Exercise 1.6
> Explain whether the following program fragment is legal.
```cpp
std::cout << "The sum of " << v1;
          << " and " << v2;
          << " is " << v1 + v2 << std::endl;
```

It's illegal.

**[Error] expected primary-expression before '<<' token**

Fixed it: remove the spare semicolons.

```cpp
std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
```

##Exercise 1.7

> Compile a program that has incorrectly nested comments.

Example:
```cpp
/*
* comment pairs /* */ cannot nest.
* ''cannot nest'' is considered source code,
* as is the rest of the program
*/
int main(int argc, char const *argv[])
{
    return -1;
}
```

Compiled result(clang++):

![result](https://cloud.githubusercontent.com/assets/6889915/19635381/818d352c-99f4-11e6-98d4-ca0820877c05.png)

##[Exercise 1.8](ex01_08.cc)

> Indicate which, if any, of the following output statements are legal:
```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```
> After you’ve predicted what will happen, test your answers by compiling a
program with each of these statements. Correct any errors you encounter.

Compiled result(clang++):

![result](https://cloud.githubusercontent.com/assets/6889915/19635719/e6c544e6-99f6-11e6-915d-7c73406d9aed.png)

Corrected? just added a quote:
```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */";
std::cout << /* "*/" /* "/*" */;
```

Output:

    /**/ */ /*

##[Exercise 1.9](ex01_09.cc)
>Write a program that uses a while to sum the numbers from 50 to 100.

##[Exercise 1.10](ex01_10.cc)
>In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--)
that subtracts 1. Use the decrement operator to write a while that prints the numbers from ten down to zero.

##[Exercise 1.11](ex01_11.cc)
>Write a program that prompts the user for two integers.
Print each number in the range specified by those two integers.

##Exercise 1.12
> What does the following for loop do? What is the final value of sum?
```cpp
int sum = 0;
for (int i = -100; i <= 100; ++i)
sum += i;
```

the loop sums the numbers from -100 to 100. the final value of sum is zero.

##Exercise 1.13
> Rewrite the exercises from § 1.4.1 (p. 13) using for loops.

```cpp
#include <iostream>

int main(int argc, char const *argv[])
{
    int sum = 0;
    for (int i = 50; i <= 100; ++i) {
        sum += i;
    }
    std::cout << "the sum is: " << sum << std::endl;

    return 0;
}
```

##Exercise 1.14
> Compare and contrast the loops that used a for with those
using a while. Are there advantages or disadvantages to using either form?

The main difference between the for's and the while's is a matter of pragmatics:
we usually use for when there is a known number of iterations, and use while
constructs when the number of iterations in not known in advance.
The while vs do ... while issue is also of pragmatics, the second executes
the instructions once at start, and afterwards it behaves just like the simple while.


[A similar question on Stack Overflow](http://stackoverflow.com/questions/2950931/for-vs-while-in-c-programming)

##Exercise 1.15
> Write programs that contain the common errors discussed in
the box on page 16. Familiarize yourself with the messages the compiler
generates.

Nothing to present here.

##Exercise 1.16
>Write your own version of a program that prints the sum of
a set of integers read from cin.

```cpp
#include <iostream>
int main(int argc, char const *argv[])
{
    int sum = 0;
    for (int val; std::cin >> val; sum += val);
    std::cout << sum << std::endl;

    return 0;
}
```

##Exercise 1.17

> What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?

If the input values are all equal, it will print a line which shows the count of the number you input.

If there are no duplicated values, when different values input, a new line will be printed if you click `Enter`.

##[Exercise 1.18](../examples/occurs.cc)

> Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.


##[Exercise 1.19](ex01_11.cc)

> Revise the program you wrote for the exercises in § 1.4.1 (p. 13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.


##[Exercise 1.20](../examples/item_io.cc)

> http://www.informit.com/title/032174113 contains a copy of Sales_item.h in the Chapter 1 code directory. Copy that file to your working directory. Use it to write a program that reads a set of book sales transactions, writing each transaction to the standard output.

./item_io.exe < data/add_item

##[Exercise 1.21](../examples/add_item2.cc)
> Write a program that reads two Sales_item objects that have the same ISBN and produces their sum.

The program should check whether the objects have the same ISBN.


##[Exercise 1.22](../examples/avg_price.cc)

> Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.


##[Exercise 1.23]()
> Write a program that reads several transactions and counts how many transactions occur for each ISBN.


##Exercise 1.24
> Test the previous program by giving multiple transactions representing multiple ISBNs.
The records for each ISBN should be grouped together.


##[Exercise 1.25](ex01_22.cc)
> Using the Sales_item.h header from the Web site,
compile and execute the bookstore program presented in this section.
