#include "dynamic_array.h"

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
    print(arr);

    return 0;
}