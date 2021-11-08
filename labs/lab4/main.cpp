#include <iostream>
#include <vector>
#include <fstream>
#include "pqueue.h"
#include "ArgumentManager.h"
using namespace std;

void parseInput(ifstream &file, pqueue &pq);
int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);
    ifstream input;
    ofstream output;

    string inputn = am.get("input");
    string outputn = am.get("output");

    input.open(inputn);
    output.open(outputn);

    pqueue pq;
    parseInput(input, pq);

    while (!pq.empty())
    {
        task t = pq.front();
        pq.pop();

        output << t.name << endl;
    }

    return 0;
}

void parseInput(ifstream &file, pqueue &pq)
{
    string line;
    while (getline(file, line))
    {
        if (line.empty())
            continue;

        string n, p;

        int i = 0;
        int j = 1;

        while (j < line.length() && line[j] < 48 || line[j] > 57)
            j++;
        n = line.substr(i, j - 1);

        i = j;
        j = j + 1;
        p = line.substr(i, j);

        task t(n, p);
        pq.push(t);
    }
}
