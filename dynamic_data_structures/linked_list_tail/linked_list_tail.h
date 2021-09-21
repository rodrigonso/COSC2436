struct Node
{
    int data;
    Node *next;
};

class LinkedListTail
{
private:
    Node *head;
    Node *tail;

    bool isEmpty();

public:
    LinkedListTail();
    void insertAtBeg(int number);
    void insertAtEnd(int number);
    void print();
};