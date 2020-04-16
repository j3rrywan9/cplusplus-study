# Beginning C++ 17

## Basic Ideas

### C++ Program Concepts

#### Source Files and Header Files

The file extension , `.cpp`, indicates that this is a C++ *source file*.

Next to source files, there're also so-called header files.
Header files contain, among other things, *function prototypes* and *definitions* for classes and templates that are used by the executable code in a `.cpp` file.
The names of header files usually have the extension `.h`, although other extensions such as `.hpp` are also used.

#### Comments and Whitespace

#### Functions

#### Statements

#### Data Input and Output

#### `return` Statements

#### Namespaces

A *namespace* is a sort of family name that prefixes all the names declared within the namespace.
The names in the Standard Library are all defined within a namespace that has the name `std`.

#### Names and Keywords

### Classes and Objects

A *class* is a block of code that defines a data type.
A class has a name that is the name for the type.
An item of data of a class type is referred to as an *object*.

### Templates

A *template* is a recipe that you create to be used by the compiler to generate code automatically for a class or function customized for a particular type or types.

## Introducing Fundamental Types of Data

### Variables, Data, and Data Types

A *variable* is a named piece of memory that you define.
Each variable stores data only of a particular type.
Every variable has a *type* that defines the kind of data it can store.
Each fundamental type is identified by a unique type name that consists of one or more *keywords*.

## Working with Fundamental Data Types

### Enumerated Data Types

When you define an enumeration, you're creating a new type, so it's also referred to as an *enumerated data type*.

Each enumerator will be automatically defined to have a fixed integer value of type `int` by default.

### Aliases for Data Types

## Making Decisions

### Comparing Data Values

You can compare data values using some new operators called *relational operators*.

### The `if` Statement

### The `if-else` Statement

### Logical Operator

Using logical operators, you can combine a series of comparisons into a single expression so that you need just one `if`, almost regardless  of the complexity of the set of conditions.
