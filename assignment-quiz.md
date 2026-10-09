# Data Structures - Assignment Quizzes

Three C++ programs, one per quiz. Each program uses only `#include <iostream>` and `using namespace std;` with no other libraries.

## Quiz 1 - Array Operations

File: [quiz1_arrays.cpp](quiz1_arrays.cpp)

Basic operations on an array:

- Traverse - show all the elements
- Insert - add a value at a position
- Delete - remove the value at a position
- Search - find the position of a value
- Update - change the value at a position
- Reverse - turn the array back to front

## Quiz 2 - Stack Operations

File: [quiz2_stack.cpp](quiz2_stack.cpp)

Basic operations on a stack (built with an array):

- Push - add a value on top
- Pop - remove the value on top
- Peek - look at the value on top without removing it
- Display - show the stack from top to bottom

## Quiz 3 - Linked List Operations

File: [quiz3_linked_list.cpp](quiz3_linked_list.cpp)

Basic operations on a singly linked list:

- Traverse - show all the nodes
- Insert - at the beginning, at the end, or at a position
- Delete - from the beginning, from the end, or by value
- Search - find the position of a value
- Update - change an old value to a new one

## How to run

Compile a program with g++ and run it:

```
g++ quiz1_arrays.cpp -o quiz1
./quiz1
```

Do the same for `quiz2_stack.cpp` and `quiz3_linked_list.cpp`. Each program shows a menu, type the number of the operation you want.
