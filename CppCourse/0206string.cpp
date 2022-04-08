#include <iostream>
#include <string>//使用string数据类型必须要有的头文件
using namespace std;

int main(){
    //c语言风格
    char str[]= "Hello World";
    cout << "Hello world" << endl;
    cout << str << endl;

    //c++语言风格

    string str2 = "Hello";
    cout << str2 << endl;

    return 0;
}