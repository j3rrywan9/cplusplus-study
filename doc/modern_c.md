# Modern C

## Chapter 1 Getting started

###  IMPERATIVE PROGRAMMING

### COMPILING AND RUNNING

There is a special program, called a *compiler*, that translates the C text into something that your machine can understand: the *binary code* or *executable*.

That said, if you have a POSIX system (such as Linux or macOS), there is a good chance that a program named `c99` might be present and that it is in fact a C compiler.

## Chapter 2 The principal structure of a program

### GRAMMAR

### DECLARATIONS

Before we may use a particular identifier in a program, we have to give the compiler a *declaration* that specifies what that identifier is supposed to represent.
This is where identifiers differ from keywords: keywords are predefined by the language and must not be declared or redefined.

Because the specifics of these predeclared features are of minor importance, this information is normally hidden from you in these *include files* or *header files*.

### DEFINITIONS

Generally, declarations only specify the kind of object an identifier refers to, not what the concrete value of an identifier is, nor where the object it refers to can be found.
This important role is filled by a *definition*.

An *initialization* is a grammatical construct that augments a declaration and provides an initial value for the object.
For instance,
```c
size_t i = 0;
```
is a declaration of `i` such that the initial value is 0.

In C, such a declaration with an initializer also *defines* the object with the corresponding name: that is, it instructs the compiler to provide storage in which the value of the variable can be stored.

### STATEMENTS

#### Iteration

#### Function calls

#### Function return

## Chapter 3 Everything is about control

## Chapter 4 Expressing computations

## Chapter 6 Derived data types

### ARRAYS

### STRUCTURES

## Chapter 7 Functions

### SIMPLE FUNCTIONS

All the functions we have seen so far have a *prototype*: their declaration and definition, including a parameter type-list and a return type.

### `main` IS SPECIAL

Perhaps you have noted some particularities about `main`.
It has a very special role as the entry point into your program: its prototype is enforced by the C standard, but it is implemented by the programmer.
Being such a pivot between the runtime system and the application, main has to obey some special rules.

First, to suit different needs, it has several prototypes, one of which must be implemented.
Two should always be possible:
```c
int main(void);
int main(int argc, char* argv[argc+1]);
```
Then, any C platform may provide other interfaces.
Two variations are relatively common:
* On some embedded platforms where main is not expected to return to the runtime system, the return type may be void.
* On many platforms, a third parameter can give access to the "environment."
You should not rely on the existence of such other forms.
If you want to write portable code (which you do), stick to the two "official" forms.
For these, the return value of `int` gives an indication to the runtime system if the execution was successful: a value of `EXIT_SUCCESS` or `EXIT_FAILURE` indicates success or failure of the execution from the programmer's point of view.
These are the only two values that are guaranteed to work on all platforms.

There is another feature in the second prototype of main: argv, the vector of command-line arguments.
We looked at some examples where we used this vector to communicate values from the command line to the program.

### RECURSION

## Chapter 8 C library functions

### GENERAL PROPERTIES OF THE C LIBRARY AND ITS FUNCTIONS

#### Headers

#### Interfaces

#### Error checking

C library functions usually indicate failure through a special return value.
What value indicates the failure can be different and depends on the function itself.
Generally, you have to look up the specific convention in the manual page for the functions.

## Chapter 9 Style

### FORMATTING

### NAMING

## Chapter 10

## Chapter 11 Pointers

### POINTER OPERATIONS

#### Address-of and object-of operators

In a declaration, it creates a new type (a pointer type), whereas in an expression it *dereferences* the object to which a pointer *refers*.
To help distinguish these two usages of the same symbol, we usually flush the `*` to the left with no blanks in between if it modifies a type (such as `double*`) and to the right if it dereferences a pointer (`*p0`).

#### Pointer addition

We already have seen that a valid pointer holds the address of an object of its reference type, but actually C assumes more than that:

> A valid pointer refers to the first element of an array of the reference type.

Or, in other words, a pointer may be used to refer not only to one instance of the reference type, but also to an array of an unknown length `n`.

This entanglement between the concept of pointers and arrays is taken an important step further in the syntax.

Both the use of array notation for the interface and the use of `[0]` to access the first element are simple *rewrite operations* that are built into the C language.

#### Pointer subtraction and difference

#### Pointer validity

#### Null pointers

### POINTERS AND STRUCTURES

Pointers to structure types are crucial for most coding in C, so some specific rules and tools have been put in place to ease this typical usage.

For convenience, here we use a new operator, `->`.
Its arrow-like symbol is meant to represent a pointer as the left operand that "points" to a member of the underlying `struct` as the right operand.

### POINTERS AND ARRAYS

#### Array and pointer access are the same

#### Array and pointer parameters are the same

### FUNCTION POINTERS

There is yet another construct for which the address-of operator `&` can be used: functions.

> A function `f` without a following opening `(` decays to a pointer to its start.

The C library has several functions that receive function parameters.

In addition, they receive a comparison function as a parameter that provides the information about the sort order between the elements.
By using such a function pointer, the `bsearch` and `qsort` functions are very generic and can be used with any data model that allows for an ordering of values.

*Calling* functions and function pointers with the `(...)` operator has rules similar to those for arrays and pointers and the `[...]` operator:

> The function call operator `(...)` applies to function pointers.

```c
double f(double a);
// Equivalent calls to f, steps in the abstract state machine
f(3);        // Decay → call
(&f)(3);     // Address of → call
(*f)(3);     // Decay → dereference → decay → call
(*&f)(3);    // Address of → dereference → decay → call
(&*f)(3);    // Decay → dereference → address of → call
```
So technically, in terms of the abstract state machine, the pointer decay is always performed, and the function is called via a function pointer.
The first, "natural" call has a hidden evaluation of the `f` identifier that results in the function pointer.

## Chapter 12 The C memory model

Pointers present us with a certain abstraction of the environment and state in which our program is executed, the *C memory model*.

The only thing C must care about is the *type* of the object a pointer addresses.
Each pointer type is derived from another type, its base type, and each such derived type is a distinct new type.

> Pointer types with distinct base types are distinct.

## Chapter 13 Storage

In this chapter, we will handle another mechanism to create objects, called *dynamic allocation*.

### `malloc` AND FRIENDS

The following set of functions, available with `stdlib.h`, has been designed to provide such an interface to allocated storage:
```c
#include <stdlib.h>
void* malloc(size_t size);
void free(void* ptr);
void* calloc(size_t nmemb, size_t size);
void* realloc(void* ptr, size_t size);
void* aligned_alloc(size_t alignment, size_t size);
```
The first two, `malloc` (memory allocate) and `free`, are by far the most prominent.
As their names indicate, `malloc` creates a storage instance for us on the fly, and `free` then annihilates it.
The three other functions are specialized versions of `malloc`: `calloc` (clear allocate) sets all bits of the new storage to 0, `realloc` grows or shrinks storage, and `aligned_alloc` ensures nondefault alignment.

All these functions operate with `void*`: that is, with pointers for which no type information is known.
Using that, they become universally applicable to all types.

It is important to note that the call to malloc stands as is;
the conversion from `void*`, the return type of `malloc`, to the target type is automatic and doesn't need any intervention.
