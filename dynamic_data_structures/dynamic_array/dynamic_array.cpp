#include <iostream>
#include "dynamic_array.h"

using namespace std;

DynamicArray::DynamicArray(int s)
{
    size = s;
    count = 0;
    data = new int[size];
}

void DynamicArray::push(int item)
{
    // if the array is already full, we increase the size by a factor of 2
    // and copy the elements to this new larger array
    if (count + 1 > size)
    {
        int *tmp = new int[size * 2];
        for (int i = 0; i < count; i++)
        {
            tmp[i] = data[i];
        }
        data = tmp;
    }
    data[count] = item;
    count++;
}
void DynamicArray::pop()
{
    data[count] = 0;
    count--;
}
void DynamicArray::print()
{
    cout << '[';
    for (int i = 0; i < count; i++)
    {
        cout << data[i];
        if (i != count - 1)
        {
            cout << ',';
        }
    }
    cout << ']' << endl;
}

DynamicArray::~DynamicArray()
{
    delete data;
}