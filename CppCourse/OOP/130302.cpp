#include <iostream>

using namespace std;
// 引用作为重载条件
void func(int &a)
{
    cout << "func(int &a)的调用" << endl;
}
void func(const int &a)
{
    cout << "func(const int &a)的调用" << endl;
}

// 函数重载碰到函数默认参数
void func2(int a, int b = 10)
{
    cout << "func2(int a,int b)的调用" << endl;
}
void func2(int a)
{
    cout << "func2(int a)的调用" << endl;
}

int main()
{
    //遇到 默认值, 会碰到二义性, 建议不加
    func2(10,20);
    return 0;
}
