#include <iostream>

using namespace std;
//全局变量
int g_a = 10;
int g_b = 10;
const int cg_c = 10;

int main()
{
    //局部变量
    int a = 10;
    int b = 10;

    //静态变量
    static int s_a = 10;
    static int s_b = 10;

    //常量
    const int c_c = 10;

    cout << "局部变量a的地址:\t\t" << (long)&a << endl;
    cout << "局部变量b的地址:\t\t" << (long)&b << endl;
    cout << "const修饰的局部变量的地址:\t" << (long)&c_c << endl;
    cout << endl;
    cout << "全局变量g_a的地址:\t\t" << (long)&g_a << endl;
    cout << "全局变量g_b的地址:\t\t" << (long)&g_b << endl;
    cout << "const修饰的全局变量cg_c的地址:\t" << (long)&cg_c << endl;
    cout << endl;
    cout << "静态变量s_a的地址:\t\t" << (long)&s_a << endl;
    cout << "静态变量s_b的地址:\t\t" << (long)&s_b << endl;
    cout << endl;
    cout << "字符串常量的的地址:\t\t" << (long)&"Hellow World" << endl;

    return 0;
}