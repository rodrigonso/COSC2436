#include <iostream>
#include "equation.h"
using namespace std;

class rstack
{
private:
    int size;
    int topIdx;
    equation *data;

public:
    rstack(int s = 10);
    void push(equation e);
    void pop();
    equation peek();
};

rstack::rstack(int s)
{
    topIdx = -1;
    data = new equation[s];
}

void rstack::push(equation e)
{
}

void rstack::pop()
{
}

equation rstack::peek() { return data[topIdx]; }
