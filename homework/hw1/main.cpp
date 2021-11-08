#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "library.h"
#include "ArgumentManager.h"

using namespace std;

void parseInput(ifstream &file, Library &data);
string formatData(string str);
vector<Book> parseCommands(ifstream &file, Library &data);
int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);

    ifstream input, commands;
    ofstream output;

    string inFileName = am.get("input");
    string outFileName = am.get("output");
    string cmdFileName = am.get("command");

    Library lib;
    vector<Book> res;

    input.open(inFileName);
    output.open(outFileName);
    commands.open(cmdFileName);

    parseInput(input, lib);
    cout << endl;
    // lib.print();
    res = parseCommands(commands, lib);
    for (int i = 0; i < res.size(); i++)
    {
        Book curr = res.at(i);
        cout << '{' << "genre:" << curr.getGenre() << ',' << "title:" << curr.getTitle() << ',' << "author:" << curr.getAuthor() << ',' << "year:" << curr.getYear() << '}' << endl;
        output << '{' << "genre:" << curr.getGenre() << ',' << "title:" << curr.getTitle() << ',' << "author:" << curr.getAuthor() << ',' << "year:" << curr.getYear() << '}' << endl;
    }

    return 0;
}

string formatData(string str)
{
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

vector<Book> parseCommands(ifstream &file, Library &data)
{
    vector<Book> res = data.getData();
    // vector<Book> res;
    string line;
    while (getline(file, line))
    {
        string key, value;
        stringstream st(line);
        while (getline(st, key, ':'))
        {
            getline(st, value, ':');
        }

        // vector<Book> findings = data.find(key, value);
        // for (int i = 0; i < findings.size(); i++)
        // {
        //     res.push_back(findings.at(i));
        // }
        for (int i = 0; i < res.size(); i++)
        {
            Book curr = res.at(i);
            if (key == "genre")
            {
                if (curr.getGenre() != value)
                {
                    res.erase(res.begin() + i);
                }
            }
            else if (key == "year")
            {
                if (curr.getYear() != stoi(value))
                {
                    res.erase(res.begin() + i);
                }
            }
        }
    }

    return res.size() == 0 ? data.getData() : res;
}

void parseInput(ifstream &file, Library &data)
{
    string line;
    while (getline(file, line))
    {
        int count = 0;
        if (line.length() == 0)
            continue;
        cout << endl;
        Book b;
        string str = line.substr(1, line.size() - 2);
        string pairs;
        stringstream st(str);
        bool isValid = true;

        while (getline(st, pairs, ','))
        {
            stringstream st2(pairs);
            string key, value;
            while (getline(st2, key, ':'))
            {

                getline(st2, value, ':');
                key = formatData(key);
                cout << key << ':' << value << ',';
                value = formatData(value);

                if (key == "genre" && count == 0)
                    b.setGenre(value);
                else if (key == "title" && count == 1)
                    b.setTitle(value);
                else if (key == "author" && count == 2)
                    b.setAuthor(value);
                else if (key == "year" && count == 3)
                    b.setYear(stoi(value));
                else
                    isValid = false;
                count++;
            }
        }
        if (isValid)
            data.insert(b);
    }
    cout << endl;
}
