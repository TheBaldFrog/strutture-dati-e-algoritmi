#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include "dynamic_array.h"

template <typename T>
class Heap
{
public:
    Heap(const bool isMin = true) : isMin(isMin) {}
    Heap(const DynamicArray<T> &arr, const bool isMin = true)
        : data(arr), isMin(isMin)
    {
        // Heapify
        for (int i = (int)data.size(); i >= 0; i--)
            siftDown(i);
    }
    Heap(const std::vector<T> &arr, const bool isMin = true)
        : data(arr), isMin(isMin)
    {
        // Heapify
        for (int i = (int)data.size(); i >= 0; i--)
            siftDown(i);
    }

    DynamicArray<T> getCopy() { return data; }
    // const DynamicArray<T> &getCopy() const { return data; }

    /**
     * Based on the greater function getMin or getMax
     */
    const T &top() const
    {
        return data.at(0);
    }

    /**
     * Based on the greater function extractMin or extractMax
     */
    void pop()
    {
        if (data.empty())
        {
            throw std::runtime_error{"heap is empty"};
        }

        std::swap(data[0], data[data.size() - 1]);
        data.pop_back();
        siftDown(0);
    }

    void push(const T &val)
    {
        data.push_back(val);
        siftUp(static_cast<int>(data.size()) - 1);
    }

    void decreaseKey(const int &index, const T &val)
    {
        if (val > 0)
        {
            data.at(index) -= val;
            if (isMin)
                siftUp(index);
            else
                siftDown(index);
        }
    }

    static void heapSort(DynamicArray<T> &arr, const bool reversed = false)
    {
        Heap<T> heap(arr, !reversed);

        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = heap.top();
            heap.pop();
        }
    }

    static void heapSort(std::vector<T> &arr, const bool reversed = false)
    {
        Heap<T> heap(arr, !reversed);

        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = heap.top();
            heap.pop();
        }
    }

    static void heapSort(Heap &heap, const bool reversed = false)
    {
        Heap<T> resultHeap(heap.data, !reversed);

        for (int i = 0; i < heap.data.size(); i++)
        {
            heap.data[i] = resultHeap.top();
            resultHeap.pop();
        }
    }

private:
    bool isMin;
    DynamicArray<T> data;
    int length;

    static int left(const int index) { return 2 * index + 1; }
    static int right(const int index) { return 2 * index + 2; }
    static int parent(const int index) { return (index - 1) / 2; }

    bool greater(const T &t1, const T &t2) const
    {
        if (isMin)
            return t1 < t2;
        else
            return t1 > t2;
    }

    void siftUp(int index)
    {
        if (index <= 0)
            return;

        int parentIndex = parent(index);

        if (greater(data[index], data[parentIndex]))
        {
            std::swap(data[index], data[parentIndex]);
            siftUp(parentIndex);
        }
    }

    void siftDown(int index)
    {
        int smallest = index;
        int leftChild = left(index);
        int rightChild = right(index);

        if (leftChild < data.size() && greater(data[leftChild], data[smallest]))
            smallest = leftChild;

        if (rightChild < data.size() && greater(data[rightChild], data[smallest]))
            smallest = rightChild;

        if (smallest != index)
        {
            std::swap(data[index], data[smallest]);
            siftDown(smallest);
        }
    }
};