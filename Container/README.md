# C++ STL Containers

This repository provides an implementation of commonly used container classes from the C++ Standard Template Library (STL). These container classes are fundamental data structures that allow you to store and manage collections of objects efficiently.

## Overview

The repository contains the following container classes:

1. Vector: A dynamic array that can grow or shrink in size based on the number of elements it holds. It provides constant-time access to individual elements and supports efficient insertion and deletion at the end of the array.

2. List: A doubly-linked list that allows efficient insertion and deletion at both ends and at any position within the list. It does not provide constant-time random access to elements but is useful for scenarios that involve frequent modifications and traversal.

3. Stack: A Last-In-First-Out (LIFO) container that provides access to the top element only. It supports push and pop operations, making it suitable for implementing algorithms that require a stack-based data structure.

4. Queue: A First-In-First-Out (FIFO) container that allows insertion at one end and removal from the other end. It provides enqueue and dequeue operations and can be used to implement algorithms that follow a queue-based approach.

5. Deque: A double-ended queue that supports insertion and deletion at both ends. It provides constant-time access to the first and last elements, making it suitable for scenarios that require efficient insertion and deletion at both ends.

6. Set: A container that stores unique elements in a specific order. It ensures that no duplicate elements are present and provides efficient insertion, removal, and search operations.

7. Map: A container that stores key-value pairs in a specific order. It guarantees unique keys and allows efficient search, insertion, and deletion based on the keys.

8. Unordered Set: A container that stores unique elements without any specific order. It provides constant-time average complexity for insertion, removal, and search operations.

9. Unordered Map: A container that stores key-value pairs without any specific order. It allows efficient search, insertion, and deletion based on the keys, providing constant-time average complexity.

Each container class is implemented with appropriate member functions and operators to perform common operations and interact with the stored elements.
