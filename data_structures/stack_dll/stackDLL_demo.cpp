#include "stackDLL.h"
#include <iostream>

void f(StackDLL<int> &stack)
{
    int i = 3;
    stack.push(i);
}

int main()
{
    StackDLL<int> stack;
    stack.push(5);
    f(stack);
    std::cout << "stack: " << stack.top() << " " << stack.top();
    return 0;
}