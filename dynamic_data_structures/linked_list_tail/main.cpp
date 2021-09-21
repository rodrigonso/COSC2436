#include "linked_list_tail.cpp"

int main()
{

    LinkedListTail list;
    list.insertAtBeg(10);
    list.insertAtBeg(20);
    list.insertAtBeg(30);
    list.insertAtBeg(40);
    list.insertAtEnd(200);
    list.insertAtEnd(400);
    list.print();

    return 0;
}