#include <iostream>
#include <vector>

std::vector<int> merge(const std::vector<int> &left_sorted,
                       const std::vector<int> &right_sorted);

// O(n*log n)
void mergeSort(std::vector<int> &input)
{
    if (input.size() > 1)
    {
        // split input into two sub-arrays
        std::vector<int> left, right;
        int middle = input.size() / 2;

        for (int i = 0; i < middle; i++)
        {
            left.push_back(input[i]);
        }

        for (int i = middle; i < input.size(); i++)
        {
            right.push_back(input[i]);
        }

        mergeSort(left);
        mergeSort(right);
        input = merge(left, right);
    }
}

std::vector<int> merge(const std::vector<int> &left_sorted,
                       const std::vector<int> &right_sorted)
{
    std::vector<int> merged_result;

    int li = 0, ri = 0;
    while (li < left_sorted.size() && ri < right_sorted.size())
    {
        if (left_sorted[li] <= right_sorted[ri])
        {
            merged_result.push_back(left_sorted[li++]);
        }
        else
        {
            merged_result.push_back(right_sorted[ri++]);
        }
    }

    for (; li < left_sorted.size(); li++)
    {
        merged_result.push_back(left_sorted[li]);
    }

    for (; ri < right_sorted.size(); ri++)
    {
        merged_result.push_back(right_sorted[ri]);
    }

    return merged_result;
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
    std::vector numbers = {
        5,
        48,
        1,
        123,
        45,
        23,
        1,
        -1,
        0,
    };
    print(numbers);
    mergeSort(numbers);
    print(numbers);
}
