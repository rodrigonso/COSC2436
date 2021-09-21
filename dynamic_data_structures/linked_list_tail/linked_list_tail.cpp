#include <iostream>
#include "linked_list_tail.h"

using namespace std;

LinkedListTail::LinkedListTail()
{
    head = 0;
    tail = 0;
}

bool LinkedListTail::isEmpty()
{
    return head == 0;
}

void LinkedListTail::insertAtBeg(int number)
{
    Node *tmp = new Node();
    tmp->data = number;
    tmp->next = 0;

    if (isEmpty())
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        Node *old = head;
        head = tmp;
        head->next = old;
    }
}
void LinkedListTail::insertAtEnd(int number)
{

    Node *tmp = new Node();
    tmp->data = number;
    tmp->next = 0;

    if (isEmpty())
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tmp;
    }
}

void LinkedListTail::print()
{
    Node *curr = head;

    while (curr != 0)
    {
        cout << curr->data << endl;
        curr = curr->next;
    }
}