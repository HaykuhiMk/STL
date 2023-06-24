#include <iostream>
#include "deque.hpp"

int main()
{
    Deque<int> deque;
    deque.pushBack(1);
    deque.pushBack(2);
    deque.pushFront(3);
    deque.pushFront(4);
    deque.print();  
    deque.popFront();
    deque.popBack();
    deque.print();  
    std::cout << "Front: " << deque.front() << std::endl;  
    std::cout << "Back: " << deque.back() << std::endl;    
    return 0;
}
