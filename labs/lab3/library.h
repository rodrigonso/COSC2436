#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class library
{
private:
    int cost;
    vector<string> data;
    queue<string> tmp;
    bool isCompSci(string title);
    void processQueue(queue<string> &q);
    void processTmp();

public:
    library();
    bool isFull();
    bool isEmpty();
    void insert(string title);
    void initialize(int numOfBooks, queue<string> &q1, queue<string> &q2);
    vector<string> toVector();
    void print();
    int getCost();
};

library::library() { cost = 0; }
int library::getCost() { return cost; }
bool library::isEmpty() { return data.empty(); }
bool library::isCompSci(string title) { return title.find("compsci") != string::npos; }
void library::insert(string title) { data.push_back(title); }
void library::processQueue(queue<string> &q)
{
    string title = q.front();
    q.pop();
    if (isCompSci(title))
    {
        data.push_back(title);
        cost += 20;
    }
    else
    {
        tmp.push(title);
        cost += 10;
    }
}

void library::processTmp()
{
    while (!tmp.empty())
    {
        string curr = tmp.front();
        tmp.pop();
        data.push_back(curr);
        cost += 20;
    }
}

void library::initialize(int numOfBooks, queue<string> &q1, queue<string> &q2)
{
    for (int i = 0; i < numOfBooks; i++)
    {
        if (!q1.empty())
            processQueue(q1);
        if (!q2.empty())
            processQueue(q2);
    }
    processTmp();
}

void library::print()
{
    for (int i = 0; i < data.size(); i++)
        cout << data.at(i) << endl;
}

vector<string> library::toVector()
{
    vector<string> res(data);
    return res;
}

/*

cost of putting book = 20seconds
cost of discarding book = 10seconds

q1 [compsiB]
q2 [compsiC]
tmp [math, art,novel,]
lib [compsiA]
*/
