/*
描述
输入一个字符串，长度小于等于200，然后将输出按字符顺序升序排序后的字符串。
输入描述：
测试数据有多组，输入字符串。
输出描述：
对于每组输入,输出处理后的结果。
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string strin;

    while(cin >> strin){
        sort(strin.begin(),strin.end());
        cout << strin <<endl;
    }


    return 0;
}