/*
描述
输入一个整数n，输出n的阶乘（每组测试用例可能包含多组数据，请注意处理）
输入描述：
一个整数n(1<=n<=20)
输出描述：
n的阶乘
*/

#include <iostream>
using namespace std;
int main(){
    int n;
    while(cin >> n){
        long ans=1;
        for(int i=1;i<=n;i++){
            ans=ans*i;
        }
        cout << ans;
    }
    return 0;
}