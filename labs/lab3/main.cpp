#include <iostream>
#include <queue>
#include <fstream>
#include "library.h"
#include "ArgumentManager.h"
using namespace std;

int parseInput(ifstream &file, queue<string> &q1, queue<string> &q2);
void writeToFile(ofstream &file, library &lib);
int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);
    ifstream input;
    ofstream output;

    string inFileName = am.get("input");
    string outFileName = am.get("output");

    input.open(inFileName);
    output.open(outFileName);

    queue<string> q1, q2;
    int bookCount = parseInput(input, q1, q2);

    library lib;
    lib.initialize(bookCount, q1, q2);
    writeToFile(output, lib);

    return 0;
}

int parseInput(ifstream &file, queue<string> &q1, queue<string> &q2)
{
    string line;
    int queueNum = 0;
    int bookCount = 0;
    while (getline(file, line))
    {
        stringstream st(line);
        string title;
        while (getline(st, title, ','))
        {
            bookCount++;
            if (queueNum == 0)
                q1.push(title);
            if (queueNum == 1)
                q2.push(title);
        }
        queueNum++;
    }
    return bookCount;
}

void writeToFile(ofstream &file, library &lib)
{
    vector<string> res = lib.toVector();
    file << lib.getCost() << endl;
    for (int i = 0; i < res.size(); i++)
    {
        file << res.at(i);
        if (i < res.size() - 1)
            file << ',';
    }
    file.close();
}
