# Chapter 6 by Zhengyuan Zhang

## Data Types
The type of a variable decides what operations it supports

### types
* Basic integer types: `char`, `int`, `unsigned`, `long`, etc
* Floating-point types: `float`, `double`
* [Structure types](#structures)
* Pointer types: pointers to all possible types, plus a `void*`
    * Note on pointer arithmetic, the unit of change is `sizeof(*ptr)`.
    * Since `void*` does not support dereference, it does not support arithmetic either.
* Literals:
    * a number without a dot has type int. Eg, `8` is an int.
    * a number with a dot has type double. Eg, `8.` is a double.
    * a string enclosed by double quotes is a pointer to a null terminated char array.
    * `NULL` is defined to be 0.

### operations
* Arithmetic operations:
    * general arithmetic: `+`, `-`, `*`, `/`. Note `int/int` produces an int.
    * integer-only arithmetic: 
        * Reminder: `%`. Note when the first operand is negative, the result is also negative. Eg, `-8%5 == -3`.
        * Increment & decrement: `++`, `--`. Note the position matters.
    * Shorthand operators available for all binary arithmetic operations. Eg, `a <<= 3`
* Bit-level operations: integer-only
    * Shift: `<<`, `>>`
    * NOT `!`, AND `&`, OR `|`, XOR `^`
* Relational/Logical expressions: similar to MatLab
    * except NOT operator is `!` instead of `~`
* Pointer related:
    * Reference(get address): `&` supported by all types
    * Dereference(get object): `*` only supported by pointer types, except `void*`
* Conditional operator: condition ? expression_1 : expression_2; Less typing compare to if statement.

### Variables
* Declaration: `TYPE variable`
    * with initialization: `TYPE variable = initial_value`. Note the value of an uninitialized variable is undefined.
    * const specifier: `const TYPE variable = initial_value`.
        Compiler would give an error if you try to change a constant variable.
    * Note when declaring a pointer:
    ```c
    //  A is a pointer to int, while B is a int
    int* A, B;
    // So I personally recommend this style
    // since *C is an int, the compiler can infer that C is a pointer to int
    int *C, D;
    // and this way when you want declare 2 pointers
    // since *E and *F are int, E and F are pointer to int
    int *E, *F;
    ```
* Scope of a variable: from declaration to end of the block.

### Recommendations (especially for project 3)
* Combine initialization with declaration whenever possible.
* Use `const` whenever a variable is meant to be fixed.
* Use meaningful names for variables.
* Limit the scope of variables as much as possible, by
    * Avoid global variables
    * Place declaration inside of blocks (function blocks, loop blocks, if blocks, etc)
    * Place declaration just before the first usage of that variable.

## Structures

Declaration
```c
// declare a structure for complex number
struct complex {
    double real, img;
};
// declare a complex number
struct complex a_complex_number;
// declare a function that returns the sum of 2 complex numbers
struct complex add(struct complex left, struct complex right);
```
Or use `typedef` to save some typing
```c
// declare a structure for complex number
struct _complex {
    double real, img;
};
// "complex" is an alias of "struct _complex"
typedef struct _complex complex;

complex a_complex_number;
complex add(complex left, complex right);
```
Or combine declaration of structure with `typedef`
```c
// "complex" is an alias of "struct _complex { double real, img; }"
typedef struct _complex {
    double real, img;
} complex;

// '->'' can also save you some typing when dealing with pointer
#include <assert.h>
void do_nothing(complex *number) {
    // the expression asserted is always true
    // so that nothing will happen
    assert( number->real == (*number).real );
}
```

## Control Statements

* if statement, while statement: similar to MatLab
* `break`, `continue`, `return`: still similar to MatLab
    * except `return` does return an object

* switch-case statement: note continue until the end of the block or `break`/`return`/`continue`, whichever first.
    ```c
    const char letter = 'a';
    switch (letter) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("vowel\n"); break;
        default:
            printf("not a vowel\n");
    }
    ```

* for statement
    ```c
    for (initialize; condition; step) {
        // code
    }
    ```
    is equivalent to

    ```c
    {
        initialize;
        while (condition) {
            // code
            step;
        }
    }
    ```
    Note: step does not need to be increment
    ```c
    // homework 5 exercise 6 loop approach
    for (unsigned step = 16; step; step >>= 1) {
        // code
    }
    ```

* do ... while statement is equivalent to
    ```c
    while (1) {
        //code
        if (!condition) break;
    }
    ```

