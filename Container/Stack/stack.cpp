#include "stack.h"

template<typename T>
Stack<T>::Stack(T val) 
{
    mArr.push_back(val);
}

template<typename T>
Stack<T>::Stack(const Stack<T>& oth) : mArr(oth.mArr) {}

template<typename T>
Stack<T>::Stack(Stack<T>&& oth) : mArr(std::move(oth.mArr)) {}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& oth) 
{
    if (this != &oth) {
        mArr = oth.mArr;
    }
    return *this;
}


template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T>&& oth) 
{
    if (this != &oth) {
        mArr = std::move(oth.mArr);
    }
    return *this;
}

template<typename T>
bool Stack<T>::operator==(Stack<T>& oth) 
{
    return mArr == oth.mArr;
}

template<typename T>
bool Stack<T>::operator!=(Stack<T>& oth) 
{
    return mArr != oth.mArr;
}

template<typename T>
bool Stack<T>::operator>(const Stack<T>& oth) 
{
    return mArr > oth.mArr;
}

template<typename T>
bool Stack<T>::operator<(const Stack<T>& oth) 
{
    return mArr < oth.mArr;
}

template<typename T>
bool Stack<T>::operator>=(const Stack<T>& oth) 
{
    return mArr >= oth.mArr;
}

template<typename T>
bool Stack<T>::operator<=(const Stack<T>& oth) 
{
    return mArr <= oth.mArr;
}

template<typename T>
void Stack<T>::push(T val)
{
    mArr.push_back(val);
}

template<typename T>
void Stack<T>::pop() 
{
    if (!empty()) {
        mArr.pop_back();
    }
}

template<typename T>
int Stack<T>::size() 
{
    return mArr.size();
}

template<typename T>
bool Stack<T>::empty() 
{
    return mArr.empty();
}

template<typename T>
void Stack<T>::swap(Stack<T>& oth) 
{
    mArr.swap(oth.mArr);
}

template<typename T>
const T& Stack<T>::top() const 
{
    if (!empty()) {
        return mArr.back();
    }
    throw std::out_of_range("Stack is empty!");
}

template<typename T>
T& Stack<T>::top() 
{
    if (!empty()) {
        return mArr.back();
    }
    throw std::out_of_range("Stack is empty");
}

template<typename T>
void Stack<T>::print() 
{
    for (const auto& elm : mArr) {
        std::cout << elm << " ";
    }
    std::cout << std::endl;
}