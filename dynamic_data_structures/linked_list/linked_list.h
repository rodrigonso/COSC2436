class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList();
    Node *insertAtBeg(int data);
    Node *insertAtIdx(int data, int idx);
    Node *insertAtEnd(int data);
    void removeNode(Node *node);
    Node *getHead();
    void print();
};