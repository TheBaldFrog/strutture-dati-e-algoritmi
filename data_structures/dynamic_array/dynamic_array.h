#pragma once

#include <iostream>
#include <vector>

class DynamicArray
{
public:
    DynamicArray() = default;
    DynamicArray(size_t initialSize);
    DynamicArray(const DynamicArray &);
    DynamicArray &operator=(const DynamicArray &);

    void push_back(double value);
    void pop_back();

    /**
     * Checks if index is out pf bounds and throws exception if it is
     * @throw std::out_of_range
     * ! make method const
     */
    double &at(size_t index);

    /**
     * Access element without checking if index is out of bounds
     */
    double &operator[](size_t index);

    /**
     * Returns number of elements in the array
     */
    size_t size() const;

    /**
     * Returns the size of the internal buffer
     */
    size_t capacity() const;

    bool empty() const;

    /**
     * Clears the array's content without modifying the internal buffer
     * after calling it, size() will return 0, nut capacity() will remain
     * the same before calling it
     */
    void clear() const;

    /**
     * Returns a direct pointer to the memory array used internally
     * by the dynamic array to store its owned elements.
     */
    double *data() noexcept;

private:
    double *m_arr = nullptr;
    size_t m_currentSize = 0;
    size_t m_currentCapacity = 0;
};