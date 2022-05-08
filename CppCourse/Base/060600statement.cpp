#include <iostream>

using namespace std;

//先声明,需要在声明之后的任意位置定义函数
int max(int a, int b);

//在主函数前定义可以不用声明
int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int a = 2, b = 4;
    int c = 5, d = 1;

    cout << "max(a,b) = " << max(a, b) << endl;
    cout << "min(c,d) = " << min(c, d) << endl;

    return 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}