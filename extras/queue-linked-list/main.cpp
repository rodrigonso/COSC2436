#include <iostream>
#include "queuell.h"
using namespace std;

int main()
{

    queuell q;
    q.enqueu(1);
    q.enqueu(2);
    q.enqueu(3);
    q.enqueu(4);
    q.enqueu(5);

    q.print();
    cout << endl;

    q.dequeu();
    q.dequeu();

    q.print();

    return 0;
}