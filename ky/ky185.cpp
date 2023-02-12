#include <iostream>

using namespace std;
#define MAX 9
/*
KY185
*/
int n;

void rot90(int m1[MAX][MAX], int n)
{
    // 顺时针旋转90并返回到m1中
    int m2[MAX][MAX];
    for (int i = 0; i < n; i++)
    { // rot90
        for (int j = 0; j < n; j++)
        {
            m2[i][j] = m1[n - j - 1][i];
        }
    }
    for (int i = 0; i < n; i++)
    { // m1=m2
        for (int j = 0; j < n; j++)
        {
            m1[i][j] = m2[i][j];
        }
    }
}

int jug(int m1[MAX][MAX], int m2[MAX][MAX], int n)
{
    // 判断矩阵相同
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (m1[i][j] != m2[i][j])
                return 0;
        }
    }
    return 1;
}
int main()
{
    int m1[MAX][MAX], m2[MAX][MAX];
    if ("./ky185.data" != NULL)
    {
        freopen("./ky185.data", "r", stdin);
    }
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m1[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m2[i][j];
            }
        }

        int tmp[MAX][MAX];
        for (int i = 0; i < n; i++)
        { // m1=m2
            for (int j = 0; j < n; j++)
            {
                tmp[i][j] = m1[i][j];
            }
        }

        int flag = -1;
        for (int i = 0; i < 4; i++)
        {
            int res = jug(m1, m2, n);
            if (res == 1)
            {
                flag = i;
                break;
            }
            rot90(m1, n);
        }
        if (flag == -1)
            cout << "-1" << endl;
        else
            cout << flag * 90 << endl;
    }
    return 0;
}
