#include <iostream>
#include "stackll.cpp"
using namespace std;

int main()
{
    stackll<int> stack;
    stack.pop();

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.pop();
    stack.push(4);
    stack.push(5);
    stack.push(10);
    stack.peek();

    stack.print();

    return 0;
}