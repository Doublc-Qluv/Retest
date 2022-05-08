#include <iostream>
#include <string>
using namespace std;

struct student
{
    string name;
    int age;
    int score;
} stu3;

int main()
{
    //方法一
    struct student stu1;

    stu1.name = "张三";
    stu1.age = 18;
    stu1.score = 100;

    cout << "姓名: " << stu1.name << endl;
    cout << " 年龄: " << stu1.age << endl;
    cout << " 分数: " << stu1.score << endl;

    cout << endl;

    //方法二

    struct student stu2 = {"李四", 19, 60};
    cout << "姓名: " << stu2.name << endl;
    cout << " 年龄: " << stu2.age << endl;
    cout << " 分数: " << stu2.score << endl;

    cout << endl;

    // 方法三

    stu3.name = "王五";
    stu3.age = 18;
    stu3.score = 80;

    cout << "姓名: " << stu3.name << endl;
    cout << " 年龄: " << stu3.age << endl;
    cout << " 分数: " << stu3.score << endl;

    cout << endl;

    return 0;
}