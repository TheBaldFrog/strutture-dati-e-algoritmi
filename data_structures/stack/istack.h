#pragma once

#include <cstddef>

// Interface
template <typename T>
class IStack
{
public:
    virtual void push(const T &newElem) = 0;
    virtual void pop() = 0;
    virtual T &top() = 0;
    virtual const T &top() const = 0;
    virtual size_t size() const = 0;
    virtual bool empty() const = 0;
};