#include <iostream>
using namespace std;

struct S
{
    int m_A;
};

class C
{
    int m_A;
};

int main()
{
    S s1;
    C c1;
    s1.m_A = 1;
    // c1.m_A = 2;// class里成员默认为私有类privae

    return 0;

}