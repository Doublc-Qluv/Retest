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

// const

void printStudent(const student *stu)
{

    cout << "子函数中 姓名: " << stu->name
         << " 年龄: " << stu->age
         << " 分数: " << stu->score << endl;
}

int main()
{
    student stu = {"张三", 18, 100};

    printStudent(&stu);

    return 0;
}