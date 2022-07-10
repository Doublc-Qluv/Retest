#include <iostream>

using namespace std;

class Person
{
private:
    /* data */
public:
    Person(/* args */);
    Person(int age);
    // Person(const Person &p);
    ~Person();

public:
    int m_Age;
};
Person::Person(/* args */)
{
    cout << "Person 默认构造函数调用" << endl;
}
Person::Person(int age)
{
    cout << "Person 有参构造函数调用" << endl;
    m_Age = age;
}
// Person::Person(const Person &p)
// {
//     cout << "Person 拷贝构造函数调用" << endl;
//     m_Age = p.m_Age;
// }

Person::~Person()
{
    cout << "Person 默认析构函数调用" << endl;
}

// void test01()
// {
//     Person p;
//     p.m_Age = 18;
//     Person p2(p);
//     cout << "p2 的年龄是" << p2.m_Age << endl;
//     // 如果用户定义有参构造函数, C++不再提供默认无参构造, 但是会提供默认拷贝构造
// }
void test02(){
    Person p(29);
    Person p2(p);
    cout << "p2 的年龄是" << p2.m_Age << endl;
}
int main()
{
    // test01();
    test02();
    return 0;
}