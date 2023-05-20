#include <iostream>
using namespace std;
class Person
{
private:
    int m_A,m_B,m_C;
public:
    Person(int a, int b, int c);
    void PrintPerson(){
        cout<<"mA:"<<m_A<<endl;
        cout<<"mB:"<<m_B<<endl;
        cout<<"mC:"<<m_C<<endl;
    }
};

// //传统方式初始化
// Person::Person(int a, int b, int c)
// {
//     m_A = a;
//     m_B = b;
//     m_C = c;
// }


//初始化列表方式初始化
Person::Person(int a, int b, int c):m_A(a),m_B(b),m_C(c){}



int main(){
    Person p(1,2,3);
    p.PrintPerson();

    return 0;
}