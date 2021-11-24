#include <iostream>
#include <fstream>
#include <vector>
#include "ArgumentManager.h"
#include "avl.h"

using namespace std;

void parseInput(ifstream &file, vector<int> &data);
int main(int argc, char *argv[])
{
    ifstream input;
    ofstream output;

    ArgumentManager am(argc, argv);
    input.open(am.get("input"));
    output.open(am.get("output"));

    vector<int> data;
    parseInput(input, data);

    avl tree;
    node *root = nullptr;

    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << endl;
        root = tree.insert(root, data[i]);
    }

    tree.bfs(output, root);
    input.close();
    output.close();

    return 0;
}

void parseInput(ifstream &file, vector<int> &data)
{
    int count = 0;
    string line;
    while (getline(file, line))
    {
        if (count++ == 0)
            continue;
        data.push_back(stoi(line));
    }
}
