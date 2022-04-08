#include <iostream>
#include <string>
using namespace std;

int main(){

    int a = 0;
    cout << "输入整型a" << endl;
    cin >> a;
    cout << a << endl;

    double d = 0;
    cout << "输入浮点d" << endl;
    cin >> d;
    cout << d << endl;

    char ch = 0;
    cout << "输入字符" << endl;
    cin >> ch;
    cout << ch << endl;

    string str = 0;
    cout << "输入字符串" << endl;
    cin >> str;
    cout << str << endl;

    bool flag = false;
    cout << "输入布尔值" << endl;
    cin >> flag;//非零的布尔型都相当于true或者说是相当于1
    cout << flag << endl;

    return 0;

}