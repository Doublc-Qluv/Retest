#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    int *p = arr;

    cout << "数组访问第一个元素" << arr[0] << endl;
    cout << "指针访问第一个元素" << *p << endl;

    //指针遍历数组

    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        cout << *p << " ";
        p++;
    }
    return 0;
}