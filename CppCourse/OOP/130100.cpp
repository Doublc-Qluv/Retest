#include <iostream>

using namespace std;

int func(int a, int b = 10, int c = 100)
{
    return a + b + c;
}

// 1. 如果某个位置参数有默认值, 那么从这个位置之后的参数都得有默认值
// 2. 如果函数声明有默认值, 函数实现时不能有默认值
int func2(int a = 10, int b = 10);
int func2(int a, int b)
{
    return a + b;
}

int main()
{
    cout << "ret = " << func(20, 20) << endl; // a=20,b=20,c=100
    cout << "ret = " << func2(100) << endl;   // a=100,b=10

    return 0;
}