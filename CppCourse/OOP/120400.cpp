#include <iostream>
using namespace std;

//返回局部变量
// int& test01()
// {
//     int a = 10;
//     return a;
// }

//返回静态变量
int &test02()
{
    static int a = 20;
    return a;
}

int main()
{
    // 不能返回局部变量
    // int &ref = test01();
    int &ref2 = test02();
    // cout << "ref = " << ref << endl;
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    test02() = 1000;
    // 返回值是一个引用,函数调用可以作为左值,
    // 相当于做了一个a=1000的操作
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    return 0;
}