#include <iostream>
#include <string>
using namespace std;

int main(){
    // + - * / %

    int a1 = 2; int c1 = 0; c1 = ++a1;
    cout << "a1 = " << a1 << "; c1 = ++a1 = " << c1 << endl;

    int a2 = 2; int c2 = 0; c2 = a2++;
    cout << "a2 = " << a2 << "; c2 = a2++ = " << c2 << endl;

    int a3 = 2; int c3 = 0; c3 = --a3;
    cout << "a3 = " << a3 << "; c3 = --a3 = " << c3 << endl;

    int a4 = 2; int c4 = 0; c4 = a4--;
    cout << "a4 = " << a4 << "; c4 = a4-- = " << c4 << endl;

    
}