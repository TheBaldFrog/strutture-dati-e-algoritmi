#pragma once

#include "istack.h"
#include <stdexcept>
#include "../dynamic_array_template/dynamic_array.h"

template <typename T>
class StackDynamicArrayImpl final : public IStack<T>
{
public:
    virtual void push(const T &newElem) override;
    virtual void pop() override;
    virtual T &top() override;
    virtual const T &top() const override;
    virtual size_t size() const override;
    virtual bool empty() const override;

private:
    DynamicArray<T> m_dynArr;
};

template <typename T>
inline void StackDynamicArrayImpl<T>::push(const T &newElem)
{
    m_dynArr.push_back(newElem);
}

template <typename T>
inline void StackDynamicArrayImpl<T>::pop()
{
    m_dynArr.pop_back();
}

template <typename T>
inline T &StackDynamicArrayImpl<T>::top()
{
    if (empty())
    {
        throw std::runtime_error{"Trying to access top element of Empty stack"};
    }

    return m_dynArr.back();
}

template <typename T>
inline const T &StackDynamicArrayImpl<T>::top() const
{
    if (empty())
    {
        throw std::runtime_error{"Trying to access top element of Empty stack"};
    }

    return m_dynArr.back();
}

template <typename T>
inline size_t StackDynamicArrayImpl<T>::size() const
{
    return m_dynArr.size();
}

template <typename T>
inline bool StackDynamicArrayImpl<T>::empty() const
{
    return m_dynArr.empty();
}
