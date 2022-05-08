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

    struct student arr[3] =
        {
            {"张三", 18, 100},
            {"李四", 17, 80},
            {"王五", 18, 90}};

    arr[2].name = "赵六";
    arr[2].age = 80;
    arr[2].score = 60;

    for (int i = 0; i < 3; i++)
    {
        cout << "姓名: " << arr[i].name 
             << " 年龄: " << arr[i].age 
             << " 分数: " << arr[i].score << endl;
    }
}