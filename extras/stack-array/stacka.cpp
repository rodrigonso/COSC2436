#include <iostream>
#include "stacka.h"

using namespace std;

template <typename T>
stacka<T>::stacka(int s)
{
    size = s;
    data = new T[size];
    topIdx = -1;
}

template <typename T>
bool stacka<T>::isEmpty() { return topIdx == -1; }

template <typename T>
bool stacka<T>::isFull() { return topIdx + 1 >= size; }

template <typename T>
void stacka<T>::push(T d)
{
    if (isFull())
        return;
    data[++topIdx] = d;
}

template <typename T>
void stacka<T>::pop()
{
    if (isEmpty())
        return;
    topIdx--;
}

template <typename T>
void stacka<T>::print()
{
    for (int i = topIdx; i >= 0; i--)
    {
        cout << data[i] << endl;
    }
}

template <typename T>
T stacka<T>::peek()
{
    return data[topIdx];
}
