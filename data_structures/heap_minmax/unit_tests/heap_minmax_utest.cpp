#include "catch.hpp"
#include "heap_minmax.h"

TEST_CASE("Testing Heap-min push siftUp top")
{
    Heap<int> heap(true); // min heap

    heap.push(10);
    heap.push(20);
    heap.push(15);
    heap.push(30);
    heap.push(25);
    REQUIRE(heap.top() == 10);

    for (int i = 0; i <= 500; i++)
    {
        heap.push(i);
    }
    REQUIRE(heap.top() == 0);

    heap.push(-4);
    heap.push(10000);
    REQUIRE(heap.top() == -4);

    heap.pop();
    REQUIRE(heap.top() == 0);
}

TEST_CASE("Testing Heap-Max push siftUp top")
{
    Heap<int> heap(false); // max heap

    heap.push(10);
    heap.push(20);
    heap.push(15);
    heap.push(30);
    heap.push(25);
    REQUIRE(heap.top() == 30);

    for (int i = 0; i <= 500; i++)
    {
        heap.push(i);
    }
    REQUIRE(heap.top() == 500);

    heap.push(-4);
    heap.push(10000);
    REQUIRE(heap.top() == 10000);

    heap.pop();
    REQUIRE(heap.top() == 500);
}

TEST_CASE("Testing Heap-min pop siftDown")
{
    Heap<int> heap;
    for (int i = 1; i <= 500; i++)
    {
        heap.push(i);
    }

    for (int i = 1; i <= 499; i++)
    {
        heap.pop();
    }

    REQUIRE(heap.top() == 500);
    heap.pop();
    REQUIRE_THROWS_AS(heap.pop(), std::runtime_error);
    heap.push(5);
    heap.push(6);
    REQUIRE(heap.top() == 5);
}

TEST_CASE("Testing Heap-max pop siftDown")
{
    Heap<int> heap(false);
    for (int i = 1; i <= 500; i++)
    {
        heap.push(i);
    }

    for (int i = 1; i <= 499; i++)
    {
        heap.pop();
    }

    REQUIRE(heap.top() == 1);
    heap.pop();
    REQUIRE_THROWS_AS(heap.pop(), std::runtime_error);
    heap.push(5);
    heap.push(6);
    REQUIRE(heap.top() == 6);
}

TEST_CASE("Heap-min decreaseKey")
{
    Heap<int> heap;

    heap.push(5);
    heap.push(4);
    heap.push(7);
    heap.push(2);

    REQUIRE(heap.top() == 2);

    heap.push(3);
    REQUIRE(heap.top() == 2);

    heap.decreaseKey(1, 2);
    REQUIRE(heap.top() == 1);
}

TEST_CASE("Heap-max decreaseKey")
{
    Heap<int> heap(false);

    heap.push(5);
    heap.push(3);
    heap.push(7);
    heap.push(2);

    // Verify that the top element is the maximum value (7)
    REQUIRE(heap.top() == 7);

    // Add a new element (6) and ensure it's correctly positioned
    heap.push(6);
    REQUIRE(heap.top() == 7); // The top element should still be 7 after insertion

    // Decrease the key of an existing element (6 to 4)
    heap.decreaseKey(0, 4);
    REQUIRE(heap.top() == 6); // The top element should now be 6 after decreasing the key
}

TEST_CASE("Heap-min sort")
{
    Heap<int> heap;
    heap.push(95);
    heap.push(37);
    heap.push(-4);
    heap.push(60);
    heap.push(1);
    heap.push(2);
    heap.push(57);
    heap.push(18);
    heap.push(2);
    heap.push(-9);
    heap.push(28);
    heap.push(23);
    heap.push(99);

    heap.heapSort();
    auto copy = heap.getCopy();

    for (int i = 0; i < copy.size() - 1; i++)
    {
        REQUIRE(copy[i] <= copy[i + 1]);
    }

    heap.heapSort(true);
    copy = heap.getCopy();

    for (int i = 0; i < copy.size() - 1; i++)
    {
        REQUIRE(copy[i] >= copy[i + 1]);
    }
}

TEST_CASE("Heap-max sort")
{
    Heap<int> heap(false);
    heap.push(95);
    heap.push(37);
    heap.push(-4);
    heap.push(60);
    heap.push(1);
    heap.push(2);
    heap.push(57);
    heap.push(18);
    heap.push(2);
    heap.push(-9);
    heap.push(28);
    heap.push(23);
    heap.push(99);

    heap.heapSort();
    auto copy = heap.getCopy();

    for (int i = 0; i < copy.size() - 1; i++)
    {
        REQUIRE(copy[i] >= copy[i + 1]);
    }

    heap.heapSort(true);
    copy = heap.getCopy();

    for (int i = 0; i < copy.size() - 1; i++)
    {
        REQUIRE(copy[i] <= copy[i + 1]);
    }
}

TEST_CASE("Heap sort Dynamic array")
{
    DynamicArray<int> arr;
    arr.push_back(95);
    arr.push_back(37);
    arr.push_back(-4);
    arr.push_back(60);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(57);
    arr.push_back(18);
    arr.push_back(2);
    arr.push_back(-9);
    arr.push_back(28);
    arr.push_back(23);
    arr.push_back(99);

    Heap<int>::heapSort(arr);

    for (int i = 0; i < arr.size() - 1; i++)
    {
        REQUIRE(arr[i] <= arr[i + 1]);
    }

    Heap<int>::heapSort(arr, true);

    for (int i = 0; i < arr.size() - 1; i++)
    {
        REQUIRE(arr[i] >= arr[i + 1]);
    }
}

TEST_CASE("Heap sort std::vector")
{
    std::vector<int> arr;
    arr.push_back(95);
    arr.push_back(37);
    arr.push_back(-4);
    arr.push_back(60);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(57);
    arr.push_back(18);
    arr.push_back(2);
    arr.push_back(-9);
    arr.push_back(28);
    arr.push_back(23);
    arr.push_back(99);

    Heap<int>::heapSort(arr);

    for (int i = 0; i < arr.size() - 1; i++)
    {
        REQUIRE(arr[i] <= arr[i + 1]);
    }

    Heap<int>::heapSort(arr, true);

    for (int i = 0; i < arr.size() - 1; i++)
    {
        REQUIRE(arr[i] >= arr[i + 1]);
    }
}

TEST_CASE("Heap-min find() and get()")
{
    Heap<int> heap;

    for (int i = 0; i < 500; i++)
    {
        heap.push(i);
    }

    for (int i = 500 / 2; i >= 0; i--)
    {

        REQUIRE(heap.find(i) == i);
        REQUIRE(heap.get(i) == i);
    }

    for (int i = 500 / 2; i < 500; i++)
    {
        REQUIRE(heap.find(i) == i);
        REQUIRE(heap.get(i) == i);
    }
}

TEST_CASE("Heap-max find() and get()")
{
    Heap<int> heap(false);

    for (int i = 0; i < 500; i++)
    {
        heap.push(i);
    }

    for (int i = 0; i < 500; i++)
    {
        int t = heap.find(i);
        REQUIRE(i == heap.get(t));
    }
    heap.push(502);
    heap.decreaseKey(0, 1);
    REQUIRE(heap.get(0) == 501);
    REQUIRE(heap.find(501) == 0);
}

TEST_CASE("Heap-min deleteElement()")
{
    Heap<int> heap;

    for (int i = 0; i < 500; i++)
    {
        heap.push(i);
    }

    for (int i = 0; i < 500; i++)
    {
        int t = heap.find(i);
        REQUIRE_NOTHROW(heap.deleteElement(t));
        REQUIRE(heap.find(i) == -1);
    }

    REQUIRE(heap.empty());
}

TEST_CASE("Heap-max deleteElement()")
{
    Heap<int> heap(false);

    for (int i = 0; i < 500; i++)
    {
        heap.push(i);
    }

    for (int i = 0; i < 500; i++)
    {
        int t = heap.find(i);
        REQUIRE_NOTHROW(heap.deleteElement(t));
        REQUIRE(heap.find(i) == -1);
    }

    REQUIRE(heap.empty());
}