#include <iostream>
using namespace std;

/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

5 => 0, 1, 1, 2, 3, 5 => F(5) = 5
6 => 0, 1, 1, 2, 3, 5, 8 => F(6) = 8

Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
*/

/*

F(n) = {
    if n = 0, F(n) = 0
    if n = 1, F(n) = 1
    else, F(n) = F(n - 1) + F(n - 2)
}

*/

int fib(int n, int data[]);
int main()
{
    int n = 9;
    int data[10];
    cout << fib(n, data) << endl;
    return 0;
}

int fib(int n, int *data)
{
    if (n <= 1)
    {
        return n;
    }

    if (data[n] != 0)
    {
        return data[n];
    }

    data[n] = fib(n - 1, data) + fib(n - 2, data);
    return data[n];
}

/*
give me fib(5)

                fib(5)
               /      \
           fib(3)     fib(4)
           /    \           \
        fib(1)  fib(2)      fib(2)
                /     \
              fib(0) fib(1)  

*/