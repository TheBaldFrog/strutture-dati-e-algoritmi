#pragma once

#include "istack.h"
#include <stdexcept>
#include "doubly_linked_list.h"

template <typename T>
class StackDLL final : public IStack<T>
{
public:
    virtual void push(const T &newElem) override;
    virtual void pop() override;
    virtual T &top() override;
    virtual const T &top() const override;
    virtual size_t size() const override;
    virtual bool empty() const override;

    StackDLL &operator=(const StackDLL &other);

private:
    DoublyLinkedList<T> m_dll;
};

template <typename T>
inline void StackDLL<T>::push(const T &newElem)
{
    m_dll.push_back(newElem);
}

template <typename T>
inline void StackDLL<T>::pop()
{
    m_dll.pop_back();
}

template <typename T>
inline T &StackDLL<T>::top()
{
    if (empty())
    {
        throw std::runtime_error{"Trying to access top element of Empty stack"};
    }

    return m_dll.back();
}

template <typename T>
inline const T &StackDLL<T>::top() const
{
    if (empty())
    {
        throw std::runtime_error{"Trying to access top element of Empty stack"};
    }

    return m_dll.back();
}

template <typename T>
inline size_t StackDLL<T>::size() const
{
    return m_dll.size();
}

template <typename T>
inline bool StackDLL<T>::empty() const
{
    return m_dll.empty();
}

template <typename T>
inline StackDLL<T> &StackDLL<T>::operator=(const StackDLL &other)
{
    if (this != &other)
    {
        m_dll = other.m_dll;
    }

    return *this;
}
