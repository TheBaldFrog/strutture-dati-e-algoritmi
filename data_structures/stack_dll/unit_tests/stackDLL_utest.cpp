#include "catch.hpp"
#include "stackDLL.h"

TEST_CASE("Stack is empty on construction with default constructor")
{
    StackDLL<int> stack;
    REQUIRE(stack.empty());
    REQUIRE(stack.size() == 0);
    REQUIRE_THROWS_AS(stack.top(), std::runtime_error);
}

TEST_CASE("Push and pop one one elemnt on stack")
{
    StackDLL<int> stack;
    stack.push(5);

    REQUIRE(stack.size() == 1);
    REQUIRE(!stack.empty());
    REQUIRE(stack.top() == 5);

    stack.pop();
    REQUIRE(stack.size() == 0);
    REQUIRE(stack.empty());
    REQUIRE_THROWS_AS(stack.top(), std::runtime_error);
}

TEST_CASE("Push and pop many elements on stack")
{
    StackDLL<int> stack;

    for (int i = 1; i <= 1000; i++)
    {
        stack.push(i);
        REQUIRE(stack.top() == i);
        REQUIRE(stack.size() == i);
    }

    for (int i = 1000; i >= 1; i--)
    {
        REQUIRE(stack.size() == i);
        REQUIRE(stack.top() == i);
        stack.pop();
    }

    REQUIRE(stack.empty());
}