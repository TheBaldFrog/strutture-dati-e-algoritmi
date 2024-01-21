#include "catch.hpp"
#include "doubly_linked_list.h"

TEST_CASE("Doubly linked list is empty on construction with defaults constructor")
{
    DoublyLinkedList<int> list;
    REQUIRE(list.empty());
    REQUIRE(list.size() == 0);
}