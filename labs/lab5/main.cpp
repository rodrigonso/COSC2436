#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "ArgumentManager.h"
using namespace std;

void findFrequency(vector<string> &data, map<string, int> &map);
void parseInput(ifstream &file, vector<string> &data);
int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);
    ifstream input;
    ofstream output;

    string inputName = am.get("input");
    string outputName = am.get("output");

    input.open(inputName);
    output.open(outputName);

    vector<string> data;
    map<string, int> freq;
    parseInput(input, data);
    findFrequency(data, freq);

    for (const auto it : freq)
    {
        cout << it.first << ": " << it.second << endl;
        output << it.first << ": " << it.second << endl;
    }
}

void parseInput(ifstream &file, vector<string> &data)
{
    string n;
    getline(file, n);

    string line;
    while (getline(file, line))
    {
        stringstream st(line);
        string str;
        while (getline(st, str, ' '))
            data.push_back(str);
    }
}

void findFrequency(vector<string> &data, map<string, int> &map)
{
    for (int i = 0; i < data.size(); i++)
    {
        string curr = data[i];
        if (!map[curr])
            map[curr] = 1;
        else
        {
            map[curr] = map[curr] + 1;
        }
    }
}
