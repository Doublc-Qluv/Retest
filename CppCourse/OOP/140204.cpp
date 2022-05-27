#include <iostream>

using namespace std;

class Person
{
private:
    /* data */
public:
    int m_Age;
    Person(/* args */);
    Person(int age);
    Person(const Person &p);
    ~Person();
};

Person::Person(/* args */)
{
    cout << "默认构造函数调用" << endl;
}
Person::Person(int age)
{
    m_Age = age;
    cout << "有参构造函数调用" << endl;
}
Person::Person(const Person &p)
{
    cout << "拷贝构造函数调用" << endl;
    m_Age = p.m_Age;
}

Person::~Person()
{
    cout << "析构函数调用" << endl;
}

// 使用已经创建好的对象来初始化一个新对象
void test01()
{
    Person p1(20);
    Person p2(p1);
    cout << "p2: " << p2.m_Age << endl;
}

// 值传递的方式给函数参数传值
void doWork(Person p)
{
    p.m_Age = 1000;
    cout << "拷贝的p.Age" << p.m_Age << endl;
}
void test02()
{
    Person p(10);
    doWork(p); //利用拷贝构造函数进行值传递
    cout << "方法的的p.Age" << p.m_Age << endl;
}
// 值方式返回局部对象
Person doWork2()
{
    Person p1;
    cout << &p1 << endl;
    return p1;
}
void test03()
{
    Person p = doWork2();
    cout << &p << endl;
}
int main()
{
    // test01();
    // test02();
    test03();

    return 0;
}