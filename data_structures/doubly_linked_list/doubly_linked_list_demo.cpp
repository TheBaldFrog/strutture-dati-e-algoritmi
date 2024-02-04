#include "doubly_linked_list.h"
#include <iostream>

template <typename T>
void print(DoublyLinkedList<T> &list)
{
    DoublyLinkedListIterator<T> it = list.begin();
    for (const auto &elem : list)
    {
        std::cout << elem << ' ';
    }

    // it points to the last element now
    std::cout << std::endl;
}

int main()
{
    DoublyLinkedList<int> list;
    for (int i = 1; i <= 10; i++)
    {
        list.push_back(i);
    }

    print(list);

    int sum = 0;
    DoublyLinkedListIterator<int> it = list.begin();
    for (const auto &elem : list)
    {
        sum += elem;
    }

    std::cout << "Sum of elements: " << sum << std::endl;

    return 0;
}