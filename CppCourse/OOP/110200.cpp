#include <iostream>

using namespace std;

int *func(int b)
{
    b = 100;
    int a = 10;
    return &a;
}

int main()
{
    int *p = func(1);
    cout << *p << endl;
    delete p;
    cout << p << endl;//windows无法访问,linux直接为0?
    return 0;
}