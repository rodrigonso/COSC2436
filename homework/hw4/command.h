#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class command
{
private:
    int priority;
    string title;
    char arg1;
    char arg2;
    string message;

public:
    command(string d);
    command();
    string toString() const { return title + ':' + to_string(priority); }
    int getPriority() const { return priority; }
    string getTitle() const { return title; }
    char getArg1() const { return arg1; }
    char getArg2() const { return arg2; }
    string getMessage() const { return message; }
    bool operator<(const command &c) const;
    bool operator>(const command &c) const;
};

command::command()
{
    priority = INT_MAX;
    title = "N/A";
    arg1 = ' ';
    arg2 = ' ';
    message = "N/A";
}

command::command(string d)
{
    string args, a1, a2;

    title = string(d.begin(), d.begin() + d.find(':'));

    if (title != "PRINT")
    {
        args = string((d.begin() + d.find('[') + 1), d.begin() + d.find(']'));
        int commaIdx = args.find(',');
        if (commaIdx != -1)
        {
            arg1 = string(args.begin(), args.begin() + commaIdx)[0];
            arg2 = args.substr(commaIdx + 1)[0];
        }
        else
        {
            if (title == "DECODE")
                message = args;
            else
                arg1 = args[0];
        }
    }

    priority = stoi(string((d.begin() + d.find('(') + 1), (d.begin() + d.find(')'))));
}

bool command::operator<(const command &c) const
{
    return priority < c.getPriority();
}

bool command::operator>(const command &c) const
{
    return priority > c.getPriority();
}
