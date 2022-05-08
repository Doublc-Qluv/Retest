#include <iostream>

using namespace std;

int main()
{
    // 1

    int score[10];
    score[0] = 100;
    score[1] = 95;
    score[2] = 90;

    cout << score[0] << endl;
    cout << score[1] << endl;
    cout << score[2] << endl;

    // 2

    int score2[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
    for (int i = 0; i < 10; i++)
    {
        cout << score2[i] << " ";
    }
    cout <<endl;

    //3

    int score3[] = {100, 90, 80, 70, 60, 50, 40, 30, 20};
    for (int i = 0; i < 10; i++)
    {
        cout << score3[i] << " ";//不在数组定义里的值会随机赋值
    }

    return 0;
}