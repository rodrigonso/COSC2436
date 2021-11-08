#include <iostream>
#include <fstream>
#include "ArgumentManager.h"
#include "doublyll.h"
#include <stack>
using namespace std;

void parseInput(ifstream &file, doublyll &res);
void parseCommands(ifstream &file, ofstream &output, doublyll &list, rstack &stack);
int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);
    ifstream input, command;
    ofstream output;

    string inputFile = am.get("input");
    string commandFile = am.get("command");
    string outputFile = am.get("output");

    doublyll list;
    rstack stack;

    input.open(inputFile);
    command.open(commandFile);
    output.open(outputFile);
    parseInput(input, list);
    parseCommands(command, output, list, stack);
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
        eequation eq(type, val);

        res.insert(eq);
    }
}

void parseCommands(ifstream &file, ofstream &output, doublyll &list, rstack &stack)
{
    string line;
    while (getline(file, line))
    {
        stringstream st(line);
        string method, args;
        getline(st, method, ' ');
        getline(st, args, ' ');
        if (!args.empty())
            args = args.substr(1, args.size() - 2);

        bool isNumber = args != "postfix" && args != "prefix" && args != "all";
        if (method == "convertList")
        {
            list.convertList((isNumber ? "position" : args), isNumber ? stoi(args) : -1);
        }
        else if (method == "printList")
        {
            list.printList(output, 1);
        }
        else if (method == "printListBackwards")
        {
            list.printList(output, -1);
        }
        else if (method == "pushReserve")
        {
            vector<eequation *> res = list.find(args);
            cout << res.size() << endl;
            for (int i = 0; i < res.size(); i++)
            {
                eequation curr = *(res.at(i));
                stack.push(curr);
                list.remove(curr, isNumber ? stoi(args) : -1);
            }
        }
        else if (method == "popReserve")
        {
            eequation top = stack.top();
            stack.pop();
            list.insert(top, isNumber ? stoi(args) : -1);
        }
        else if (method == "flipReserve")
        {
            stack.print();
            cout << endl;
            stack.reverse();
            stack.print();
            cout << endl;
        }
        else if (method == "printReserveSize")
            stack.printSize(output);
        else if (method == "convertReserve")
        {
            eequation eq = stack.top();
            eq.convert();
            stack.pop();
            stack.push(eq);
        }
        else if (method == "printReserveTop")
            stack.printTop(output);
        else if (method == "emptyReserve")
        {
            eequation curr;
            while (!stack.isEmpty())
            {
                curr = stack.top();
                stack.pop();
                list.insert(curr, isNumber ? stoi(args) : -1);
            }
        }
    }
}