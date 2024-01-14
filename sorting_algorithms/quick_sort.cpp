#include <iostream>
#include <vector>

int partition(int arr[], int start, int end)
{
    // choose last element as pivot
    int pivot = arr[end];

    int lastSmallestThanPivotElementIndex = start - 1;

    for (int i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            lastSmallestThanPivotElementIndex++;
            std::swap(arr[lastSmallestThanPivotElementIndex], arr[i]);
        }
    }

    int pivotIndex = lastSmallestThanPivotElementIndex + 1;
    std::swap(arr[pivotIndex], arr[end]);
    return pivotIndex;
}

// O(n*log n)
void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int partitionIndex = partition(arr, start, end);
        quickSort(arr, start, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, end);
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }

    std::cout << std::endl;
}

int main()
{
    int arr[] = {5, 48, 1, 123, 45, 23, 1, 8, 9, 23, 45, 3, 7, 17, 12};
    int size = sizeof(arr) / sizeof(int);
    print(arr, size);
    quickSort(arr, 0, size - 1);
    print(arr, size);
}