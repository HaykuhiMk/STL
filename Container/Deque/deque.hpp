#include <iostream>
#include "deque.h"

template<typename T>
Deque<T>::Deque() : 
mArr(nullptr), 
mSize(0), 
mCapacity(0), 
mFrontIndex(-1), 
mBackIndex(-1) 
{}

template<typename T>
Deque<T>::~Deque()
{
    delete[] mArr;
}

template<typename T>
Deque<T>::Deque(const Deque<T>& other)
{
    mSize = other.mSize;
    mCapacity = other.mCapacity;
    mFrontIndex = other.mFrontIndex;
    mBackIndex = other.mBackIndex;
    mArr = new T[mCapacity];
    for (int i = 0; i < mSize; i++)
    {
        mArr[i] = other.mArr[i];
    }
}

template<typename T>
Deque<T>::Deque(Deque<T>&& other)
{
    mSize = other.mSize;
    mCapacity = other.mCapacity;
    mFrontIndex = other.mFrontIndex;
    mBackIndex = other.mBackIndex;
    mArr = other.mArr;
    other.mArr = nullptr;
}

template<typename T>
void Deque<T>::setSize(int size)
{
    mSize = size;
}

template<typename T>
int Deque<T>::getSize() const
{
    return mSize;
}

template<typename T>
void Deque<T>::setCap(int capacity)
{
    mCapacity = capacity;
}

template<typename T>
int Deque<T>::getCap() const
{
    return mCapacity;
}

template<typename T>
void Deque<T>::pushFront(const T& value)
{
    if (mSize == mCapacity)
    {
        resize();
    }
    if (mFrontIndex == -1)  
    {
        mFrontIndex = mBackIndex = 0;
    }
    else if (mFrontIndex == 0)
    {
        mFrontIndex = mCapacity - 1;
    }
    else
    {
        mFrontIndex--;
    }

    mArr[mFrontIndex] = value;
    mSize++;
}

template<typename T>
void Deque<T>::pushBack(const T& value)
{
    if (mSize == mCapacity)
    {
        resize();
    }
    if (mBackIndex == -1) 
    {
        mFrontIndex = mBackIndex = 0;
    }
    else if (mBackIndex == mCapacity - 1)
    {
        mBackIndex = 0;
    }
    else
    {
        mBackIndex++;
    }

    mArr[mBackIndex] = value;
    mSize++;
}

template<typename T>
void Deque<T>::popFront()
{
    if (empty())
    {
        std::cout << "Deque is empty." << std::endl;
        return;
    }

    if (mFrontIndex == mBackIndex) 
    {
        mFrontIndex = mBackIndex = -1;
    }
    else if (mFrontIndex == mCapacity - 1)
    {
        mFrontIndex = 0;
    }
    else
    {
        mFrontIndex++;
    }

    mSize--;
}

template<typename T>
void Deque<T>::popBack()
{
    if (empty())
    {
        std::cout << "Deque is empty." << std::endl;
        return;
    }

    if (mFrontIndex == mBackIndex) 
    {
        mFrontIndex = mBackIndex = -1;
    }
    else if (mBackIndex == 0)
    {
        mBackIndex = mCapacity - 1;
    }
    else
    {
        mBackIndex--;
    }

    mSize--;
}

template<typename T>
T& Deque<T>::front()
{
    if (empty())
    {
        throw std::runtime_error("Deque is empty.");
    }

    return mArr[mFrontIndex];
}

template<typename T>
const T& Deque<T>::front() const
{
    if (empty())
    {
        throw std::runtime_error("Deque is empty.");
    }

    return mArr[mFrontIndex];
}

template<typename T>
T& Deque<T>::back()
{
    if (empty())
    {
        throw std::runtime_error("Deque is empty.");
    }

    return mArr[mBackIndex];
}

template<typename T>
const T& Deque<T>::back() const
{
    if (empty())
    {
        throw std::runtime_error("Deque is empty.");
    }

    return mArr[mBackIndex];
}

template<typename T>
bool Deque<T>::empty() const
{
    return mSize == 0;
}

template<typename T>
void Deque<T>::print() const
{
    if (empty())
    {
        std::cout << "Deque is empty." << std::endl;
        return;
    }

    int index = mFrontIndex;
    for (int i = 0; i < mSize; i++)
    {
        std::cout << mArr[index] << " ";

        if (index == mCapacity - 1)
        {
            index = 0;
        }
        else
        {
            index++;
        }
    }

    std::cout << std::endl;
}

template<typename T>
void Deque<T>::resize()
{
    int newCapacity = (mCapacity == 0) ? 1 : mCapacity * 2;
    T* newArr = new T[newCapacity];
    int newIndex = 0;
    int index = mFrontIndex;
    while (newIndex < mSize)
    {
        newArr[newIndex] = mArr[index];

        if (index == mCapacity - 1)
        {
            index = 0;
        }
        else
        {
            index++;
        }

        newIndex++;
    }
    delete[] mArr;
    mArr = newArr;
    mCapacity = newCapacity;
    mFrontIndex = 0;
    mBackIndex = mSize - 1;
}
