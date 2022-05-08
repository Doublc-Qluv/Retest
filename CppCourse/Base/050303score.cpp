#include <iostream>
#include <string>
using namespace std;

int main()
{
    int score[3][3] = {
        {100, 100, 100},
        {90, 50, 100},
        {60, 70, 80}};
    string name[] = {"张三", "李四", "王五"};
    for (int i = 0; i < 3; i++)
    {
        cout << name[i] << " 总分: " << score[i][0] + score[i][1] + score[i][2] << endl;
    }
    return 0;
}