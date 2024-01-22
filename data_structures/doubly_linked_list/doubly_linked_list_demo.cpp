#include "doubly_linked_list.h"
#include <iostream>

template <typename T>
void print(DoublyLinkedList<T> &list)
{
    DoublyLinkedListIterator<T> it = list.begin();
    for (; it != list.end(); ++it)
    {
        std::cout << *it << ' ';
    }

    // it points to the last element now
    std::cout << *it << std::endl;
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
    for (; it != list.end(); ++it)
    {
        sum += *it;
    }

    sum += *it;

    std::cout << "Sum of elements: " << sum << std::endl;

    return 0;
}