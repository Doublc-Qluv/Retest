#include <iostream>

using namespace std;

int main()
{
    //逆置5个元素的数组

    int array[5] = {1, 3, 2, 5, 4};
    int res[5] = {};
    for (int i = 5; i > 0; i--)
    {
        res[5 - i] = array[i - 1];
    }
    for (int i = 0; i < 5; i++)
    {
        cout << res[i] << " ";
    }
}