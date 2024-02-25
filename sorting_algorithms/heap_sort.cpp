#include <iostream>
#include <vector>

// Helper function to maintain the min-heap property
void heapify(std::vector<int> &arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        std::swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

// In-place heap sort
void heapSort(std::vector<int> &arr)
{
    int n = (int)arr.size();

    // Build a min-heap
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; --i)
    {
        std::swap(arr[0], arr[i]); // Move current root to the end
        heapify(arr, i, 0);        // Heapify the reduced heap
    }
}

int main()
{
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    heapSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}