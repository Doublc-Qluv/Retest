// 比较三个数的大小,输出最大

#include <iostream>

using namespace std;

int main(){
    int a=0, b=0, c=0;
    cin >> a >> b >> c;
    cout << "a is " << a <<endl;
    cout << "b is " << b <<endl;
    cout << "c is " << c <<endl;
    int max=0;
    if(a>b){
        max=a;
        cout << "max is a" <<endl;
        if(max<c){
            max = c;
            cout << "max is c" <<endl;
        }
    }
    else{
        max = b;
        cout << "max is b" <<endl;
        if(max<c){
            max = c;
            cout << "max is c" <<endl;
        }
    }
    
    return 0;
}