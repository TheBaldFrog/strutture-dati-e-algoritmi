#include <iostream>
#include <vector>

// O(n2)
void selectionSort(std::vector<int> &vector)
{
    for (int i = 0; i < vector.size(); i++)
    {
        int min = i;
        for (int j = i + 1; j < vector.size(); j++)
        {
            if (vector[j] < vector[min])
                min = j;
        }

        int temp = vector[min];
        vector[min] = vector[i];
        vector[i] = vector[temp];
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
    std::vector numbers = {5, 48, 1, 123, 45, 23, 1, -1};
    print(numbers);
    selectionSort(numbers);
    print(numbers);
}
