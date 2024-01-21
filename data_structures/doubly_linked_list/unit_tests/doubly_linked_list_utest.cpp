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