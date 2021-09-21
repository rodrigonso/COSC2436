#include "linked_list.h"
#include "task.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
    head = 0;
}

LinkedList::LinkedList(Task t)
{
    for (int i = 0; i < t.getSize(); i++)
    {
        string curr = t.getDataAtIndex(i);
        Node *tmp = new Node();
        tmp->data = curr;
        tmp->next = 0;

        if (i == 0)
        {
            head = tmp;
        }
    }
}

LinkedList::~LinkedList()
{
    delete head;
    delete tail;
}

void LinkedList::print()
{
    Node *curr = head;

    while (curr != tail)
    {
        cout << curr->data << "->";
        curr = curr->next;
    }
}