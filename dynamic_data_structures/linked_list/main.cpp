#include <iostream>
#include "linked_list.cpp"

using namespace std;

int main()
{
    LinkedList list;
    // Insert Operations
    list.insertAtBeg(1);
    list.insertAtBeg(2);
    list.insertAtBeg(3);
    list.print();

    Node *itemA = list.insertAtIdx(100, 4);
    Node *itemB = list.insertAtEnd(200);
    list.print();

    // Remove operations
    list.removeNode(itemA);
    list.removeNode(itemB);
    list.print();

    return 0;
}