#include <iostream>

using namespace std;

//值传递
void mySwap1(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

//地址传递
void mySwap2(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//引用传递
void mySwap3(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a = 10, b = 20;
    mySwap1(a, b); //值传递,形参不会修饰实参
    cout << "1a= " << a << ", 1b= " << b << endl;

    int c = 10, d = 20;
    mySwap2(&c, &d); //地址传递,形参会修饰实参
    cout << "2a= " << c << ", 2b= " << d << endl;

    int e = 10, f = 20;
    mySwap3(e, f); //地址传递,形参会修饰实参
    cout << "3a= " << c << ", 3b= " << d << endl;

    return 0;
}