#include <iostream>

using namespace std;

int main()
{
    //打印数组中最大的数

    int arr[5] = {300, 350, 200, 400, 250};
    int max = 0;
    for (int i = 0; i < 5; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
        else
            continue;
    }
    cout << max << endl;
}