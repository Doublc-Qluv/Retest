#include <iostream>

using namespace std;

int main()
{
    int *p = NULL;

    cout << *p << endl; //不可以访问,会报错

    cout << endl;

    int *q = (int *)0x1100;

    cout << *q << endl;

    return 0;
}