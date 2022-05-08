#include <iostream>
#include <string>
#include <random>

using namespace std;


//
struct Student
{
    string sName;
    int score;
};

//

struct Teacher
{
    string tName;
    struct Student sArr[5];
};

void toTeacher(struct Teacher tArr[], int len)
{
    string nameSeed = "ABCDE";
    int numSeed1[]={60,50,70,80,100};
    for (int i = 0; i < len; i++)
    {
        tArr[i].tName = "Teacher_";
        tArr[i].tName += nameSeed[i];
        for (int j = 0; j < 5; j++)
        {
            tArr[i].sArr[j].sName = "Student_";
            tArr[i].sArr[j].sName += nameSeed[j];
            tArr[i].sArr[j].score = numSeed1[random()%5];
        }
    }
}

void printInfo(struct Teacher tArr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "老师姓名: " << tArr[i].tName << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "学生姓名: " << tArr[i].sArr[j].sName
                 << " 分数: " << tArr[i].sArr[j].score << endl;
        }
        cout << endl;
    }
}

int main()
{
    struct Teacher tArr[3];
    int len = sizeof(tArr) / sizeof(tArr[0]);
    toTeacher(tArr, len);
    printInfo(tArr, len);
    return 0;
}