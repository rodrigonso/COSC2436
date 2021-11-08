#include <iostream>
#include "queuea.h"
using namespace std;

int main()
{
    queuea q;

    q.enqeue(1);
    q.enqeue(2);
    q.enqeue(3);
    q.enqeue(4);
    q.enqeue(5);
    q.print();

    cout << endl;

    q.deqeue();
    q.deqeue();

    q.print();

    return 0;
}