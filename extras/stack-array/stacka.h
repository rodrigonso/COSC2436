#include <iostream>
using namespace std;

template <typename T>
class stacka
{
private:
    int size;
    int topIdx;
    T *data;

public:
    stacka(int s);
    void print();
    void push(T data);
    void pop();
    bool isEmpty();
    bool isFull();
    T peek();
};