#include "catch.hpp"
#include "doubly_linked_list.h"

TEST_CASE("Doubly linked list is empty on construction with defaults constructor")
{
    DoublyLinkedList<int> list;
    REQUIRE(list.empty());
    REQUIRE(list.size() == 0);
}

TEST_CASE("Push back test")
{
    DoublyLinkedList<int> list;
    for (int i = 1; i <= 1000; i++)
    {
        list.push_back(i);
        REQUIRE(list.size() == i);
        REQUIRE(list.back() == i);
        REQUIRE(!list.empty());
    }
}

TEST_CASE("Push back and then pop back many elements")
{
    DoublyLinkedList<int> list;
    for (int i = 1; i <= 1000; i++)
    {
        list.push_back(i);
    }

    for (int i = 1000; i >= 1; i--)
    {
        REQUIRE(list.back() == i);
        REQUIRE(list.size() == i);
        list.pop_back();
    }

    REQUIRE(list.empty());
}

TEST_CASE("Push front and then pop front many elements")
{
    DoublyLinkedList<int> list;
    for (int i = 1; i <= 1000; i++)
    {
        list.push_front(i);
        REQUIRE(list.size() == i);
        REQUIRE(list.front() == i);
    }

    for (int i = 1000; i >= 1; i--)
    {
        REQUIRE(list.front() == i);
        REQUIRE(list.size() == i);
        list.pop_front();
    }

    REQUIRE(list.empty());

    for (int i = 1; i <= 1000; i++)
    {
        list.push_front(i);
        REQUIRE(list.size() == i);
        REQUIRE(list.front() == i);
    }

    for (int i = 1; i <= 1000; i++)
    {
        REQUIRE(list.back() == i);
        REQUIRE(list.size() == 1001 - i);
        list.pop_back();
    }

    REQUIRE(list.empty());
}

TEST_CASE("Push a lot of elements and then clear the list")
{
    DoublyLinkedList<int> list;
    for (int i = 0; i < 15'000; i++)
    {
        list.push_front(i + 10);
        list.push_back(i - 10);
    }

    REQUIRE(list.size() == 30'000);
    list.clear();
    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());
}

TEST_CASE("Push a lot of elements test iterators")
{
    DoublyLinkedList<int> list;
    for (int i = 0; i < 30'000; i++)
    {
        list.push_back(i);
    }

    DoublyLinkedListIterator<int> it = list.begin();
    int i = 0;
    for (; it != list.end(); ++it)
    {
        REQUIRE(*it == i++);
    }

    REQUIRE(it == list.end());
    REQUIRE(i == 29'999);
    REQUIRE(*it == i);

    for (; it != list.begin(); --it)
    {
        REQUIRE(*it == i--);
    }

    REQUIRE(it == list.begin());
    REQUIRE(i == 0);
    REQUIRE(*it == i);

    auto anotherIt = list.begin();
    REQUIRE(anotherIt == it);

    auto it1 = list.begin(), it2 = list.begin();
    auto old = it1++;
    REQUIRE(*old == 0);
    it1++;
    it2++;
    it2++;

    REQUIRE(it1 == it2);
    REQUIRE(*it1 == 2);

    it1--;
    it1--;
    REQUIRE(it1 == old);

    *old = 6969;
    REQUIRE(*list.begin() == 6969);
}