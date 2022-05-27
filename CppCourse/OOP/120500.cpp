#include <iostream>

using namespace std;

void func(int &ref)
{
    ref = 100; // ref是引用,转换为*ref =100;
}

// 引用的使用场景, 通常来修饰形参
void showValue(const int& v){
    //v+=10;
    cout <<v<<endl;

}
int main()
{
    int a = 10;
    int &ref = a; //会转换为 int* const ref = a;
    //指针常量是指针指向不可改, 也说明为什么引用不可修改
    ref = 20; //内部发现是引用自动帮我们转换为*ref=20;

    cout << "a: " << a << endl;
    cout << "ref: " << ref << endl;

    return 0;
}