#include <iostream>
#include <vector>

// O(n2)
void bubbleSort(std::vector<int> &vector)
{
    for (int i = 0; i < vector.size() - 1; i++)
    {
        bool isSwapped = false;

        for (int j = 0; j < vector.size() - i - 1; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;

                isSwapped = true;
            }
        }

        if (!isSwapped)
            break;
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
    // std::vector numbers = {5, 48, 1, 123, 45, 23, 1, -1};
    std::vector numbers = {1, 2, 3, -1, 123, 45, 7};
    print(numbers);
    bubbleSort(numbers);
    print(numbers);
}