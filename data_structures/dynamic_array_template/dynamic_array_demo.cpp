#include "dynamic_array.h"
#include <iostream>

template <typename T>
void print(const DynamicArray<T> &arr)
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
    DynamicArray<double> arr;

    for (int i = 1; i <= 10; i++)
    {
        arr.push_back(static_cast<double>(i));
    }

    double sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    print(arr);
    std::cout << "Sum of array elements is: " << sum << '\n';

    for (int i = 1; i <= 10; i++)
    {
        print(arr);
        arr.pop_back();
    }

    print(arr);

    std::cout << "Array capacity: " << arr.capacity() << '\n';
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(10.0);
    }

    print(arr);
    arr.clear();
    print(arr);
    std::cout << "Array capacity: " << arr.capacity() << '\n';

    arr.shrink_to_fit();
    std::cout << "Array capacity: " << arr.capacity() << '\n';

    return 0;
}