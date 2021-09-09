#include <iostream>
#include "linked_list.cpp"

using namespace std;

int main()
{
    LinkedList list;

    list.insertAtBeg(10);
    list.insertAtBeg(20);
    list.insertAtBeg(30);
    list.insertAtBeg(40);
    list.insertAtBeg(50);

    list.print();
    Node *testTwo = list.insertAtIdx(100, 4);
    cout << endl;
    list.print();
    cout << endl;
    Node *test = list.insertAtEnd(200);
    list.print();
    cout << endl;
    list.removeNode(test);
    list.removeNode(testTwo);
    list.print();

    return 0;
}