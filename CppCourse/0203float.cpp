#include <iostream>

using namespace std;

int main(){
    float f1 = 3.1415926;
    float f2 = 3.1415926f;
    double d1 = 3.1415926;

    cout << "f1 = " << f1 << endl;
    cout << "d1 = " << d1 << endl;

    cout << "float size " << sizeof(float) << endl;
    cout << "double size " << sizeof(double) << endl;


    //科学计数法

    float f3 = 3e2;
    float f4 = 3e-2;
    cout << " f3 = " << f3 << endl;
    cout << " f4 = " << f4 << endl;
    return 0;
}
