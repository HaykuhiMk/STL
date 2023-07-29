#include "queue.h"

template <typename T, typename Container>
bool Queue<T, Container>::empty() const 
{
    return container_.empty();
}

template <typename T, typename Container>
typename Queue<T, Container>::size_type Queue<T, Container>::size() const 
{
    return container_.size();
}

template <typename T, typename Container>
typename Queue<T, Container>::reference Queue<T, Container>::front() 
{
    if (empty()) {
        throw std::out_of_range("Queue is empty!");
    }
    return container_.front();
}

template <typename T, typename Container>
typename Queue<T, Container>::const_reference Queue<T, Container>::front() const 
{
    if (empty()) {
        throw std::out_of_range("Queue is empty!");
    }
    return container_.front();
}

template <typename T, typename Container>
typename Queue<T, Container>::reference Queue<T, Container>::back() 
{
    if (empty()) {
        throw std::out_of_range("Queue is empty!");
    }
    return container_.back();
}

template <typename T, typename Container>
typename Queue<T, Container>::const_reference Queue<T, Container>::back() const
{
    if (empty()) {
        throw std::out_of_range("Queue is empty!");
    }
    return container_.back();
}

template <typename T, typename Container>
void Queue<T, Container>::push(const value_type& value) 
{
    container_.push_back(value);
}

template <typename T, typename Container>
void Queue<T, Container>::pop() 
{
    if (empty()) {
        throw std::out_of_range("Queue is empty, cannot pop.");
    }
    container_.pop_front();
}
