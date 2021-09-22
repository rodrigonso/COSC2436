#include <iostream>
#include <fstream>
#include <sstream>
#include "linked_list.h"

using namespace std;

LinkedList parseInput(ifstream &file);
void writeOutput(ofstream &file, LinkedList &list);

int main(int argc, char const *argv[])
{

    // ArgumentManager am(argc, argv);
    ifstream input;
    ofstream output;

    // string inFileName = am.get("input");
    // string outFileName = am.get("output");
    string inFileName = "input1.txt";
    string outFileName = "output2.txt";

    input.open(inFileName);
    output.open(outFileName);

    try
    {
        LinkedList list = parseInput(input);
        list.print();
        list.sort();
        list.print();
        writeOutput(output, list);
    }
    catch (invalid_argument ex)
    {
        output << ex.what() << endl;
    }

    input.close();
    output.close();

    return 0;
}

LinkedList parseInput(ifstream &file)
{
    LinkedList res;
    string line;
    bool isValid = false;
    while (getline(file, line))
    {

        int commaCount = count(line.begin(), line.end(), ',');
        if (commaCount != 1)
        {
            cout << "Line did not have correct format... skipping" << endl;
            continue;
        }

        stringstream stringStream(line);
        string name, score;
        getline(stringStream, name, ',');
        getline(stringStream, score, ',');

        res.add(name, stoi(score));
        isValid = true;
    }

    if (!isValid)
    {
        throw invalid_argument("No valid data in input");
    }

    return res;
}

void writeOutput(ofstream &file, LinkedList &list)
{
    Node *curr = list.getHead();
    while (curr != 0)
    {
        file << curr->name << "," << curr->score << endl;
        curr = curr->next;
    }
}