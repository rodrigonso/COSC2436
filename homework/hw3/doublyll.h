#include <iostream>
#include "equation.h"
using namespace std;

struct node
{
    equation data;
    node *prev;
    node *next;
};

class doublyll
{
private:
    node *tail;
    node *head;

    void remove(int pos);
    equation *find(string query);

public:
    doublyll();
    void insert(equation eq);
    void removeList(string type, int pos);
    void convertList(string type);
    void printList(int order);
    bool isEmpty() { return head == nullptr; }
};

doublyll::doublyll()
{
    head = nullptr;
    tail = nullptr;
}

void doublyll::insert(equation eq)
{
    node *tmp = new node();
    tmp->data = eq;
    tmp->next = nullptr;
    if (isEmpty())
    {
        head = tmp;
        tail = tmp;
        tmp->prev = nullptr;
        return;
    }

    node *curr = head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }

    curr->next = tmp;
    tmp->prev = curr;
    tail = tmp;
    return;
}

void doublyll::remove(int pos)
{
    if (isEmpty())
        return;
    int counter = 0;
    node *curr = head;
    while (curr != nullptr)
    {
        counter++;
        curr = curr->next;
        if (counter == pos)
            break;
    }
    cout << curr->data.toString() << endl;
}

void doublyll::removeList(string type, int pos = -1)
{
    if (type == "position")
    {
        remove(pos);
    }
    else
    {
    }
}

equation *doublyll::find(string query)
{
}

void doublyll::printList(int order = 1)
{
    if (order == 1)
    {
        node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data.toString() << endl;
            curr = curr->next;
        }
    }
    else
    {
        node *curr = tail;
        while (curr != nullptr)
        {
            cout << curr->data.toString() << endl;
            curr = curr->prev;
        }
    }
}
