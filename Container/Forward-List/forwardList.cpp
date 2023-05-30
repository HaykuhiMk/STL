#include <iostream>
#include "forwardList.h"

template <typename T>
ForwardList<T>::ForwardList() : 
mSize{},
head{nullptr}
{}

template <typename T>
ForwardList<T>::~ForwardList() 
{
    if (this->head)
    {
        clear();
    }
}

template <typename T>
ForwardList<T>::ForwardList(const ForwardList& oth)
{
    if (oth.head == nullptr)
    {
        this->head = nullptr;
    }
    else
    {
        head = new Node(oth.head->mData);
        Node* tmp1 = this->head;
        Node* tmp2 = oth.head->next;
        while (tmp2)
        {
            tmp1->next = new Node(tmp2->mData);
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
    }    
}

template <typename T>
ForwardList<T>::ForwardList(ForwardList&& oth)
{
    this->head = oth.head;
    oth.head = nullptr;
}

template <typename T>
ForwardList<T>& ForwardList<T>::operator=(const ForwardList& rhs)
{
    if (this->head == rhs.head)
    {
        return *this;
    }
    clear();
    head = new Node(rhs.head->mData);
    Node* tmp1 = this->head;
    Node* tmp2 = rhs.head->next;
    while (tmp2)
    {
        tmp1->next = new Node(tmp2->mData);
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }    
    return *this;
}

template <typename T>
ForwardList<T>& ForwardList<T>::operator=(ForwardList&& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    clear();
    this->head = rhs.head;
    rhs.head = nullptr;
    return *this;
}

template <typename T>
bool ForwardList<T>::operator==(const ForwardList& rhs)
{
    if (this->head == nullptr || rhs.head == nullptr || (this->length() != rhs.length()))
    {
        return false;
    }
    Node* tmp1 = this->head;
    Node* tmp2 = rhs.head;
    while (tmp1)
    {
        if (tmp1->mData != tmp2->mData)
        {
            return false;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    return true;
}

template <typename T>
bool ForwardList<T>::operator!=(const ForwardList<T>& rhs)
{
    return !(*this == rhs);
}

template <typename T>
const T& ForwardList<T>::front() const
{
    if (empty())
    {
        throw std::logic_error("Forward List is empty!");
    }
    return this->head->mData;
}

template <typename T>
T ForwardList<T>::begin() const
{
    if (empty())
    {
        throw std::logic_error("Forward List is empty!");
    }
    return this->head->mData;
}

template <typename T>
T ForwardList<T>::end() const
{
    if (empty())
    {
        throw std::logic_error("Forward List is empty!");
    }
    Node* tmp = this->head;
    while (tmp)
    {
        tmp = tmp->next;
    }
    return tmp->mData;
}

template <typename T>
void ForwardList<T>::pushFront(T elem)
{
    Node* tmp = new Node(elem);
    tmp->next = head;
    head = tmp;
}

template <typename T>
void ForwardList<T>::popFront()
{
    if (this->head)
    {
        Node* tmp = head;
        head = head->next;
        delete tmp;

    }
}

template <typename T>
bool ForwardList<T>::empty() const
{
	if (head == nullptr)
	{
		return true;
	}
	return false;
}

template <typename T>
void ForwardList<T>::insertAfter(int index, T elem)
{
	if (head == nullptr)
	{
		throw std::logic_error("The list is empty!");
	}
	if (index < 0 || index >= length())
	{
		throw std::out_of_range("Invalid index!");
	}	
	if (!index) 
	{
		this->pushFront(elem);
		return;
	}
	Node* tmp = this->head->next;
	Node* prev = nullptr;
	for (int i = 0; i < index; ++i) 
	{
		if (i == index - 1) 
		{
			prev = tmp;
		}
		tmp = tmp->next;
	}
	prev->next = new Node(elem);
	prev->next->next = tmp;
}

template <typename T>
void ForwardList<T>::eraseAfter(int index)
{
	if (index < 0 || index >= length() - 1)
	{
		throw std::out_of_range("Invalid index!");
	}	
	if (index == 0)
	{
		popFront();
	}
	Node* tmp = head;
	for (int i = 0; i < index; ++i)
	{
		tmp = tmp->next;
	}
	Node* del = tmp->next;
	tmp->next = tmp->next->next;
	delete del;
	del = nullptr;
}

template <typename T>
void ForwardList<T>::swap(ForwardList& other)
{
	Node* tmp = head;
	head = other.head;
	other.head = tmp;
}

template <typename T>
void ForwardList<T>::clear()
{
    while (this->head)
    {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        tmp = nullptr;
    }
    if (this->head)
    {
        delete this->head;
    }
    this->head = nullptr;
}

template <typename T>
int ForwardList<T>::length()
{
    int len = 0;
    Node* tmp = head;
    while (tmp)
    {
        ++len;
        tmp = tmp->next;
    }
    return len;
}

template <typename T>
void ForwardList<T>::print()
{
	Node* tmp = head;
	while (tmp)
	{
		std::cout << tmp->mData << " ";
		tmp = tmp->next;
	}
	if (head) 
	{
		std::cout << std::endl;
	}
}

template <typename T>
void ForwardList<T>::sort()
{
	for (Node* i = head; i->next != nullptr; i = i->next)
	{
		for (Node* j = i->next; j != nullptr; j = j->next)
		{
			if (i->mData > j->mData)
			{
				std::swap(i->mData, j->mData);
			}
		}
	}
}

template <typename T>
void ForwardList<T>::merge(ForwardList oth)
{
	if (head == nullptr || oth.head == nullptr)
	{
		throw std::logic_error("The list is empty!");
	}
	this->sort();
	oth.sort();
	Node* tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	Node* tmp2 = oth.head;
	while(tmp2) 
	{
		tmp->next = new Node(tmp2->mData);
		tmp2 = tmp2->next;
		tmp = tmp->next;
	}
	sort();
}
