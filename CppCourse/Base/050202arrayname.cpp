#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    //统计空间大小

    cout << "size array: " << sizeof(arr) << endl;
    cout << "size element: " << sizeof(arr[0]) << endl;
    cout << "size number: " << sizeof(arr) / sizeof(arr[0]) << endl;

    //获得内存中的地址

    cout << "首地址: " << arr << endl;
    cout << "第一个元素地址" << &arr[0] << endl;
    cout << "第二个元素地址" << &arr[1] << endl;
    return 0;
}