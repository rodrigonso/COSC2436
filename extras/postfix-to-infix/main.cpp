#include <iostream>
#include <stack>
using namespace std;

string getInfix(string exp);
bool isOperand(char x);
int main()
{
    string test = "ab*c+";
    cout << getInfix(test) << endl;
    return 0;
}

bool isOperand(char x)
{
    return (x >= 'a' && x <= 'z') ||
           (x >= 'A' && x <= 'Z');
}

string getInfix(string exp)
{
    stack<string> s;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (isOperand(exp[i]))
        {
            string op(1, exp[i]);
            s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + exp[i] +
                   op1 + ")");
        }
    }

    return s.top();
}
