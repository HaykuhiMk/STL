#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

template <typename T>
class ForwardList
{
public:
	ForwardList();
	~ForwardList();
	ForwardList(const ForwardList&);
	ForwardList(ForwardList&&);
	
public:
	ForwardList& operator=(const ForwardList&);
	ForwardList& operator=(ForwardList&&);
	bool operator==(const ForwardList&);
	bool operator!=(const ForwardList&);
	
public:
	void sort();
	void merge(ForwardList);
	
public:
	const T& front() const;
	int length();
	T begin() const;
	T end() const;
	bool empty() const;
	void clear();
	void pushFront(T);
	void popFront();
 	void insertAfter(int, T);
 	void eraseAfter(int);
	void swap(ForwardList&);
	void print();

private:
    struct Node
    {
        T mData;
        Node* next;
        Node() : mData{}, next{nullptr} {}
        Node(const T& data) : mData{data}, next{nullptr} {}
    } *head;
    int mSize;
};

#endif  //FORWARD_LIST_H
