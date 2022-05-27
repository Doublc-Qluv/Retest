#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int b = 20;

    // int &c;//引用 变量需要初始值设定项
    int &c = a;
    cout << "a = " << a << endl; // 10
    cout << "b = " << b << endl; // 20
    cout << "c = " << c << endl; // 10
    c = b;                       //赋值,不更改引用
    cout << "a = " << a << endl; // 20
    cout << "b = " << b << endl; // 20
    cout << "c = " << c << endl; // 20
    return 0;
}