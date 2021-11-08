#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "ArgumentManager.h"
#include "linked_list.h"
#include "task.h"
using namespace std;
void parseCommands(ifstream &file, LinkedList &list);

int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);
    ifstream input, command;
    ofstream output;

    string inFileName = am.get("input");
    string outFileName = am.get("output");
    string cmdFileName = am.get("command");

    // string inFileName = "input22.txt";
    // string outFileName = "output22.txt";
    // string cmdFileName = "command22.txt";

    input.open(inFileName);
    output.open(outFileName);
    command.open(cmdFileName);

    Task t(input);
    LinkedList list = t.initialize();
    parseCommands(command, list);

    input.close();
    output.close();
    command.close();
    return 0;
}

void parseCommands(ifstream &file, LinkedList &list)
{
    string line;
    while (getline(file, line))
    {
        string command, arg1, arg2;
        int i = 0, j = 0;
        while (line.at(j) != ' ')
        {
            j++;
        }
        // at this point we have the actions
        command = line.substr(i, j);

        unordered_map<char, int> map;

        for (int k = 0; k < line.length(); k++)
        {
            if (line.at(k) == '(')
                map[line.at(k)] = k;
            if (line.at(k) == ')')
                map[line.at(k)] = k;
            if (line.at(k) == '[')
                map[line.at(k)] = k;
            if (line.at(k) == ']')
                map[line.at(k)] = k;
        }

        if (map['('] != 0)
        {
            int start = map['('];
            int end = map[')'];
            arg1 = line.substr(start + 1, end - start - 1);
        }
        if (map['['] != 0)
        {
            int start = map['['];
            int end = map[']'];
            arg2 = line.substr(start + 1, end - start - 1);
        }

        if (command == "Add")
        {
            list.addAtIdx(stoi(arg1), arg2);
        }
        else if (command == "Remove")
        {
            list.remove(arg2);
            // list.print();
        }
        else if (command == "Sort")
        {
            list.sort(arg1);
            // list.print();
        }
    }
}
