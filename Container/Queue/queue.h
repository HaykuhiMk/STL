#include <iostream>
#include <deque>
#include <stdexcept>

template <typename T, typename Container = std::deque<T>>
class Queue 
{
public:
    using value_type = typename Container::value_type;
    using reference = typename Container::reference;
    using const_reference = typename Container::const_reference;
    using size_type = typename Container::size_type;

    bool empty() const;
    size_type size() const;
    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;
    void push(const value_type& value);
    void pop();
    
private:
    Container container_;
};
