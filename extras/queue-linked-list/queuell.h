#include <iostream>
using namespace std;

struct node
{
    int data;
    node *prev, *next;
};

class queuell
{
private:
    node *front, *back;

public:
    queuell() { front = back = nullptr; }
    void enqueu(int d);
    void dequeu();
    int getFront();
    int getBack();
    bool isEmpty() { return front == nullptr; }
    void print();
};

void queuell::enqueu(int d)
{
    node *tmp = new node();
    tmp->next = nullptr;
    tmp->data = d;
    if (isEmpty())
    {
        tmp->prev = nullptr;
        front = tmp;
        back = tmp;
    }
    else
    {
        node *og = back;
        og->next = tmp;
        tmp->prev = og;
        back = tmp;
    }
}

void queuell::dequeu()
{
    if (isEmpty())
        return;
    node *tmp = front;
    front = tmp->next;
    front->prev = nullptr;
    delete tmp;
}

void queuell::print()
{
    node *curr = front;
    while (curr != nullptr)
    {
        cout << curr->data << endl;
        curr = curr->next;
    }
}

int queuell::getFront() { return isEmpty() ? -1 : front->data; }
int queuell::getBack() { return isEmpty() ? -1 : back->data; }
