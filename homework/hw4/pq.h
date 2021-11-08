#include "command.h"
#include <iostream>
using namespace std;

struct node
{
    int priority;
    command data;
    node *right;
    node()
    {
        priority = INT_MAX;
        right = nullptr;
        data = command();
    }
};

class PQ
{
private:
    node *front;

public:
    PQ() { front = nullptr; }
    void push(command c);
    void pop();
    command top() { return front->data; }
    bool empty() { return front == nullptr; }
};

void PQ::push(command c)
{
    int p = c.getPriority();

    node *tmp = new node();
    tmp->data = c;
    tmp->priority = p;

    if (empty() || p < front->priority)
    {
        tmp->right = front;
        front = tmp;
    }
    else
    {
        node *curr = front;
        while (curr->right != nullptr && curr->right->priority <= p)
            curr = curr->right;

        tmp->right = curr->right;
        curr->right = tmp;
    }
}

void PQ::pop()
{
    if (empty())
        return;
    node *tmp = front;
    front = front->right;
    delete tmp;
}
