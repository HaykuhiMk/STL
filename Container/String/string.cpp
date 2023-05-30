#include <iostream>
#include "string.h"

String::String()
{
    mCapacity = 8;
    mSize = 0;
    mBuf = new char[mCapacity];
}

String::~String()
{
    mCapacity = 0;
    mSize = 0;
    delete[] mBuf;
    mBuf = nullptr;
}
 
String::String(char* buf) 
{  
    this->mSize = strlen(buf);
    this->mCapacity = this->mSize + 1;
    mBuf = new char[this->mCapacity];
    for (int i = 0; i < this->mSize; ++i)
    {
        this->mBuf[i] = buf[i];
    }
}

String::String(std::size_t size, std::size_t cap)
{
    this->mCapacity = cap;
    this->mSize = size;
    mBuf = new char[this->mCapacity];
}

String::String(const String& rhs)
{
    this->mCapacity = rhs.mCapacity;
    this->mSize = rhs.mSize;
    delete[] mBuf;
    this->mBuf = new char[this->mCapacity];
    for (int i = 0; i < this->mSize; ++i)
    {
        this->mBuf[i] = rhs.mBuf[i];
    }
}

String::String(String&& rhs)
{
    this->mCapacity = rhs.mCapacity;
    this->mSize = rhs.mSize;
    this->mBuf = rhs.mBuf;
    rhs.mCapacity = 0;
    rhs.mSize = 0;
    rhs.mBuf = nullptr;
}

String& String::operator=(const String& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    if (this->empty())
    {
        delete[] this->mBuf;
        mBuf = nullptr;
    }
    this->mCapacity = rhs.mCapacity;
    this->mSize = rhs.mSize;
    this->mBuf = new char[this->mCapacity];
    for (int i = 0; i < this->mSize; ++i)
    {
        this->mBuf[i] = rhs.mBuf[i];
    }
    return *this;
}

String& String::operator=(String&& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    this->mCapacity = rhs.mCapacity;
    this->mSize = rhs.mSize;
    this->mBuf = rhs.mBuf;
    rhs.mCapacity = 0;
    rhs.mSize = 0;
    rhs.mBuf = nullptr;
    return *this;
}

String String::operator+(const String& rhs)
{
    String tmp;
    tmp.mSize = this->mSize + rhs.mSize;
    tmp.mCapacity = tmp.mSize + 1;
    tmp.mBuf = new char[tmp.mCapacity];
    for (int i = 0; i < this->mSize; ++i)
    {
        tmp.mBuf[i] = this->mBuf[i]; 
    }
    for (int i = 0; i < rhs.mSize; ++i)
    {
        tmp.mBuf[this->mSize + i] = rhs.mBuf[i]; 
    }
    tmp.mBuf[tmp.mSize] = '\0';
    return tmp;
}

String& String::operator+=(const String& rhs)
{
    this->mCapacity += rhs.mCapacity;
    this->mSize += rhs.mSize;
    int i = 0;
    for (; this->mBuf[i] != '\0'; ++i){}
    for (int j = 0; rhs.mBuf[j] != '\0'; ++j, ++i)
    {
        this->mBuf[i] = rhs.mBuf[j];
    }
    this->mBuf[mSize] = '\0';
    return *this;
}

const char& String::operator[](int ind) const
{
    if (ind < 0 || ind >= this->mSize)
    {
        std::cout << "Index not found!" << std::endl;
    }
    return mBuf[ind];
}

char& String::operator[](int ind)
{
    if (ind < 0 || ind >= this->mSize)
    {
        std::cout << "Index not found!" << std::endl;
    }
    return mBuf[ind];
}

bool String::operator==(String&  rhs)
{
    if (this->mSize != rhs.mSize)
    {
       return false;
    }
    for (int i = 0; i < this->mSize; ++i)
    {
        if (this->mBuf[i] != rhs.mBuf[i])
        {
            return false;
        }
    }
    return true;
}

bool String::operator!=(String& rhs)
{
    if (this->mSize != rhs.mSize)
    {
        return true;
    }
    for (int i = 0; i < this->mSize; ++i)
    {
        if (this->mBuf[i] != rhs.mBuf[i])
        {
            return true;
        }
    }
    return false;
}

bool String::operator<(const String& rhs)
{
    for (int i = 0; i < this->mSize; ++i)
    {
        if (this->mBuf[i] < rhs.mBuf[i])
        {
            return true;
        }
        else if (this->mBuf[i] > rhs.mBuf[i])
        {
            return false;
        }
    }
    return false;
}

bool String::operator>(const String& rhs)
{
    for (int i = 0; i < this->mSize; ++i)
    {
        if (this->mBuf[i] > rhs.mBuf[i])
        {
            return true;
        }
        else if (this->mBuf[i] < rhs.mBuf[i])
        {
            return false;
        }
    }
    return false;
}

bool String::operator<=(const String& rhs)
{
    int minLength = std::min(this->mSize, rhs.mSize);
    for (int i = 0; i < minLength; ++i)
    {
        if (this->mBuf[i] > rhs.mBuf[i])
        {
            return false;
        }
    }
    return true;
}

bool String::operator>=(const String& rhs)
{
    int minLength = std::min(this->mSize, rhs.mSize);
    for (int i = 0; i < minLength; ++i)
    {
        if (this->mBuf[i] < rhs.mBuf[i])
        {
            return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
    int i = 0;
    if (str.length() == 0) 
    {
        os << "";
        return os;
    }  
    return os << str.mBuf << std::endl;
}

std::size_t String::getCapacity() const
{
    return this->mCapacity;
}

void String::setCapacity(std::size_t cap)
{
    this->mCapacity = cap;
}

std::size_t String::getSize() const
{
    return this->mSize;
}

void String::setSize(std::size_t size) 
{
    this->mSize = size;
}

char* String::getBuf() const
{
    return this->mBuf;
}

void String::setBuf(char* buf)
{
    if (this->mBuf != nullptr)
    {
        delete[] this->mBuf;
    }
    this->mSize = strlen(buf);
    this->mCapacity = this->mSize + 1;
    this->mBuf = new char[mCapacity];
    for (int i = 0; i < this->mSize; ++i)
    {
        this->mBuf[i] = buf[i];
    }
}

void String::pushBack(char ch)
{
    if (!this->mBuf)
    {
        mCapacity = 2;
        mSize = 0;
        mBuf = new char[mCapacity];
        this->mBuf[0] = ch;
        this->mBuf[1] = '\0';
    }
    else 
    {
        if (this->mSize + 1 == this->mCapacity)
        {
            realoc(this->mSize);
        }
        this->mBuf[this->mSize++] = ch;
        this->mBuf[this->mSize] = '\0'; 
    }
}

void String::pushBack(const char* str)
{
    if(!this->mBuf)
    {
        this->mSize = length(str);
        this->mCapacity = this->mSize + 1;
        for (int i = 0; i < this->mSize; ++i)
        {
            this->mBuf[i] = str[i];
        }
        this->mBuf[this->mSize] = '\0';
    }
    else
    {
        int oldSize = this->mSize;
        this->mSize += length(str);
        if (this->mSize >= this->mCapacity)
        {
            realoc(this->mSize);
        }
        int j = 0;
        for (; oldSize < this->mSize;)
        {
            this->mBuf[oldSize++] = str[j++];
        }
        this->mBuf[this->mSize] = '\0';
    }
}

void String::realoc(int size)
{
    this->mCapacity = this->mCapacity + size;
    char* tmp = new char[this->mCapacity];
    for(int i = 0; i < this->mSize; ++i)
    {
        tmp[i] = this->mBuf[i];
    }
    tmp[this->mSize] = '\0';
    delete[] mBuf;
    mBuf = tmp;
    tmp = nullptr;
}

void String::popBack()
{
    if (!this->mBuf)
    {
        return;
    }
    else if (this->mSize > 1)
    {
        this->mSize = this->mSize - 1;
        this->mBuf[this->mSize] = '\0';
    }
    else if (this->mSize <= 1)
    {
        this->mCapacity = 0;
        this->mSize = 0;
        this->mBuf = nullptr;
    }
    
}

char& String::at(int ind)
{
    if (empty())
    {
        delete[] this->mBuf;
        mBuf = nullptr;
    }
    else
    {
        for (int i = 0; i < this->mSize; ++i)
        {
            if (i == ind)
            {
                return mBuf[i];
            }
        }
    }
    throw std::out_of_range("Invalid index!");
}

void String::insert(int ind, char* str)
{
    int len = length(str);
    if ((mSize + len + 1) >= this->mCapacity)
    {
        realoc((len + 1));
    }
    if (empty() && ind == 0)
    {
        this->mBuf = str;
    }
    else if (!empty() && ind == mSize)
    {
        for (int i = 0; i < len; ++i)
        {
            this->mBuf[mSize++] = str[i];
        }
        mBuf[mSize] = '\0';
    }
    else if (ind < mSize && ind > 0)
    {
        for (int i = this->mSize; i >= ind; --i)
        {
            this->mBuf[len + i] = this->mBuf[i];
        }
        for (int i = 0; i < len; ++i)
        {
            mBuf[ind + i] = str[i];
        }
        mSize += len;
        mBuf[mSize] = '\0';
    }
}

void String::erase(int ind)
{   
    if (!this->mBuf)
    {
        delete[] mBuf;
        mBuf = nullptr;
    }
    else
    {
        this->mBuf[ind] = '\0';
        this->mSize -= ind;
    }
}

void String::clear()
{
    if (mBuf)
    {
        mBuf[0] = '\0';
        mSize = 0;
    }
}

int String::find(char ch)
{
    for (int i = 0; i < this->mSize; ++i)
    {
        if (mBuf[i] == ch)
        {
            return i;
        }
    }
    return -1;
}

void String::sSwap(String& str)
{
    if (empty())
	{
		delete[] mBuf;
		mBuf = nullptr;
	}
    else
    {
        char* tmpBuf = str.mBuf;
        size_t tmpSize = str.mSize;
        size_t tmpCapacity = str.mCapacity;
        str.mBuf = this->mBuf;
        str.mSize = this->mSize;
        str.mCapacity = this->mCapacity;
        this->mBuf = tmpBuf;
        this->mSize = tmpSize;
        this->mCapacity = tmpCapacity;
    }
}

void String::reSize(int size)
{
    if (empty())
    {
        delete[] this->mBuf;
        this->mBuf = nullptr;
    }
    else
    {
        this->mSize = size;
        this->mCapacity = size + 1;
        this->realoc(size);
    }
}

char String::begin()
{
    return mBuf[0];
}

char String::end()
{
    return mBuf[mSize - 1];
}

void String::print()
{
    std::cout << this->mBuf << " s=" << mSize << " c=" << mCapacity;
}

bool String::empty()
{
    return(!this->mSize);
}

int String::length() const
{
    int len = 0;
    for (int i = 0; this->mBuf[i] != '\0'; ++i)
    {
        ++len;
    }
    return len;
}

int String::length(const char* str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        ++len;
    }
    return len;
}