#include <iostream>
#include <vector>

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
        std::cout << "Element is found at index " << result;
}