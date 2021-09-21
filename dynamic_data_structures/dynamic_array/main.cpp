#include "dynamic_array.cpp"

int main()
{

    DynamicArray arr;
    arr.push(1);
    arr.push(2);
    arr.push(4);
    arr.push(5);
    arr.push(6);
    arr.push(7);
    arr.push(8);
    arr.push(9);
    arr.push(10);
    arr.push(11);
    arr.push(12);
    arr.push(13);
    arr.print();

    arr.pop();
    arr.pop();
    arr.pop();
    arr.pop();
    arr.print();

    return 0;
}