#include <iostream>

using namespace std;

class Person
{
private:
    /* data */
public:
    //无参(默认)构造函数
    Person();
    Person(int age, int height);
    Person(const Person &p);
    ~Person();
    int m_Age;
    int *m_Height;
};

Person::Person()
{
    cout << " 无参构造函数 " << endl;
}
Person::Person(int age, int height)
{
    m_Age = age;
    m_Height = new int(height);
    cout << " 有参构造函数" << endl;
}
Person::Person(const Person &p)
{
    cout << " 自建构造函数 " << endl;
    m_Age = p.m_Age;
    // m_Height=p.m_Height;
    m_Height = new int(*p.m_Height);
}
Person::~Person()
{
    if (m_Height != NULL)
    {
        delete m_Height;
        m_Height = NULL;
    } //会出错如下:释放两次内存
    // free(): double free detected in tcache 2
    // 此时要自己另写构造函数
    cout << " 析构函数" << endl;
}

void test01()
{
    Person p1(18, 160);
    cout << " p1 age is " << p1.m_Age << " height is " << *p1.m_Height << endl;
    Person p2(p1);
    cout << " p2 age is " << p2.m_Age << " height is " << *p2.m_Height << endl;
}

int main()
{
    test01();
    return 0;
}