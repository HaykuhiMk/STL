# Vector Implementation
This is an implementation of a dynamic array called Vector in C++. The Vector class provides functionality similar to the std::vector
container in the C++ Standard Library.

## Features
Dynamic resizing: The Vector automatically resizes itself when the number of elements exceeds its capacity.

Random access: Elements in the Vector can be accessed using the indexing operator ([]).

Range-based iteration: The Vector supports range-based iteration using the begin() and end() member functions.

Element manipulation: Elements can be added at the end (pushBack()), removed from the end (popBack()), inserted at a specific position (insert()), and erased from a specific position (erase()).

Capacity management: The Vector allows setting and retrieving the current size and capacity of the array.

Comparison operators: The Vector supports comparison operators (==, !=, >, <, >=, <=) for comparing the contents of two vectors.

Copy and move semantics: The Vector supports both copy construction and assignment as well as move construction and assignment.
