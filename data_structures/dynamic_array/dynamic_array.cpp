#include "dynamic_array.h"

DynamicArray::DynamicArray(size_t initialSize)
{
    m_arr = new double[initialSize];
    m_currentSize = initialSize;
    m_currentCapacity = initialSize;
}

size_t DynamicArray::size() const { return m_currentSize; }

size_t DynamicArray::capacity() const { return m_currentCapacity; }

bool DynamicArray::empty() const { return m_currentSize == 0; }

double *DynamicArray::data() noexcept { return m_arr; }