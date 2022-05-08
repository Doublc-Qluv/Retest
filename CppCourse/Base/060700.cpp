#include "060700.h"

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;

    cout << "a = " << a;
    cout << "b = " << b;
}

int main()
{
    int a = 10, b = 20;
    swap(a, b);

    return 0;
}