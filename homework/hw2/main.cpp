#include <iostream>
#include <fstream>
#include "ArgumentManager.h"
#include "linked_list.h"

using namespace std;

class Task
{
private:
    int length;
    string operationType;
    string *data;
    string *res;

public:
    Task(ifstream &file)
    {
        int l = -1;
        string curr, prev = "";
        while (getline(file, curr))
        {
            if (curr == "" || curr == prev)
                continue;
            prev = curr;
            l++;
        }

        cout << "Number of lines: " << l << endl;
        length = l;

        file.clear();
        file.seekg(0);

        data = new string[length];

        getline(file, operationType);
        cout << "Operation: " << operationType << endl;

        int idx = 0;
        while (getline(file, curr))
        {
            if (curr == "" || curr == prev)
                continue;
            prev = curr;
            data[idx] = curr;
            idx++;
        }
    }

    LinkedList execute()
    {
        LinkedList list;
        for (int i = 0; i < length; i++)
        {
            string curr = data[i];
            if (operationType == "End")
            {
                list.addAtEnd(curr);
            }
            else
            {
                list.addAtBeg(curr);
            }
        }

        if (operationType == "Alphabetically")
            list.sort(operationType);
        else if (operationType == "Length")
            list.sort(operationType);

        return list;
    }
};

int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);
    ifstream input;
    ofstream output;

    // string inFileName = am.get("input");
    // string outFileName = am.get("output");
    // string cmdFileName = am.get("command");

    string inFileName = "input21.txt";
    string outFileName = "output21.txt";

    input.open(inFileName);
    output.open(outFileName);

    Task t(input);
    LinkedList list = t.execute();
    list.print();
    Node *curr = list.getHead();
    while (curr != 0)
    {
        output << curr->data << endl;
        curr = curr->next;
    }

    input.close();
    output.close();
    return 0;
}
