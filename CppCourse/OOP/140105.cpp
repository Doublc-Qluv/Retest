#include <iostream>
#include <string>
#include <cassert>

using namespace std;
class Person
{
private:
    string m_Name;
    int m_Age;
    string m_Lover;

public:
    //姓名可读可写
    void setName(string name)
    {
        m_Name = name;
    }
    string getName()
    {
        return m_Name;
    }

    //获取年龄 可读写 想修改范围0~150
    int getAge()
    {
        return m_Age;
    }
    void setAge(int age)
    {
        if (age < 0 || age > 150)
        {
            m_Age = 0;
            cout << "年龄错误! " << endl;
            return;
        }
        m_Age = age;
    }

    //爱人只写
    void setLover(string love)
    {
        m_Lover = love;
    }
};

int main()
{
    Person p;
    p.setName("张三");

    cout << "姓名: " << p.getName() << endl;
    p.setAge(11);
    cout << "年龄" << p.getAge() << endl;
    return 0;
}