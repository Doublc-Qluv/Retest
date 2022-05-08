#include <iostream>

using namespace std;

int main(){//下三角乘法表
    for (int j = 1; j < 10; j++){
        for (int i = 1; i <= j; i++){
            cout << i << " * " << j << " = " << i * j << "\t";
        }
        cout << endl;
    }
    return 0;
}