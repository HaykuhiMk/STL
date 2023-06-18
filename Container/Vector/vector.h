#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Vector
{
public:
	Vector();
	~Vector();
	Vector(T*, int);
	Vector(int, int);
	Vector(const Vector<T>&);
	Vector(Vector<T>&&);

public:	
	const T& operator[](int) const;
	T& operator[](int);
	Vector& operator=(const Vector<T>&);
	Vector& operator=(Vector<T>&&);
	bool operator==(const Vector<T>&) const;
	bool operator!=(const Vector<T>&) const;
	bool operator>(const Vector<T>&) const;
	bool operator<(const Vector<T>&) const;
	bool operator>=(const Vector<T>&) const;
	bool operator<=(const Vector<T>&) const;
    friend std::ostream& operator<<(std::ostream& os, const Vector<T>& vc)
    {
        for (int i = 0; i < vc.mSize; ++i)
        {
            os << vc[i] << " ";
        }
        return os;
    }

public:
	void setSize(int);
	int getSize() const;
	void setCapacity(int);
	int getCapacity() const;
	void setArr(T*, int);
	T* getArr() const;

public:	
	void pushBack(const T&);
	void popBack();
	void clear();
	void resize();
	bool empty();
	int length() const;
	T& at(int);
	void insert(int, const T&);
	void erase(int);
	void swap(Vector&);
	T begin() const;
	T end() const;
	void print() const;

private:
	T* mArr;
	int mSize;
	int mCapacity;
};

#endif // VECTOR_H