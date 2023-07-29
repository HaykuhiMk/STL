# Queue Implementation
This repository contains a C++ implementation of a simple queue data structure using templates and the Standard Template Library (STL).
## Features
1)Generic Data Type: The Queue class is designed using templates, allowing it to be used with various data types, including built-in
types (int, float, etc.) and user-defined classes.

2)Custom Underlying Container: The Queue class allows you to choose the underlying container to store elements. By default, it uses
std::deque, but you can easily switch to other STL containers such as std::vector or std::list.

3)FIFO Behavior: The Queue class follows the First-In-First-Out (FIFO) order, meaning that elements are added at the back and 
removed from the front. This makes it suitable for scenarios where elements need to be processed in the order they are added.

4)Basic Queue Operations: The class provides standard queue operations like push (to add an element to the back of the queue), 
pop (to remove the front element), front (to access the front element), back (to access the back element), empty (to check if the
queue is empty), and size (to get the current size of the queue).
