#include <iostream>
#include <string>

using namespace std;

class Cube
{
private:
    //  属性
    int m_L;
    int m_W;
    int m_H;

public:
    // 行为
    // 获取长宽高
    void setL(int sl)
    {
        m_L = sl;
    }
    int getL()
    {
        return m_L;
    }

    void setW(int sw)
    {
        m_W = sw;
    }
    int getW()
    {
        return m_W;
    }

    void setH(int sh)
    {
        m_H = sh;
    }
    int getH()
    {
        return m_H;
    }

    // 快速设置
    void setSize(int sl, int sw, int sh)
    {
        m_L = sl;
        m_W = sw;
        m_H = sh;
    }
    int getSize()
    {
        return m_L, m_W, m_H;
    }

    // 获得立方体面积
    int calcS()
    {
        return 2 * m_L * m_W + 2 * m_L * m_H + 2 * m_W * m_H;
    }
    // 获得立方体体积
    int calcV()
    {
        return m_L * m_W * m_H;
    }
};

//全局函数, 判断特定角度三条边对应相等
bool lookSame(Cube &c1, Cube &c2)
{
    if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
    {
        return true;
    }
    return false;
}

int main()
{
    Cube C1;
    C1.setSize(10, 20, 30);
    cout << "立方体1面积: " << C1.calcS() << endl;
    cout << "立方体1体积: " << C1.calcV() << endl;

    Cube C2;
    C2.setSize(20, 30, 10);

    bool ret = lookSame(C1, C2);
    
    ret==true?cout<<"C1C2相等"<<endl:cout<<"C1C2不等"<<endl;

    return 0;
}