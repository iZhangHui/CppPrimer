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