#include <iostream>
#include <fstream>
#include <vector>
#include "ArgumentManager.h"
using namespace std;

vector<string> parseInput(ifstream &file);
void findPermutations(string data, int idx, ofstream &output);
bool shouldSwap(string str, int start, int curr);
int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);
    ifstream input;
    ofstream output;

    string inFileName = am.get("input");
    string outFileName = am.get("output");

    input.open(inFileName);
    output.open(outFileName);

    vector<string> res;
    vector<string> data = parseInput(input);
    string curr;

    if (data.size() == 0)
    {
        output << "no permutation\n";
        return 0;
    }

    for (int i = 0; i < data.size(); i++)
    {
        findPermutations(data[i], 0, output);
    }

    return 0;
}

bool shouldSwap(string str, int start, int curr)
{
    for (int i = start; i < curr; i++)
        if (str[i] == str[curr])
            return 0;
    return 1;
}

void findPermutations(string data, int idx, ofstream &output)
{
    if (idx >= data.size())
    {
        output << data << endl;
        return;
    }

    for (int i = idx; i < data.size(); i++)
    {
        bool check = shouldSwap(data, idx, i);
        if (check)
        {
            char tmp = data[idx];
            data[idx] = data[i];
            data[i] = tmp;
            findPermutations(data, idx + 1, output);
            char tmp2 = data[idx];
            data[idx] = data[i];
            data[i] = tmp2;
        }
    }
}

vector<string> parseInput(ifstream &file)
{
    vector<string> res;
    string line;
    while (getline(file, line))
    {
        res.push_back(line);
    }
    return res;
}