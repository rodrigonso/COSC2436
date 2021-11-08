#ifndef LINKED_LIST
#define LINKED_LIST
#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *next;
};

class LinkedList
{
private:
    int length;
    Node *head;
    Node *sorted;

    bool predicate(Node *a, Node *b, string type)
    {
        if (type == "Length")
            return a->data.length() < b->data.length();
        return a->data < b->data;
    }

public:
    LinkedList()
    {
        head = 0;
        sorted = 0;
        length = 0;
    }

    void addAtBeg(string str)
    {

        if (contains(str))
            return;

        Node *tmp = new Node();
        tmp->data = str;
        tmp->next = head;
        head = tmp;
        length++;
    }
    void addAtEnd(string str)
    {
        if (contains(str))
            return;

        Node *tmp = new Node();
        tmp->data = str;
        tmp->next = 0;

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
        length++;
    };

    void sort(string type)
    {

        Node *cur1 = head;
        Node *cur2 = head;

        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length - 1; j++)
            {
                if (predicate(cur1, cur2, type))
                {
                    string temp = cur1->data;
                    cur1->data = cur2->data;
                    cur2->data = temp;
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

    bool contains(string str)
    {
        Node *curr = head;
        while (curr != 0)
        {
            if (curr->data == str)
                return true;
            curr = curr->next;
        }

        return false;
    }

    void addAtIdx(int idx, string data)
    {

        if (contains(data) || idx > length)
            return;

        Node *tmp = new Node();
        tmp->data = data;

        if (idx == 0)
        {
            tmp->next = head;
            head = tmp;
            return;
        }

        Node *curr = head;
        for (int i = 1; i < idx - 1; i++)
        {
            curr = curr->next;
        }

        Node *old = curr->next;
        curr->next = tmp;
        tmp->next = old;
    }

    bool isEmpty()
    {
        return head == 0;
    }

    void remove(string str)
    {

        Node *dummy = new Node();
        dummy->next = head;

        while (dummy->next != 0)
        {
            cout << dummy->data << endl;
            Node *right = dummy->next;
            if (right->data.find(str) != string::npos)
            {
                dummy->next = right->next;
                continue;
            }
            dummy = dummy->next;
        }
    }

    Node *getHead()
    {
        return head;
    }

    void print()
    {
        Node *curr = head;

        while (curr != 0)
        {
            cout << curr->data << endl;
            curr = curr->next;
        }

        cout << endl;
    }
};

#endif