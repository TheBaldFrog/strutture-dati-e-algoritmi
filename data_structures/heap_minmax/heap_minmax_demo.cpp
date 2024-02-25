#include <iostream>
#include "heap_minmax.h"

template <typename T>
void printDynamicArr(const DynamicArray<T> &arr)
{
    if (arr.empty())
    {
        std::cout << "The array is empty.\n";
        return;
    }

    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << ' ';
    }

    std::cout << '\n';
}

int main()
{
    Heap<int> h;
    h.push(5);
    h.push(4);
    h.push(3);
    h.push(8);
    h.push(2);
    h.push(10);
    h.push(2);
    h.push(-2);
    h.push(1);
    h.push(55);
    h.push(34);

    Heap<int>::heapSort(h);
    std::cout << h << '\n';

    Heap<int>::heapSort(h, true);
    std::cout << h << '\n';

    DynamicArray<int> arr;
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(8);
    arr.push_back(2);
    arr.push_back(10);
    arr.push_back(-1);
    arr.push_back(2);
    Heap<int>::heapSort(arr);
    printDynamicArr(arr);
    Heap<int>::heapSort(arr, true);
    printDynamicArr(arr);

    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(3);
    vec.push_back(8);
    vec.push_back(2);
    vec.push_back(10);
    vec.push_back(-2);
    vec.push_back(2);
    Heap<int>::heapSort(vec);
    for (const auto &i : vec)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    Heap<int>::heapSort(vec, true);
    for (const auto &i : vec)
    {
        std::cout << i << ' ';
    }

    std::cout << "\n\n";
    int ind = h.find(34);
    std::cout << ind << '\n';
    auto ir = h.get(ind);
    std::cout << ir << '\n';
    h.decreaseKey(ind, 2);
    std::cout << h;

    std::cout << "\n\n";
    int ft = h.find(32);
    std::cout << ft << '\n';
    h.deleteElement(ft);
    std::cout << h.find(32) << '\n';
    std::cout << h.empty() << '\n';

    std::cout << h << '\n';
    Heap<int>::heapSort(h);
    std::cout << h;
}