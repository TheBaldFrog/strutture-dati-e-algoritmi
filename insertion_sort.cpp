#include <iostream>
#include <vector>

void insertionSort(std::vector<int> &vector)
{
    for (int step = 0; step < vector.size(); step++)
    {
        int key = vector[step];
        int j = step - 1;

        while (j >= 0 && key < vector[j])
        {
            vector[j + 1] = vector[j];
            j--;
        }

        vector[j + 1] = key;
    }
}

void print(const std::vector<int> &vector)
{
    for (const auto &elem : vector)
    {
        std::cout << elem << " ";
    }

    std::cout << std::endl;
}

int main()
{
    std::vector numbers = {5, 48, 1, 123, 45, 23, 1};
    print(numbers);
    insertionSort(numbers);
    print(numbers);
}
