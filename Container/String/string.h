#ifndef STRING_H
#define STRING_H
#include <iostream>

class String
{
public:
    String();   //default
    ~String();
    String(char*);  //param
    String(std::size_t, std::size_t);
    String(const String&);  //copy
    String(String&&);   //move

public:
    String& operator=(const String&);
    String& operator=(String&&);
    String operator+(const String&);
    String& operator+=(const String&);
    const char& operator[](int) const;
    char& operator[](int);
    bool operator==(String&);
    bool operator!=(String&);
    bool operator<(const String&);
    bool operator>(const String&);
    bool operator<=(const String&);
    bool operator>=(const String&);
    friend std::ostream& operator<<(std::ostream&, const String&);

public:
    void setCapacity(std::size_t);
    std::size_t getCapacity() const;
    void setSize(std::size_t);
    std::size_t getSize() const;
    void setBuf(char*);
    char* getBuf() const;

public:
    void print();
    void pushBack(char);
    void pushBack(const char*);
    void popBack();
    char& at(int);
    void insert(int, char*);
    void erase(int);
    bool empty();
    void clear();
    void realoc(int);
    int length(const char*);
    int length() const;
    int find(char);
    void sSwap(String&);
    void reSize(int);
    char begin();
    char end();

private:
    std::size_t mCapacity;
    std::size_t mSize;
    char* mBuf;
};
#endif  //STRING_H
