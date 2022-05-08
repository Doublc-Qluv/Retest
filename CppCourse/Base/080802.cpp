#include <iostream>
#include <string>

using namespace std;

//学生
struct Member
{
    string name;
    int age;
    string sex;
};

int main()
{
    struct Member mem[5] = {
        {"刘备", 23, "男"},
        {"关羽", 22, "男"},
        {"张飞", 20, "男"},
        {"赵云", 21, "男"},
        {"貂蝉", 19, "女"},
    };

    for (int i = 0; i < 5; i++)
    {
        cout << mem[i].name << " " << mem[i].age << " " << mem[i].sex << endl;
    }
    cout << endl;
    for (int i = 0; i < 5 - 1; i++)
    {
        for (int j = 0; j < 5 - i - 1; j++)
        {
            if (mem[j].age > mem[j + 1].age)
            {
                struct Member tmp = mem[j];
                mem[j] = mem[j + 1];
                mem[j + 1] = tmp;
            }

            // if(i>j){
            //     int tmp=j;
            //     j=i;
            //     i=tmp;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << mem[i].name << " " << mem[i].age << " " << mem[i].sex << endl;
    }
    return 0;
}