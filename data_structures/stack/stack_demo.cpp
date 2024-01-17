#include "stack_dynamic_array.h"
#include <iostream>

void f(StackDynamicArrayImpl<int> &stack)
{
    int i = 3;
    stack.push(i);
}

int main()
{
    StackDynamicArrayImpl<int> stack;
    stack.push(5);
    f(stack);
    std::cout << "stack: " << stack.top() << " " << stack.top();
    return 0;
}