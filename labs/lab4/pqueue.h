#include <iostream>
#include <vector>
using namespace std;

struct task
{
    double priority;
    string name;
    task(string n, string p)
    {
        name = n;
        priority = stod(p);
    }
};

class pqueue
{
private:
    vector<task> data;
    void buildHeap();
    void heapify(int idx);

public:
    bool empty() { return data.size() == 0; }
    void push(task t);
    void pop();
    void print();
    task front() { return data[0]; }
};

void pqueue::print()
{
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i].priority << endl;
    }
}

void pqueue::push(task t)
{
    data.push_back(t);
    buildHeap();
}

void pqueue::pop()
{
    data.erase(data.begin());
    buildHeap();
}

void pqueue::buildHeap()
{
    int start = (data.size() / 2) - 1;
    for (int i = start; i >= 0; i--)
        heapify(i);
}

void pqueue::heapify(int idx)
{
    int smallest = idx;
    int left = (2 * idx) + 1;
    int right = (2 * idx) + 2;

    if (left < data.size() && data[left].priority < data[smallest].priority)
        smallest = left;
    if (right < data.size() && data[right].priority < data[smallest].priority)
        smallest = right;

    if (idx != smallest)
    {
        task tmp = data[idx];
        data[idx] = data[smallest];
        data[smallest] = tmp;

        heapify(smallest);
    }
}
