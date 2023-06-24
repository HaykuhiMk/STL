#ifndef DEQUE_H
#define DEQUE_H

template<typename T>
class Deque
{
public:
    Deque();
    ~Deque();
    Deque(const Deque<T>&);
    Deque(Deque<T>&&);

public:
    void setSize(int);
    int getSize() const;
    void setCap(int);
    int getCap() const;

public:
    void pushFront(const T&);
    void pushBack(const T&);
    void popFront();
    void popBack();
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    bool empty() const;
    void print() const;

private:
    void resize();

private:
    T* mArr;
    int mSize;
    int mCapacity;
    int mFrontIndex;
    int mBackIndex;

};

#endif  //DEQUE_H