#include <iostream>
using namespace std;

class equation
{
private:
    string data;
    string type;
    string removeSpaces(string str);

public:
    equation()
    {
        data = "";
        type = "";
    }
    equation(string t, string d);
    void convert();
    string toString();
};

string equation::removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

equation::equation(string t, string d)
{
    data = removeSpaces(d);
    type = removeSpaces(t);
}

void equation::convert()
{
    if (type == "prefix")
    {
        // TODO convert to postfix
        type = "postfix";
    }
    if (type == "postfix")
    {
        // TODO convert to prefix
        type = "prefix";
    }
}

string equation::toString()
{
    return "Type: " + type + " | Data: " + data;
}
