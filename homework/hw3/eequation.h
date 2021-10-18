#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class eequation
{
private:
    string data;
    string type;
    string removeSpaces(string str);
    void toPostfix();
    void toPrefix();
    int getPriority(char ch);
    bool isOperand(char ch);
    bool isOperator(char ch);

public:
    eequation()
    {
        data = "";
        type = "";
    }
    eequation(string t, string d);
    void convert();
    string toString();
    string getType() { return type; }
    string getExpression() { return data; }
};

string eequation::removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

eequation::eequation(string t, string d)
{
    data = removeSpaces(d);
    type = removeSpaces(t);
}

void eequation::convert()
{
    if (type == "prefix")
    {
        toPostfix();
        type = "postfix";
    }
    else
    {
        toPrefix();
        type = "prefix";
    }
}

string eequation::toString()
{
    return type + ":" + data;
}

int eequation::getPriority(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    else
        return 3;
}

void eequation::toPostfix()
{
    stack<string> s;
    for (int i = data.size() - 1; i >= 0; i--)
    {
        if (isOperator(data[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            string temp = op1 + op2 + data[i];

            s.push(temp);
        }

        else
        {

            s.push(string(1, data[i]));
        }
    }

    data = s.top();
}

bool eequation::isOperand(char x)
{
    return (x >= 'a' && x <= 'z') ||
           (x >= 'A' && x <= 'Z');
}

bool eequation::isOperator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

void eequation::toPrefix()
{
    {
        stack<string> s;
        for (int i = 0; i < data.length(); i++)
        {
            if (isOperand(data[i]))
            {
                string op(1, data[i]);
                s.push(op);
            }
            else
            {
                string op1 = s.top();
                s.pop();
                string op2 = s.top();
                s.pop();
                s.push(data[i] + op2 + op1);
            }
        }
        data = s.top();
    }
}
