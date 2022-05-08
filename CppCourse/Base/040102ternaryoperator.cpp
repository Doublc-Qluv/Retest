// 比较三个数的大小,输出最大

#include <iostream>

using namespace std;

int main()
{
    int a = 20, b = 10, c = 0;

    c = a > b ? a : b;
    cout << "c = " << c << endl << endl;
    //三目运算符返回变量,可以被赋值

    (a > b ? a : b) = 100;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}