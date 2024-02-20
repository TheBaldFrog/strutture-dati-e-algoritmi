#include "catch.hpp"
#include "queue_using_stacks.h"

TEST_CASE("QUEUE is empty")
{
    QueueUsingStacks<int> que;

    REQUIRE(que.empty());
    que.enqueue(1);

    REQUIRE(!que.empty());
    que.dequeue();
    REQUIRE(que.empty());
}

TEST_CASE("QUEUE copy constructor")
{
    QueueUsingStacks<int> que1;
    que1.enqueue(1);
    que1.enqueue(2);

    QueueUsingStacks<int> que2(que1);
    REQUIRE(que2.dequeue() == 1);
    REQUIRE(que2.dequeue() == 2);
    REQUIRE(que2.empty());

    REQUIRE(!que1.empty());
    REQUIRE(que1.dequeue() == 1);
    REQUIRE(que1.dequeue() == 2);
    REQUIRE(que1.empty());
}

TEST_CASE("QUEUE enqueue and dequeue methods")
{
    QueueUsingStacks<int> que;

    for (int i = 1; i <= 500; i++)
    {
        que.enqueue(i);
    }

    int y = 1;
    for (int i = 500; i >= 1; i--)
    {
        REQUIRE(que.dequeue() == y++);
    }

    REQUIRE(que.empty());
}