#include <iostream>

using namespace std;

//
void test01()
{
    cout << "test01" << endl;
}

void test02(int a)
{
    cout << "test02" << endl;
    cout << "a= " << a << endl;
}

int test03()
{
    cout << "test03" << endl;
    return 10;
}

int test04(int a, int b)
{
    cout << "test04" << endl;
    int sum = a + b;
    return sum;
}

int main()
{
    test01();

    int a = 2;
    test02(a);

    cout << test03() << " is test3 result" << endl;

    int b = 3;
    cout << test04(a, b) << " is test4 result " << endl;

    return 0;
}