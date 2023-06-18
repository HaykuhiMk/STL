#include <iostream>
#include <exception>
#include <utility>
#include "vector.h"

template <typename T>
Vector<T>::Vector() : mArr(nullptr), mSize(0), mCapacity(0) {}

template <typename T>
Vector<T>::~Vector()
{
    mSize = 0;
    mCapacity = 0;
    if (mArr != nullptr) 
    {
        delete[] mArr;
        mArr = nullptr;
    }
}

template <typename T>
Vector<T>::Vector(T* arr, int size)
{
    mSize = size;
    mCapacity = size * 2 + 1;
    delete[] mArr;
    mArr = new T[mCapacity];
    for (int i = 0; i < size; ++i)
    {
        mArr[i] = arr[i];
    }
}

template <typename T>
Vector<T>::Vector(int size, int cap)
{
    mSize = size;
    mCapacity = cap;
    delete[] mArr;
    mArr = new T[mCapacity];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& oth)
{
    this->mSize = oth.mSize;
    this->mCapacity = oth.mCapacity;
    delete[] this->mArr;
    this->mArr = new T[this->mCapacity];
    for (int i = 0; i < this->mSize; ++i)
    {
        this->mArr[i] = oth.mArr[i];
    } 
}

template <typename T>
Vector<T>::Vector(Vector<T>&& oth)
{
    this->mSize = oth.mSize;
    this->mCapacity = oth.mCapacity;
    this->mArr = oth.mArr;
    oth.mSize = 0;
    oth.mCapacity = 0;
    oth.mArr = nullptr;
}

template <typename T>
const T& Vector<T>::operator[](int ind) const
{
    if (ind >= mSize || ind < 0)
    {
        throw std::out_of_range("Invalid index!");
    }
    return mArr[ind];
}

template <typename T>
T& Vector<T>::operator[](int ind)
{
    if (ind >= mSize || ind < 0)
    {
        throw std::out_of_range("Invalid index!");
    }
    return mArr[ind];
}

template <typename T>	
Vector<T>& Vector<T>::operator=(const Vector<T>& oth)
{
    if (this == &oth)
    {
        return *this;
    }
    delete[] this->mArr;
    this->mSize = oth.mSize;
    this->mCapacity = oth.mCapacity;
    this->mArr = new T[this->mCapacity];
    for (int i = 0; i < this->mSize; ++i)
    {
        this->mArr[i] = oth.mArr[i];
    } 
    return *this;
}

template <typename T>	
Vector<T>& Vector<T>::operator=(Vector<T>&& oth)
{
    if (this == &oth)
    {
        return *this;
    }
    this->mSize = oth.mSize;
    this->mCapacity = oth.mCapacity;
    this->mArr = oth.mArr;
    oth.mSize = 0;
    oth.mCapacity = 0;
    oth.mArr = nullptr;
    return *this;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T>& oth) const
{
    if (this->mSize != oth.mSize)
    {
        return false;
    }
    for (int i = 0; i < this->mSize; ++i)
    {
        if (this->mArr[i] != oth.mArr[i])
        {
            return false;
        }
    }
    return true;
}

template <typename T>
bool Vector<T>::operator!=(const Vector<T>& oth) const
{
    return !(*this == oth);
}

template <typename T>
bool Vector<T>::operator>(const Vector<T>& oth) const
{
    if (this->mSize > oth.mSize)
    {
        return true;
    }
    else if (this->mSize < oth.mSize)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < this->mSize; ++i)
        {
            if (this->mArr[i] > oth.mArr[i])
            {
                return true;
            }
            else if (this->mArr[i] < oth.mArr[i])
            {
                return false;
            }
        }
        return false; 
    }
}

template <typename T>
bool Vector<T>::operator<(const Vector<T>& oth) const
{
    if (this->mSize < oth.mSize)
    {
        return true;
    }
    else if (this->mSize > oth.mSize)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < this->mSize; ++i)
        {
            if (this->mArr[i] < oth.mArr[i])
            {
                return true;
            }
            else if (this->mArr[i] > oth.mArr[i])
            {
                return false;
            }
        }
        return false; 
    }
}

template <typename T>
bool Vector<T>::operator>=(const Vector<T>& oth) const
{
    return (*this > oth) || (*this == oth);
}

template <typename T>
bool Vector<T>::operator<=(const Vector<T>& oth) const
{
    return (*this < oth) || (*this == oth);
}

template <typename T>
void Vector<T>::setSize(int size)
{
    this->mSize = size;
}

template <typename T>
int Vector<T>::getSize() const
{
    return this->mSize;
}

template <typename T>
void Vector<T>::setCapacity(int cap)
{
    this->mCapacity = cap;
}

template <typename T>
int Vector<T>::getCapacity() const
{
    return this->mCapacity;
}

template <typename T>
void Vector<T>::setArr(T* arr, int size)
{
    delete[] mArr;
    mSize = size;
    mCapacity = size * 2 + 1;
    mArr = new T[mCapacity];
    for (int i = 0; i < size; ++i)
    {
        mArr[i] = arr[i];
    }
}

template <typename T>
T* Vector<T>::getArr() const
{
    return mArr;
}

template <typename T>
void Vector<T>::pushBack(const T& val)
{
    if (mSize == mCapacity)
    {
        this->resize();
    }
    mArr[mSize] = val;
    ++mSize;
}

template <typename T>
void Vector<T>::popBack()
{
    if (mSize > 0) 
    {
        --mSize;
    }
}

template <typename T>
void Vector<T>::clear() 
{
    mSize = 0;
}

template <typename T>
void Vector<T>::resize()
{
    int newCapacity = (mCapacity == 0) ? 1 : mCapacity * 2;
    T* tmp = new T[newCapacity];
    for (int i = 0; i < mSize; ++i)
    {
        tmp[i] = mArr[i];
    }
    mCapacity = newCapacity;
    delete[] mArr;
    mArr = tmp;
}

template <typename T>
void Vector<T>::print() const
{
    for (int i = 0; i < mSize; ++i)
    {
        std::cout << mArr[i] << std::endl;
    }
}

template <typename T>
bool Vector<T>::empty() 
{
    return (mSize == 0);
}

template <typename T>
int Vector<T>::length() const 
{
    return mSize;
}

template <typename T>
T& Vector<T>::at(int ind) 
{
    if (ind < 0 || ind >= mSize) 
    {
        throw std::out_of_range("Invalid index!");
    }
    return mArr[ind];
}

template <typename T>
void Vector<T>::swap(Vector<T>& oth) 
{
    std::swap(this->mArr, oth.mArr);
    std::swap(this->mSize, oth.mSize);
    std::swap(this->mCapacity, oth.mCapacity);
}

template <typename T>
T Vector<T>::begin() const 
{
    return mArr[0];
}

template <typename T>
T Vector<T>::end() const 
{
    return mArr[mSize - 1];
}

template <typename T>
void Vector<T>::insert(int ind, const T& val) 
{
    if (ind < 0 || ind > mSize) 
    {
        throw std::out_of_range("Invalid index!");
    }
    if (mSize == mCapacity) 
    {
        resize();
    }
    for (int i = mSize; i > ind; --i) 
    {
        mArr[i] = mArr[i - 1];
    }
    mArr[ind] = val;
    ++mSize;
}


template <typename T>
void Vector<T>::erase(int ind) 
{
    if (ind < 0 || ind >= mSize) 
    {
        throw std::out_of_range("Invalid index!");
    }
    for (int i = ind; i < mSize - 1; ++i) 
    {
        mArr[i] = mArr[i + 1];
    }
    --mSize;
}
