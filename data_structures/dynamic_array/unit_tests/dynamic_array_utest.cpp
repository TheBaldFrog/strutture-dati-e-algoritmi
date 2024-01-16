#include "catch.hpp"
#include "dynamic_array.h"

TEST_CASE("Dynamic array is empty and has no buffer on construction with "
          "default constructor")
{
    DynamicArray arr;
    REQUIRE(arr.empty());
    REQUIRE(arr.capacity() == 0);
    REQUIRE(!arr.data());
}

TEST_CASE("Dynamic array has correct size when using size constructor")
{
    DynamicArray arr{23};
    REQUIRE(!arr.empty());
    REQUIRE(arr.capacity() >= 23);
    REQUIRE(arr.size() == 23);
}