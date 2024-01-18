#include "dynamic_array.h"
#include <iostream>
#include <vector>

void print(const DynamicArray &arr)
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
    DynamicArray arr;

    for (size_t i = 0; i < 10; i++)
    {
        arr.push_back(static_cast<double>(i));
    }

    double sum = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    print(arr);
    std::cout << "Sum of array elements is: " << sum << '\n';

    for (size_t i = 1; i < 10; i++)
    {
        print(arr);
        arr.pop_back();
    }
    print(arr);

    std::cout << "Array capacity: " << arr.capacity() << '\n';
    std::cout << "Array size: " << arr.size() << '\n';

    arr.shrink_to_fit();
    std::cout << "Array capacity: " << arr.capacity() << '\n';
    arr[0] = 1;
    print(arr);
    arr.pop_back();
    print(arr);

    // vector insert at
    std::vector<int> a{1, 2, 3, 4};
    // a.insert(a.begin() + 2, 7);
    a.insert(a.begin() + 4, 8);

    std::cout << a[0] << a[1] << a[2] << a[3] << a[4] << "\n";
    // ----------------

    arr.insert(0, 2);
    arr.insert(0, 1);
    arr.insert(0, 0);
    arr.insert(2, 4);
    // std::cout << arr.at(0) << "\n";
    print(arr);
    std::cout << "size: " << arr.size() << "\n";
    std::cout << "cap: " << arr.capacity() << "\n";

    arr.insert(4, 8);
    print(arr);

    DynamicArray arr3;
    std::cout << "3size: " << arr3.size() << "\n";
    std::cout << "3cap: " << arr3.capacity() << "\n";

    arr3.insert(0, 2);
    std::cout << "3size: " << arr3.size() << "\n";
    std::cout << "3cap: " << arr3.capacity() << "\n";
    arr3.insert(0, 1);
    arr3.insert(0, 0);
    arr3.insert(2, 4);
    arr3.insert(4, 5);
    std::cout << "3size: " << arr3.size() << "\n";
    std::cout << "3cap: " << arr3.capacity() << "\n";
    print(arr3);

    return 0;
}