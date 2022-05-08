#include <iostream>

using namespace std;

int main()
{
    int a = 10; //整型数a

    int *p;
    p = &a; //指向变量a的地址
    cout << "&a = " << &a << endl;
    cout << "p = " << p << endl;

    cout << "*p = " << *p << endl;//指向变量

    return 0;

}