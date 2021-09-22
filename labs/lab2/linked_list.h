#include <iostream>
using namespace std;

struct Node
{
    string name;
    int score;
    Node *next;
};

class LinkedList
{
private:
    int length;
    Node *head;

    string formatData(string s1);
    void swap(Node *node1, Node *node2);

public:
    LinkedList();
    void sort();
    void add(string name, int score);
    void print();
    string trim(string str);
    Node *getHead()
    {
        return head;
    }
};

LinkedList::LinkedList()
{
    head = 0;
    length = 0;
}

string LinkedList::trim(string str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

void LinkedList::swap(Node *node1, Node *node2)
{
    int tempScore = node1->score;
    string tempName = node1->name;
    node1->score = node2->score;
    node1->name = node2->name;
    node2->score = tempScore;
    node2->name = tempName;
}

void LinkedList::add(string name, int score)
{
    Node *tmp = new Node();

    tmp->name = trim(name);
    tmp->score = score;
    tmp->next = 0;

    length++;

    if (head == 0)
    {
        head = tmp;
        return;
    }

    Node *curr = head;
    while (curr->next != 0)
    {
        curr = curr->next;
    }

    curr->next = tmp;
    return;
}

void LinkedList::sort()
{

    Node *cur1 = head;
    Node *cur2 = head;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1; j++)
        {
            if (cur1->score > cur2->score)
            {
                swap(cur1, cur2);
            }
            cur2 = cur2->next;
        }
        cur2 = head;
        cur1 = head->next;
        for (int k = 0; k < i; k++)
        {
            cur1 = cur1->next;
        }
    }
}

void LinkedList::print()
{
    Node *curr = head;
    while (curr != 0)
    {
        cout << curr->name << " " << curr->score << endl;
        curr = curr->next;
    }
    cout << endl;
}
