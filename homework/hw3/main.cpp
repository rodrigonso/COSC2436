#include <iostream>
#include <fstream>
#include "ArgumentManager.h"
#include "doublyll.h"
using namespace std;

void parseInput(ifstream &file, doublyll &res);
void removeSpaces(string &str);
int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);
    ifstream input;
    ofstream output;

    string inputFile = am.get("input");
    string commandFile = am.get("command");
    string outputFile = am.get("output");

    doublyll list;

    input.open(inputFile);
    parseInput(input, list);
    // list.printList(-1);
    list.removeList("position");
    return 0;
}

void parseInput(ifstream &file, doublyll &res)
{
    string line;
    while (getline(file, line))
    {
        stringstream st(line);
        string type, val;
        getline(st, type, ':');
        getline(st, val, ':');
        equation eq(type, val);

        res.insert(eq);
    }
}