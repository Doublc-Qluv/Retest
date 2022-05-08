#include <iostream>
#include <string>

using namespace std;

//学生
struct student
{
    string name;
    int age;
    int score;
};

//老师
struct teacher
{
    int id;
    string name;
    int age;
    struct student stu;
};

int main()
{
    struct teacher t1;
    t1.id = 10000;
    t1.name = "老王";
    t1.age = 40;

    t1.stu.name = "张三";
    t1.stu.age = 18;
    t1.stu.score = 100;

    cout << "教师 职工编号: " << t1.id
         << " 姓名: " << t1.name
         << " 年龄: " << t1.age << endl;
    cout << "学生 姓名: " << t1.stu.name
         << " 年龄: " << t1.stu.age
         << " 分数: " << t1.stu.score << endl;
    return 0;
}