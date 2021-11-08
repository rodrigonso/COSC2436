#include <iostream>
#include "stackll.h"

using namespace std;

template <typename T>
stackll<T>::stackll()
{
    top = nullptr;
}

template <typename T>
bool stackll<T>::isEmpty() { return top == nullptr; }

template <typename T>
void stackll<T>::push(T d)
{
    node<T> *tmp = new node<T>();
    tmp->data = d;

    if (isEmpty())
    {
        top = tmp;
        tmp->next = nullptr;
    }
    else
    {
        tmp->next = top;
        top = tmp;
    }
}

template <typename T>
void stackll<T>::pop()
{
    if (isEmpty())
        return;
    node<T> *tmp = top;
    top = top->next;
    delete tmp;
}

template <typename T>
T stackll<T>::peek()
{
    return top->data;
}

template <typename T>
void stackll<T>::print()
{
    node<T> *curr = top;
    while (curr != nullptr)
    {
        cout << curr->data << endl;
        curr = curr->next;
    }
}