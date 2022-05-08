#include <iostream>
#include <string>

using namespace std;

struct student
{
    string name;
    int age;
    int score;
};

int main()
{
    struct student stu = {"张三", 18, 100};
    struct student *p = &stu;
    p->score = 80;

    cout << "姓名: " << p->name
         << " 年龄: " << p->age
         << " 分数: " << p->score << endl;
    return 0;
}