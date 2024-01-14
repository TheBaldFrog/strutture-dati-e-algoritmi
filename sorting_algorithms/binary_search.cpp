#include <iostream>
#include <vector>

int binarySearchRecursive(int array[], int x, int low, int high)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] > x)
            return binarySearchRecursive(array, x, low, mid - 1);
        else
            return binarySearchRecursive(array, x, mid + 1, high);
    }

    return -1;
}

int binarySearch(std::vector<int> &input, int x)
{
    int low = 0;
    int high = static_cast<int>(input.size() - 1);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (input[mid] == x)
            return mid;

        if (input[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    std::vector numbers = {3, 4, 5, 6, 7, 8, 9};
    int result = binarySearch(numbers, 4);
    if (result == -1)
        std::cout << "Not found";
    else
        std::cout << "Element is found at index " << result << '\n';

    int array[] = {3, 4, 5, 6, 7, 8, 9};
    int x = 4;
    int n = sizeof(array) / sizeof(array[0]);
    result = binarySearchRecursive(array, x, 0, n - 1);
    if (result == -1)
        std::cout << "Not found";
    else
        std::cout << "Element is found at index " << result;
}