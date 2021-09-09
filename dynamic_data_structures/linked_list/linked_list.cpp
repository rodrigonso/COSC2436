#include <iostream>
#include "linked_list.h"

using namespace std;

LinkedList::LinkedList()
{
    head = 0;
}

Node *LinkedList::getHead()
{
    return head;
}

Node *LinkedList::insertAtBeg(int data)
{
    Node *tmp = new Node();
    tmp->data = data;
    tmp->next = head;
    head = tmp;

    return tmp;
}

Node *LinkedList::insertAtIdx(int data, int idx = 0)
{
    Node *tmp = new Node();
    tmp->data = data;

    Node *curr = head;
    for (int i = 1; i < idx - 1; i++)
    {
        curr = curr->next;
    }

    Node *old = curr->next;
    curr->next = tmp;
    tmp->next = old;

    return tmp;
}

Node *LinkedList::insertAtEnd(int data)
{
    Node *tmp = new Node();
    tmp->data = data;
    tmp->next = nullptr;

    if (head == nullptr)
    {
        head = tmp;
        return tmp;
    }

    Node *curr = head;
    while (curr->next != 0)
    {
        curr = curr->next;
    }

    curr->next = tmp;
    return tmp;
}

void LinkedList::removeNode(Node *node)
{
    // This method can handle the cases where you want to remove a node
    // at beg, end, or any position -- by simply passing the desired to
    // this method.

    if (head == nullptr)
    {
        return;
    }

    Node *curr = head;
    while (curr->next != node)
    {
        curr = curr->next;
    }

    Node *tmp = node->next;
    curr->next = tmp;
    delete node;
}

void LinkedList::print()
{
    Node *itr = head;
    while (itr != 0)
    {
        cout << itr->data;
        if (itr->next != 0)
        {
            cout << "->";
        }
        itr = itr->next;
    }
    cout << '\n';
}