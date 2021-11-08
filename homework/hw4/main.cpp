#include <iostream>
#include <fstream>
#include "pq.h"
#include "ArgumentManager.h"

using namespace std;

void swap(string &str, char a, char b);
void replace(string &str, char a, char b);
void add(string &str, char a, char b);
void remove(string &str, char c);
void parseInput(ifstream &file, vector<command> &data);
int main(int argc, char *argv[])
{

    ArgumentManager am(argc, argv);
    ifstream input;
    ofstream output;

    string inputf = am.get("input");
    string outputf = am.get("output");

    input.open(inputf);
    output.open(outputf);

    PQ pq;
    queue<string> q;
    vector<command> data;

    parseInput(input, data);

    for (int i = 0; i < data.size(); i++)
    {
        pq.push(data[i]);
    }

    while (!pq.empty())
    {
        command curr = pq.top();
        string title = curr.getTitle();
        pq.pop();

        if (title == "DECODE")
        {
            q.push(curr.getMessage());
        }
        else if (!q.empty())
        {
            string currStr = q.front();
            if (title == "REPLACE")
            {
                replace(currStr, curr.getArg1(), curr.getArg2());
            }
            else if (title == "SWAP")
            {
                swap(currStr, curr.getArg1(), curr.getArg2());
            }
            else if (title == "REMOVE")
            {
                remove(currStr, curr.getArg1());
            }
            else if (title == "ADD")
            {
                add(currStr, curr.getArg1(), curr.getArg2());
            }
            else if (title == "PRINT")
            {
                cout << currStr << endl;
                output << currStr << endl;
                q.pop();
                continue;
            }
            q.pop();
            q.push(currStr);
        }
    }
}

void parseInput(ifstream &file, vector<command> &data)
{
    string line;
    while (getline(file, line))
    {
        command c(line);
        data.push_back(c);
    }
}

void swap(string &str, char a, char b)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == a)
            str[i] = b;
        else if (str[i] == b)
            str[i] = a;
    }
}

void replace(string &str, char a, char b)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == a)
            str[i] = b;
    }
}

void remove(string &str, char c)
{
    str.erase(remove(str.begin(), str.end(), c), str.end());
}

void add(string &str, char a, char b)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == a)
            str.insert(i + 1, string(1, b));
    }
}
