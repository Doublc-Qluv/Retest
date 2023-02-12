#include <iostream>
using namespace std;

int main()
{
    int sum = 0, t[200] = {0};
    for (int i = 0; i <= 5; i++)
    {
        for (int j = 0; j <= 4; j++)
        {
            for (int k = 0; k <= 6; k++)
            {
                t[8 * i + 10 * j + 18 * k]++;
            }
        }
    }
    for (int i = 0; i < 200; i++)
    {
        if (t[i])
            sum++;
    }
    cout << sum - 1 << endl;
    return 0;
}