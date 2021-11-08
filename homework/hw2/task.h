#include <iostream>
#include <fstream>
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

    LinkedList initialize()
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

    void execute()
    {
    }
};
