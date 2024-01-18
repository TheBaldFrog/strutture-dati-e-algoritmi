#include "dynamic_array.h"
#include <stdexcept>

DynamicArray::DynamicArray(size_t initialSize)
{
    m_arr = new double[initialSize];

    // initialize array with 0
    for (size_t i = 0; i < initialSize; i++)
    {
        m_arr[i] = 0;
    }

    m_currentSize = initialSize;
    m_currentCapacity = initialSize;
}

DynamicArray::DynamicArray(const DynamicArray &other)
{
    m_arr = new double[other.m_currentCapacity];
    for (size_t i = 0; i < other.m_currentSize; i++)
    {
        m_arr[i] = other.m_arr[i];
    }

    m_currentSize = other.m_currentSize;
    m_currentCapacity = other.m_currentCapacity;
}

DynamicArray &DynamicArray::operator=(const DynamicArray &other)
{
    if (this != &other)
    {
        double *newArr = new double[other.m_currentCapacity];
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

DynamicArray::~DynamicArray() { delete[] m_arr; }

size_t DynamicArray::size() const { return m_currentSize; }

size_t DynamicArray::capacity() const { return m_currentCapacity; }

void DynamicArray::shrink_to_fit()
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

    double *newArr = new double[m_currentSize];
    m_currentCapacity = m_currentSize;

    for (size_t i = 0; i < m_currentSize; i++)
    {
        newArr[i] = m_arr[i];
    }

    delete[] m_arr;
    m_arr = newArr;
}

bool DynamicArray::empty() const { return m_currentSize == 0; }

double *DynamicArray::data() noexcept { return m_arr; }

void DynamicArray::clear() { m_currentSize = 0; }

void DynamicArray::push_back(double value)
{
    if (m_currentCapacity == 0)
    {
        m_arr = new double[1];
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

    // static const int RESIZE_CONSTANT = 2;

    const size_t newCapacity = m_currentCapacity * RESIZE_CONSTANT;
    double *newArr = new double[newCapacity];

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

void DynamicArray::pop_back()
{
    if (empty())
    {
        throw std::runtime_error("Calling pop_back() on an empty container");
    }

    --m_currentSize;
}

void DynamicArray::insert(size_t index, double value)
{
    // m_current size = 10 | 0 -> 9
    if (index > m_currentSize)
    {
        throw std::out_of_range{"Index out of range."};
    }

    if (index <= m_currentSize)
    {
        if (m_currentSize == m_currentCapacity)
        {
            if (m_currentCapacity == 0)
                m_currentCapacity++;
            const size_t newCapacity = m_currentCapacity * RESIZE_CONSTANT;
            double *newArr = new double[newCapacity];
            m_currentSize++;

            for (size_t i = 0; i < index; i++)
            {
                newArr[i] = m_arr[i];
            }

            newArr[index] = value;

            for (size_t i = index + 1; i < m_currentSize; i++)
            {
                newArr[i] = m_arr[i - 1];
            }

            delete[] m_arr;
            m_arr = newArr;
            m_currentCapacity = newCapacity;
        }
        else
        {
            m_currentSize++;
            double t = m_arr[index];
            double t1;
            m_arr[index] = value;

            for (size_t i = index + 1; i < m_currentSize; i++)
            {
                t1 = m_arr[i];
                m_arr[i] = t;
                t = t1;
            }
        }
    }
}

double &DynamicArray::at(size_t index) const
{
    if (index < 0 || index >= m_currentSize)
    {
        throw std::out_of_range{"Index out of range."};
    }

    return m_arr[index];
}

double &DynamicArray::operator[](size_t index)
{
    return m_arr[index];
}

const double &DynamicArray::operator[](size_t index) const
{
    return m_arr[index];
}

bool operator==(const DynamicArray &lhs, const DynamicArray &rhs)
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

bool operator!=(const DynamicArray &lhs, const DynamicArray &rhs)
{
    return !(lhs == rhs);
}