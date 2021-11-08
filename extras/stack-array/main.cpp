#include <iostream>
#include "stacka.cpp"
using namespace std;

int main()
{
    stacka<int> stack(10);
    stack.pop();
    stack.peek();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.pop();
    stack.push(4);

    stack.print();

    return 0;
}