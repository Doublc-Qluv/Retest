#include <iostream>
#include <string>

using namespace std;

// 1. 公共权限  `public`     类内可以访问, 类外可以访问
// 2. 保护权限  `protected`  类内可以访问, 类外不可以访问, 子类可以访问
// 3. 私有权限  `private`    类内可以访问, 类外不可以访问, 子类不能访问

class Person
{
private:
    int m_Password;

public:
    string m_Name;

protected:
    string m_Car;

public:
    void func()// 函数体 属于类内
    {
        m_Name = "张三";
        m_Car = "拖拉机";
        m_Password = 123456;

        cout << m_Name << " " << m_Car << " " << m_Password << endl;
    }
};

int main()
{
    Person p1;
    p1.m_Name="李四";
    // p1.m_Car="奔驰";// 类外不可访问
    // p1.m_Password =123;// 类外不可访问
    p1.func();
    return 0;
}
