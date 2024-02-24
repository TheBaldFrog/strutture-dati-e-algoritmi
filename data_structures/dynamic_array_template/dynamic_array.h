#pragma once

#include <stdexcept>
#include <vector>

template <typename T>
class DynamicArray
{
public:
    DynamicArray() = default;
    DynamicArray(size_t initialSize);
    DynamicArray(const DynamicArray &other);
    DynamicArray(const std::vector<T> &other);
    DynamicArray &operator=(const DynamicArray &);
    ~DynamicArray();

    /**
     * Appends the given element value to the end of
     * the container
     */
    void push_back(const T &value);

    /**
     * Removes the last element of the container.
     * Calling pop_back on an empty container throws exception.
     * @throw std::runtime_error
     */
    void pop_back();

    /**
     * Checks if index is out pf bounds and throws exception if it is
     * @throw std::out_of_range
     * ! make method const
     */
    T &at(size_t index) const;

    /**
     * Access element without checking if index is out of bounds
     */
    T &operator[](size_t index);
    const T &operator[](size_t index) const;

    T &back();
    const T &back() const;

    /**
     * Returns number of elements in the array
     */
    size_t size() const;

    /**
     * Returns the size of the internal buffer
     */
    size_t capacity() const;

    /**
     * Requests the container to reduce its capacity to fit its size
     */
    void shrink_to_fit();

    /**
     * Returns whether the array is empty of elements or not
     */
    bool empty() const;

    /**
     * Clears the array's content without modifying the internal buffer
     * after calling it, size() will return 0, nut capacity() will remain
     * the same before calling it
     */
    void clear();

    /**
     * Returns a direct pointer to the memory array used internally
     * by the dynamic array to store its owned elements.
     */
    T *data() noexcept;

private:
    T *m_arr = nullptr;
    size_t m_currentSize = 0;
    size_t m_currentCapacity = 0;
};

template <typename T>
DynamicArray<T>::DynamicArray(size_t initialSize)
{
    m_arr = new T[initialSize];

    // initialize array with 0
    for (size_t i = 0; i < initialSize; i++)
    {
        m_arr[i] = 0;
    }

    m_currentSize = initialSize;
    m_currentCapacity = initialSize;
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray &other)
{
    m_arr = new T[other.m_currentCapacity];
    for (size_t i = 0; i < other.m_currentSize; i++)
    {
        m_arr[i] = other.m_arr[i];
    }

    m_currentSize = other.m_currentSize;
    m_currentCapacity = other.m_currentCapacity;
}

template <typename T>
inline DynamicArray<T>::DynamicArray(const std::vector<T> &other)
{
    for (int i = 0; i < other.size(); i++)
    {
        push_back(other[i]);
    }
}

template <typename T>
DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray &other)
{
    if (this != &other)
    {
        T *newArr = new T[other.m_currentCapacity];
        for (size_t i = 0; i < other.m_currentSize; i++)
        {
            newArr[i] = other.m_arr[i];
        }

        delete[] m_arr;
        m_arr = newArr;
        m_currentSize = other.m_currentSize;
        m_currentCapacity = other.m_currentCapacity;
    }

    return *this;
}

template <typename T>
void DynamicArray<T>::push_back(const T &value)
{
    if (m_currentCapacity == 0)
    {
        m_arr = new T[1];
        m_arr[0] = value;
        m_currentSize = 1;
        m_currentCapacity = 1;
        return;
    }

    if (m_currentSize < m_currentCapacity)
    {
        m_arr[m_currentSize++] = value;
        return;
    }

    static const int RESIZE_CONSTANT = 2;

    const size_t newCapacity = m_currentCapacity * RESIZE_CONSTANT;
    T *newArr = new T[newCapacity];

    // copy
    int i = 0;
    for (; i < m_currentSize; i++)
    {
        newArr[i] = m_arr[i];
    }

    newArr[i] = value;
    ++m_currentSize;

    delete[] m_arr;
    m_arr = newArr;
    m_currentCapacity = newCapacity;
}

template <typename T>
void DynamicArray<T>::pop_back()
{
    if (empty())
    {
        throw std::runtime_error("Calling pop_back() on an empty container");
    }

    --m_currentSize;
}

template <typename T>
T &DynamicArray<T>::at(size_t index) const
{
    if (index < 0 || index >= m_currentSize)
    {
        throw std::out_of_range{"Index out of range."};
    }

    return m_arr[index];
}

template <typename T>
T &DynamicArray<T>::operator[](size_t index)
{
    return m_arr[index];
}

template <typename T>
const T &DynamicArray<T>::operator[](size_t index) const
{
    return m_arr[index];
}

template <typename T>
inline T &DynamicArray<T>::back()
{
    return m_arr[size() - 1];
}

template <typename T>
inline const T &DynamicArray<T>::back() const
{
    return m_arr[size() - 1];
}

template <typename T>
DynamicArray<T>::~DynamicArray() { delete[] m_arr; }

template <typename T>
size_t DynamicArray<T>::size() const { return m_currentSize; }

template <typename T>
size_t DynamicArray<T>::capacity() const { return m_currentCapacity; }

template <typename T>
bool operator==(const DynamicArray<T> &lhs, const DynamicArray<T> &rhs)
{
    if (lhs.size() != rhs.size())
    {
        return false;
    }

    for (size_t i = 0; i < lhs.size(); i++)
    {
        if (lhs[i] != rhs[i])
        {
            return false;
        }
    }

    return true;
}

template <typename T>
bool operator!=(const DynamicArray<T> &lhs, const DynamicArray<T> &rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool DynamicArray<T>::empty() const { return m_currentSize == 0; }

template <typename T>
T *DynamicArray<T>::data() noexcept { return m_arr; }

template <typename T>
void DynamicArray<T>::clear() { m_currentSize = 0; }

template <typename T>
void DynamicArray<T>::shrink_to_fit()
{
    if (m_currentSize == m_currentCapacity)
    {
        return;
    }

    if (m_currentSize == 0 && m_currentCapacity > 0)
    {
        delete[] m_arr;
        m_arr = nullptr;
        m_currentCapacity = 0;
        return;
    }

    // m_currentSize < m_currentCapacity

    T *newArr = new T[m_currentSize];
    m_currentCapacity = m_currentSize;

    for (size_t i = 0; i < m_currentSize; i++)
    {
        newArr[i] = m_arr[i];
    }

    delete[] m_arr;
    m_arr = newArr;
}