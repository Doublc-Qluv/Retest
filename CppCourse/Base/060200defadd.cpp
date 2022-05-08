#include <iostream>

using namespace std;

int add(int num1, int num2)
{
    return num1 + num2;
}

int main()
{
    int a = 3, b = 7;
    cout << add(a, b) << endl;
    return 0;
}