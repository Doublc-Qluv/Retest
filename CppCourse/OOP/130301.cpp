#include <iostream>

using namespace std;

void func()
{
    cout << "func调用" << endl;
}
void func(int a)
{
    cout << "func调用 int a" << endl;
}
void func(double a)
{
    cout << "func调用 double a" << endl;
}
void func(double a, int b)
{
    cout << "func调用 double int" << endl;
}
void func(int b, double a)
{
    cout << "func调用 int double" << endl;
}

// int func()//无法重载仅按返回类型区分的函数
// {
//     cout << "func调用" << endl;
// }

int main()
{
    func();
    func(10);
    func(3.14);
    func(3.14, 10);
    func(10, 3.14);
    return 0;
}