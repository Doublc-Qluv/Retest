#include <iostream>
#include <string>
using namespace std;

class Student
{ //类中的属性和行为 统一称为成员
public:
    // 成员属性,成员变量
    string m_Name;
    int m_Id;
    void showStudent()
    {
        cout << "姓名: " << m_Name << " 学号: " << m_Id << endl;
    }
public:
    // 成员函数,成员方法
    // 姓名输入
    void setName(string name)
    {
        m_Name = name;
    }
    // 学号输入
    void setId(int id)
    {
        m_Id = id;
    }
};

int main()
{
    Student stu; // 实例化对象

    // 使用直接赋值的方式
    stu.m_Name = "张三";
    stu.m_Id = 01;
    stu.showStudent();

    // 使用方法进行赋值
    stu.setName("李四");
    stu.setId(02);
    stu.showStudent();

    return 0;
}