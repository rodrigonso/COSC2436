#include <iostream>
#include <stack>
using namespace std;

int getPriority(char ch);
string infixToPostfix(string exp);
int main()
{
    string exp;
    cout << "Please enter expression: ";
    cin >> exp;
    cout << infixToPostfix(exp) << endl;
    return 0;
}

int getPriority(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    else
        return 3;
}

string infixToPostfix(string exp)
{
    string res;
    stack<char> stack;

    for (int i = 0; i < exp.length(); i++)
    {
        char curr = exp.at(i);
        if (isdigit(curr))
        {
            res += curr;
        }
        else
        {
            if (stack.empty())
            {
                stack.push(curr);
                continue;
            }

            while (!stack.empty() && getPriority(curr) <= getPriority(stack.top()))
            {
                res += stack.top();
                stack.pop();
            }

            stack.push(curr);
        }
    }

    while (!stack.empty())
    {
        res += stack.top();
        stack.pop();
    }

    return res;
}
