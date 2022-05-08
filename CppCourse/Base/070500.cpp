#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int b = 10;

    const int *p1 = &a;
    p1 = &b;
    //*p1 = 100;//报错

    int * const p2 = &a;
    //p2 = &b; //报错  
    *p2 = 100;

    const int * const p3 = &a;
    //*p3 = 100;//报错
    //p3 = &b; //报错  
}