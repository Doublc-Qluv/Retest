#include <iostream>

using namespace std;

const double PI = 3.14;

class Circle
{
    // 访问权限
    // 公共权限
public:
    // 属性
    // 半径
    int m_r;

    // 行为
    // 计算圆的周长
    double CalcCircumference()
    {
        return 2 * PI * m_r;
    }
};

int  main()
{
    // 创建具体的圆,即为对象
    // 通过类创建对象的过程,称作实例化
    Circle c1;
    // 给圆对象 的属性进行赋值
    c1.m_r = 10;

    cout << "圆的周长为: " << c1.CalcCircumference() << endl;
    return 0;
}