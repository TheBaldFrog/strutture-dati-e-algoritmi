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

    i = 0;
    for (const auto& elem : list)
    {
        REQUIRE(elem == i++);
    }

    it = list.begin();

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

TEST_CASE("Test inserting one element in the brginning")
{
    DoublyLinkedList<int> list;
    list.push_front(1);

    auto it = list.begin();
    auto insertIt = list.insertBefore(it, 2);

    REQUIRE(*it == 1);
    REQUIRE(*insertIt == 2);

    REQUIRE(insertIt == list.begin());
}

TEST_CASE("Test insertion many elements")
{
    DoublyLinkedList<int> list;

    // add even numbers
    for (int i = 2; i <= 100; i += 2)
    {
        list.push_back(i);
    }

    REQUIRE(list.size() == 50);

    // now add the
    auto it = list.begin();
    ++it;

    for (int i = 3; i <= 100; i += 2)
    {
        list.insertBefore(it, i);
        ++it;
    }

    it = list.begin();
    for (int i = 2; i <= 100; i++)
    {
        REQUIRE(*it == i);
        ++it;
    }
}

TEST_CASE("Erase at beginning")
{
    DoublyLinkedList<int> list;
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.erase(list.begin());

    auto it = list.begin();
    REQUIRE(*it == 6);
    ++it;
    REQUIRE(*it == 7);
}

TEST_CASE("Erase at middle")
{
    DoublyLinkedList<int> list;
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    auto it = list.begin();
    ++it;
    auto afterErasedIt = list.erase(it);
    REQUIRE(*afterErasedIt == 7);
    afterErasedIt--;
    REQUIRE(*afterErasedIt == 5);
    REQUIRE(list.size() == 2);
}

TEST_CASE("Erase many numbers")
{
    DoublyLinkedList<int> list;
    for (int i = 1; i <= 100; i++)
    {
        list.push_back(i);
    }

    REQUIRE(list.size() == 100);

    auto it = list.begin();
    ++it;

    for (int i = 3; i <= 100; i +=2)
    {
        it = list.erase(it);
        REQUIRE(*it == i);
        ++it;
    }

    it = list.begin();
    for (int i = 1; i <= 100; i += 2)
    {
        REQUIRE(*it == i);
        ++it;
    }

    REQUIRE(list.size() == 51);
}