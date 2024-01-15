#include "dynamic_array.h"

size_t DynamicArray::capacity() const { return m_currentCapacity; }

bool DynamicArray::empty() const { return m_currentSize == 0; }

double *DynamicArray::data() noexcept
{
    return m_arr;
}