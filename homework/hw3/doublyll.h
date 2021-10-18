#include <iostream>
#include <fstream>
#include "eequation.h"
#include <vector>
using namespace std;

struct node
{
    eequation data;
    node *prev;
    node *next;
};

class doublyll
{
private:
    int size;
    node *tail;
    node *head;

public:
    doublyll();
    void insert(eequation eq, int post = -1);
    void remove(eequation &eq, int pos = -1);
    void convertList(string type, int pos);
    void printList(ofstream &output, int order);
    bool isEmpty() { return head == nullptr; }
    vector<eequation *> find(string query);
};

doublyll::doublyll()
{
    size = 0;
    head = nullptr;
    tail = nullptr;
}

void doublyll::insert(eequation eq, int pos)
{
    node *tmp = new node();
    tmp->data = eq;
    tmp->next = nullptr;
    tmp->prev = nullptr;

    size++;

    if (isEmpty())
    {
        head = tmp;
        tail = tmp;
        return;
    }

    if (pos == 0)
    {
        node *next = head;
        head = tmp;
        tmp->next = next;
        return;
    }
    else
    {
        node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }

        curr->next = tmp;
        tmp->prev = curr;
        tail = tmp;
        return;
    }
}

void doublyll::remove(eequation &eq, int pos)
{
    if (isEmpty())
        return;

    node *curr = head;
    while (curr != nullptr)
    {
        if (curr->data.getExpression() == eq.getExpression())
            break;
        curr = curr->next;
    }

    if (curr == nullptr)
        return;

    if (curr->prev == nullptr)
    {
        // its head
        head = curr->next;
    }

    if (curr->next != nullptr)
    {
        // its tail
        curr->next->prev = curr->prev;
    }

    if (curr->prev != nullptr)
    {
        curr->prev->next = curr->next;
    }
}

void doublyll::convertList(string type, int pos = -1)
{
    if (type == "position")
    {
        int counter = 0;
        node *curr = head;
        while (curr != nullptr)
        {
            if (counter == pos)
                break;
            curr = curr->next;
            counter++;
        }

        if (curr != nullptr)
            curr->data.convert();
    }
    else
    {
        vector<eequation *> res = find(type);
        for (int i = 0; i < res.size(); i++)
        {
            (*res.at(i)).convert();
        }
    }
}

vector<eequation *> doublyll::find(string query)
{
    vector<eequation *> res;
    node *curr = head;

    while (curr != nullptr)
    {
        if (query == "all")
            res.push_back(&curr->data);
        else
        {
            if (curr->data.getType() == query)
                res.push_back(&curr->data);
        }
        curr = curr->next;
    }
    return res;
}

void doublyll::printList(ofstream &file, int order = 1)
{
    if (order == 1)
    {
        file << "List:" << endl;
        if (isEmpty())
        {
            file << "EMPTY" << endl;
            file << endl;
            return;
        }
        node *curr = head;
        while (curr != nullptr)
        {
            file << curr->data.toString() << endl;
            curr = curr->next;
        }
        file << endl;
    }
    else
    {
        file << "Reversed List:" << endl;
        node *curr = tail;
        while (curr != nullptr)
        {
            file << curr->data.toString() << endl;
            curr = curr->prev;
        }
        file << endl;
    }
}

class rstack
{
private:
    int topIdx;
    int size;
    eequation *data;

    bool isFull() { return topIdx + 1 >= size; }

public:
    bool isEmpty() { return topIdx == -1; }
    rstack(int s = 10);
    void push(eequation eq);
    void pop();
    eequation top();
    void reverse();
    void printSize(ofstream &file);
    void printTop(ofstream &file);
    void empty();
    void print();
};

rstack::rstack(int s)
{
    topIdx = -1;
    size = s;
    data = new eequation[s];
}

void rstack::push(eequation eq)
{
    if (isFull())
        return;
    data[++topIdx] = eq;
}

void rstack::pop()
{
    if (isEmpty())
        return;
    topIdx--;
}

eequation rstack::top() { return data[topIdx]; }

void rstack::printTop(ofstream &output)
{
    output << "Top of Reserve: ";
    output << data[topIdx].toString() << endl;
    output << endl;
}

void rstack::printSize(ofstream &output)
{
    output << "Reserve Size: ";
    output << topIdx + 1 << endl;
    output << endl;
}

void rstack::reverse()
{
    eequation *res = new eequation[size];
    for (int i = 0; i <= topIdx; i++)
        res[topIdx - i] = data[i];
    data = res;
}

void rstack::print()
{
    for (int i = topIdx; i >= 0; i--)
        cout << data[i].toString() << endl;
}
