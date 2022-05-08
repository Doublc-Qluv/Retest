#include <iostream>

using namespace std;

//值传递
void swap1(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

//地址传递
void swap2(int *p1, int *p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int main()
{

    int a = 10, b = 20;

    swap1(a, b); //值的传递不改变实参

    cout << "1." << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    swap2(&a, &b); //地址传递会改变实参

    cout << "2." << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}