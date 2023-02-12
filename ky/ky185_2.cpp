#include <iostream>
#define MAX 9
using namespace std;
/*
KY185_2
*/
int m1[MAX][MAX];
int m2[MAX][MAX];
int n;
int **to(int m1[MAX][MAX], int rot)
{

    int **m2 = new int *[MAX];
    for (int i = 0; i < n; i++)
    {
        m2[i] = new int[MAX];
    }

    if (rot == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                m2[j][n - i - 1] = m1[i][j];
            }
        }
    }
    else if (rot == 2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                m2[n - i - 1][n - j - 1] = m1[i][j];
            }
        }
    }
    else if (rot == 3)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                m2[n - j - 1][i] = m1[i][j];
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                m2[i][j] = m1[i][j];
            }
        }
    }
    return m2;
}

bool jug(int m1[MAX][MAX], int **m2)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (m2[i][j] != m1[i][j])
                return false;
        }
    }
    return true;
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

        bool flag = false, temp;
        for (int rot = 0; rot < 4; rot++)
        {
            temp = jug(m2, to(m1, rot));
            flag = flag || temp;
            if (temp == true)
            {
                cout << 90 * rot << endl;
                break;
            }
        }
        if (flag == false)
            cout << "-1" << endl;
    }
    return 0;
}
