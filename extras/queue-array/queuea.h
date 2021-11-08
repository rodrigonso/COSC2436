#include <iostream>
using namespace std;

class queuea
{
private:
    int size;
    int frontIdx;
    int backIdx;
    int *data;

    bool isFull();

public:
    queuea(int s = 10);
    void enqeue(int data);
    void deqeue();
    int front();
    int back();
    bool isEmpty();
    void print();
};

queuea::queuea(int s)
{
    size = s;
    frontIdx = backIdx = -1;
    data = new int[s];
}

bool queuea::isEmpty() { return backIdx == -1; }
bool queuea::isFull() { return backIdx >= size - 1; }

void queuea::enqeue(int d)
{
    if (isFull())
        return;
    if (isEmpty())
        frontIdx++;
    backIdx++;
    data[backIdx] = d;
}

void queuea::deqeue()
{
    if (isEmpty())
        return;
    frontIdx++;
}

void queuea::print()
{
    for (int i = frontIdx; i <= backIdx; i++)
    {
        cout << data[i] << endl;
    }
}

int queuea::front() { return data[frontIdx]; }
int queuea::back() { return data[backIdx]; }
