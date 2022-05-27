#include <iostream>

using namespace std;

// 引用的使用场景, 通常来修饰形参
void showValue(const int &v)
{
    // v += 10;
    cout << v << endl;
}
int main()
{
    // int& ref =10;// 非常量引用的初始值必须为左值
    //引用本身需要一个合法空间, 因此错误

    // 加入const,编译器优化代码
    // int tmp = 10;const int& ref = tmp;
    const int &ref = 10;

    // ref = 100; //表达式必须是可修改的左值
    cout << ref << endl;

    // 函数中利用常量引用防止误操作修改实参
    int a = 10;
    showValue(a);

    cout << "a: " << a << endl;

    return 0;
}