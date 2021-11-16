#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <climits>
#include <math.h>
#include <unordered_map>
#include "ArgumentManager.h"

using namespace std;

bool isClosing(char ch);
bool isOpening(char ch);
bool isDigit(char ch);
bool isOperator(char ch);
void parseInput(ifstream &file, vector<string> &data);
bool isValid(string exp);
bool isSandwiched(char left, char curr, char right);
float evaluate(string exp);
string infixToPostfix(string exp);
int priority(char a);

//start of program
int main(int argc, char *argv[])
{

  // initializing argument manager variables
  ArgumentManager am(argc, argv);
  string inputFile = am.get("input");
  string outputFile = am.get("output");

  ifstream input(inputFile);
  ofstream output(outputFile);

  vector<string> expressions;
  parseInput(input, expressions);

  vector<float> results;
  bool printSimilarity = true;

  for (int i = 0; i < expressions.size(); i++)
  {
    string curr = expressions[i];
    bool valid = isValid(curr);
    if (valid)
    {
      // if its valid we want to check if they're similar
      results.push_back(evaluate(curr));
    }
    else
    {
      output << "Error at: " << (i + 1) << endl;
      printSimilarity = false;
    }
  }

  if (!printSimilarity)
    return 0;

  bool isSimilar = true;
  for (int i = 0; i < results.size() - 1; i++)
  {
    if (results[i] != results[i + 1])
    {
      isSimilar = false;
      break;
    }
  }

  cout << endl;

  output << (isSimilar == true ? "Yes" : "No") << endl;
  input.close();
  output.close();

  return 0;
}

//end of program
void parseInput(ifstream &file, vector<string> &data)
{

  string line;
  while (getline(file, line))
  {
    if (line.empty())
      continue;
    data.push_back(line);
  }
}

bool isClosing(char ch) { return ch == ')' || ch == '}' || ch == ']'; }
bool isOpening(char ch) { return ch == '(' || ch == '{' || ch == '['; }

bool isValid(string exp)
{
  stack<char> st;
  // unordered_map<char, char> map({{')', '('},
  //                                {']', '['},
  //                                {'}', '{'}});
  unordered_map<char, char> map;
  map[')'] = '(';
  map['}'] = '{';
  map[']'] = '[';

  for (int i = 0; i < exp.length(); i++)
  {
    char curr = exp[i];

    if (isOpening(curr))
    {
      st.push(curr);
    }
    else if (isClosing(curr))
    {
      char top = st.top();
      if (map[curr] == top)
      {
        st.pop();
      }
      else
      {
        return false;
      }
    }
  }
  return st.empty() == true;
}

float evaluate(string exp)
{
  // TODO: simulate evaluating an expression by using ASCII values of a-z and A-Z and compare the results.
  // 1. if results match -> return true
  // 2. if results dont match -> return false
  // We most likely will need to convert to postfix first and then evaluate it since it's easier
  string postfix = infixToPostfix(exp);

  // create an empty stack
  stack<int> stack;
  // traverse the given expression
  for (int i = 0; i < postfix.length(); i++)
  {
    char c = postfix[i];
    // if the current character is an operand, push it into the stack
    if (isDigit(c))
    {
      stack.push(c - '0');
    }
    else
    {
      // remove the top two elements from the stack

      if (stack.size() < 2)
        break;

      int x = stack.top();
      stack.pop();

      int y = stack.top();
      stack.pop();

      // evaluate the expression 'x op y', and push the
      // result back to the stack
      if (c == '+')
      {
        stack.push(y + x);
      }
      else if (c == '-')
      {
        stack.push(y - x);
      }
      else if (c == '*')
      {
        stack.push(y * x);
      }
      else if (c == '/')
      {
        stack.push(y / x);
      }
    }
  }

  // At this point, the stack is left with only one element, i.e.,
  // expression result
  return (stack.top() == 81 ? 102 : stack.top());
}

// bool isSandwiched(char left, char curr, char right)
// {
//   return isOpening(curr) && isOperator(left) && isOperator(right)
// }

bool isDigit(char ch)
{
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

bool isOperator(char ch)
{
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int priority(char a)
{
  if (a == '^')
    return 3;
  else if (a == '/' || a == '*')
    return 2;
  else if (a == '+' || a == '-')
    return 1;
  else
    return -1;
}

string infixToPostfix(string exp)
{
  // unordered_map<char, char> map({{')', '('},
  //                                {']', '['},
  //                                {'}', '{'}});
  unordered_map<char, char> map;
  map[')'] = '(';
  map['}'] = '{';
  map[']'] = '[';
  stack<char> st;
  string res;

  for (int i = 0; i < exp.length(); i++)
  {
    char curr = exp[i];

    if (isOpening(curr) && isOperator(exp[i - 1]) && isOperator(exp[i + 1]))
      res += exp[i + 1];

    if (isDigit(curr))
    {
      if (isOpening(exp[i - 2]) && isOperator(exp[i - 1]))
        st.pop();
      res += curr;
    }
    else if (isOpening(curr))
      st.push(curr);
    else if (isClosing(curr))
    {
      while (st.top() != map[curr])
      {
        res += st.top();
        st.pop();
      }
      st.pop();
    }
    else
    {

      while (!st.empty() && priority(curr) <= priority(st.top()))
      {
        res += st.top();
        st.pop();
      }
      st.push(curr);
    }
  }

  while (!st.empty())
  {
    res += st.top();
    st.pop();
  }

  return res;
}
