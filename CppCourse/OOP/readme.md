[TOC]

面向对象的编程
------

# 1. 内存分区模型
C++程序在执行时, 将内存大方向划分为4个区域
1. 代码区: 存放函数体二进制代码,由操作系统进行管理
2. 全局区: 存放全局变量和静态变量以及常量
3. 栈区: 由编译器自动分配释放,存放函数参数值和局部变量等
4. 堆区: 由程序员分配和释放,若程序员不释放,程序结束时由操作系统回收

内存分四区意义:

不同区域存放的数据,赋予不同的生命周期,给编程更大的灵活性

## 1.1 程序运行前
windows中, 在程序编译后, 生成了exe可执行文件, 未执行该程序前分为两个区域

- 代码区:
  - 存放CPU执行的机器指令
  - 代码区是共享的: 共享的目的是对于频繁被执行的程序, 只需要在内存中有一份代码即可
  - 代码区是只读的, 使其制度的原因是防止程序意外修改它的指令
- 全局区:
  - 存放全局变量和静态变量
  - 全局区还包括了常量区, 字符串常量和其他常量也存放于此
  - 该区域数据在程序结束后由系统释放

[示例](./110100.cpp)
```c++
//全局变量
int g_a = 10;
int g_b = 10;
const int cg_c = 10;

int main()
{
    //局部变量
    int a = 10;
    int b = 10;

    //静态变量
    static int s_a = 10;
    static int s_b = 10;

    //常量
    const int c_c = 10;

    cout << "局部变量a的地址:\t\t" << (long)&a << endl;
    cout << "局部变量b的地址:\t\t" << (long)&b << endl;
    cout << "const修饰的局部变量的地址:\t" << (long)&c_c << endl;
    cout << endl;
    cout << "全局变量g_a的地址:\t\t" << (long)&g_a << endl;
    cout << "全局变量g_b的地址:\t\t" << (long)&g_b << endl;
    cout << "const修饰的全局变量cg_c的地址:\t" << (long)&cg_c << endl;
    cout << endl;
    cout << "静态变量s_a的地址:\t\t" << (long)&s_a << endl;
    cout << "静态变量s_b的地址:\t\t" << (long)&s_b << endl;
    cout << endl;
    cout << "字符串常量的的地址:\t\t" << (long)&"Hellow World" << endl;

    return 0;
}
```

## 1.2 程序运行后
- 栈区
  - 由编译器自动分配释放, 存放函数参数值, 局部变量等
  - 注:不要返回局部变量的地址栈区开辟的数据由编译器自动释放

[示例](./110200.cpp)

注:
- 堆区数据由程序员管理开辟和释放
- 堆区数据利用`new`关键字开辟内存

## 1.3 new 操作符
C++利用`new`关键字开辟内存

堆区数据由程序员手动开辟和释放, 利用释放操作符`delete`

语法: ```new 数据类型```

利用`new`创建的数据, 会返回该数据对应类型的指针

[示例1](./110200.cpp): delete
```c++
int *func(int b)
{
    b = 100;
    int a = 10;
    return &a;
}

int main()
{
    int *p = func(1);
    cout << *p << endl;
    delete p;
    cout << p << endl;//windows无法访问,linux直接为0?
    return 0;
}
```

[示例2](./110300.cpp): 开辟数组
```c++
int main()
{
    int *arr = new int[10];
    
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 100;
    }
    
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
    delete[] arr;

    return 0;
}
```

# 2. 引用

## 2.1 引用的基本使用

作用: 给变量起别名

做法 `数据类型 &别名 = 原名`

[示例](./120100.cpp)
```c++
int main()
{
    int a = 10;
    int &b = a;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    b = 100;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}
```

## 2.2 引用的注意事项
- 引用必须要初始化
- 引用在初始化之后不可改变

[示例](./120200.cpp)
```c++
int main()
{
    int a = 10;
    int b = 20;

    // int &c;//引用 变量需要初始值设定项
    int &c = a;
    cout << "a = " << a << endl; // 10
    cout << "b = " << b << endl; // 20
    cout << "c = " << c << endl; // 10
    c = b;                       //赋值,不更改引用
    cout << "a = " << a << endl; // 20
    cout << "b = " << b << endl; // 20
    cout << "c = " << c << endl; // 20
    return 0;
}
```

## 2.3 引用做函数参数
作用: 函数传递时, 可以利用引用让形参修饰实参
优点: 简化指针, 修改实参
总结: 通过引用参数产生的效果和按照地址传递的效果是一样的, 但是引用的语法更简单

[示例](./120300.cpp)
```c++
//值传递
void mySwap1(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

//地址传递
void mySwap2(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//引用传递
void mySwap3(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a = 10, b = 20;
    mySwap1(a, b); //值传递,形参不会修饰实参
    cout << "1a= " << a << ", 1b= " << b << endl;

    int c = 10, d = 20;
    mySwap2(&c, &d); //地址传递,形参会修饰实参
    cout << "2a= " << c << ", 2b= " << d << endl;

    int e = 10, f = 20;
    mySwap3(e, f); //地址传递,形参会修饰实参
    cout << "3a= " << c << ", 3b= " << d << endl;

    return 0;
}
```

## 2.4 引用作函数的返回
引用可以作为函数的返回值

注意: 不要引用局部变量

用法: 函数调用为左值

[示例](./120400.cpp)
```c++
//返回局部变量
// int& test01()
// {
//     int a = 10;
//     return a;
// }

//返回静态变量
int &test02()
{
    static int a = 20;
    return a;
}

int main()
{
    // 不能返回局部变量
    // int &ref = test01();
    int &ref2 = test02();
    // cout << "ref = " << ref << endl;
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    test02() = 1000;
    // 返回值是一个引用,函数调用可以作为左值,
    // 相当于做了一个a=1000的操作
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    return 0;
}
```

## 2.5 引用的本质

本质: 引用的本质在C++内部实现是一个指针常量

指针常量是常量, 指向不可修改, 指向的值可以修改

[示例](./120500.cpp)

```c++
void func(int &ref)
{
    ref = 100; // ref是引用,转换为*ref =100;
}

int main()
{
    int a = 10;
    int &ref = a; //会转换为 int* const ref = a;
    //指针常量是指针指向不可改, 也说明为什么引用不可修改
    ref = 20; //内部发现是引用自动帮我们转换为*ref=20;

    cout << "a: " << a << endl;
    cout << "ref: " << ref << endl;

    return 0;
}
```

## 2.6 常量引用

作用: 常量引用主要用来修饰形参, 防止误操作

在函数形参列表中, 加入const修饰形参,防止形参改变实参

[示例](./120600.cpp)
```c++

// 引用的使用场景, 通常来修饰形参
void showValue(const int &v)
{
    // v += 10;
    cout << v << endl;
}
int main()
{
    // int& ref =10;// 非常量引用的初始值必须为左值
    //引用本身需要一个合法空间, 因此错误

    // 加入const,编译器优化代码
    // int tmp = 10;const int& ref = tmp;
    const int &ref = 10;

    // ref = 100; //表达式必须是可修改的左值
    cout << ref << endl;

    // 函数中利用常量引用防止误操作修改实参
    int a = 10;
    showValue(a);

    cout << "a: " << a << endl;

    return 0;
}
```

# 3. 函数提高

## 3.1 函数的默认参数

在C++中, 函数的形参列表是可以有默认值的

语法`返回值类型 函数名 (参数=默认值){}`

[示例](./130100.cpp)
```c++
int func(int a, int b = 10, int c = 100)
{
    return a + b + c;
}

// 1. 如果某个位置参数有默认值, 那么从这个位置之后的参数都得有默认值
// 2. 如果函数声明有默认值, 函数实现时不能有默认值
int func2(int a = 10, int b = 10);
int func2(int a, int b)
{
    return a + b;
}

int main()
{
    cout << "ret = " << func(20, 20) << endl; // a=20,b=20,c=100
    cout << "ret = " << func2(100) << endl;   // a=100,b=10

    return 0;
}
```
## 3.2 函数占位参数

C++中函数的形参列表里可以有占位参数, 用来占位, 调用函数时必须要填补该位置

语法`返回值类型 函数名 (数据类型){}`

[返回](#32-函数占位参数)

[示例](./130200.cpp)
```c++
void func(int a, int)
{
    cout << "this is func" << endl;
}

int main()
{
    func(10, 10);
    return 0;
}
```
## 3.3 函数重载

### 3.3.1 概述
函数名可以相同,以提高复用性

函数重载条件:
- 同一作用域下
- 函数名称相同
- 函数参数类型不同,个数不同,顺序不同

但是: 函数返回值不可以作为函数重载的条件

[示例](./130301.cpp)

```c++
void func()
{
    cout << "func调用" << endl;
}
void func(int a)
{
    cout << "func调用 int a" << endl;
}
void func(double a)
{
    cout << "func调用 double a" << endl;
}
void func(double a, int b)
{
    cout << "func调用 double int" << endl;
}
void func(int b, double a)
{
    cout << "func调用 int double" << endl;
}

// int func()//无法重载仅按返回类型区分的函数
// {
//     cout << "func调用" << endl;
// }

int main()
{
    func();
    func(10);
    func(3.14);
    func(3.14, 10);
    func(10, 3.14);
    return 0;
}
```

### 3.3.2 函数重载的注意事项

- 引用作为重载条件
- 函数重载碰到函数默认参数

[引用示例](./130302.cpp)
```c++
// 引用作为重载条件
void func(int &a)
{
    cout << "func(int &a)的调用" << endl;
}
void func(const int &a)
{
    cout << "func(const int &a)的调用" << endl;
}

int main()
{
    int a = 10;
    func(a);

    const int b = 20;
    func(b);
    //上两行可以合并为
    func(20);

    return 0;
}
```
[默认参数示例](./130302.cpp)
```c++
// 函数重载碰到函数默认参数
void func2(int a, int b = 10)
{
    cout << "func2(int a,int b)的调用" << endl;
}
void func2(int a)
{
    cout << "func2(int a)的调用" << endl;
}

int main()
{


    //遇到 默认值, 会碰到二义性, 建议不加
    func2(10,20);
    return 0;
}
```


# 4. 类和对象
C++ 面向对象的三大特性
1. 封装
2. 继承
3. 多态

C++认为万事万物皆为对象, 对象上有其属性和行为

例如:
- 人作为对象，属性有姓名、年龄、身高、体重……，行为有走、跑、跳、吃饭唱歌……
- 车作为对象，属性有轮胎、方向盘、车灯……，行为有载人、放音乐、放空调……
- 具有相同性质的`对象`，我们可以抽象为`类`，人属于人类，车属于车类

## 4.1 封装
### 4.1.1 封装的意义

- 将属性和行为作为一个整体, 表现生活中的事物
- 将属性和行为加以权限限制

通过类创建对象的过程,称作`实例化`

**意义1**

在设计类时候, 属性和行为写在一起, 表现事物

**语法**: `class 类名{访问权限: 属性/行为}`

[示例1](./140101.cpp): 设计一个圆类, 求圆的周长
```c++
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
```

[示例2](./140102.cpp): 设计一个学生类, 可以显示并添加学生姓名和学号

```c++

class Student
{ //类中的属性和行为 统一称为成员
public:
    // 成员属性,成员变量
    string m_Name;
    int m_Id;
    void showStudent()
    {
        cout << "姓名: " << m_Name 
             << " 学号: " << m_Id << endl;
    }
public:
    // 成员函数,成员方法
    // 姓名输入
    void setName(string name)
    {
        m_Name = name;
    }
    // 学号输入
    void setId(int id)
    {
        m_Id = id;
    }
};

int main()
{
    Student stu; // 实例化对象

    // 使用直接赋值的方式
    stu.m_Name = "张三";
    stu.m_Id = 01;
    stu.showStudent();

    // 使用方法进行赋值
    stu.setName("李四");
    stu.setId(02);
    stu.showStudent();

    return 0;
}
```

**意义2**

类在设计时,可以把属性和行为放在不同的权限下,加以控制

访问权限有三种:

1. 公共权限  `public`     类内可以访问, 类外可以访问
2. 保护权限  `protected`  类内可以访问, 类外不可以访问, 子类可以访问
3. 私有权限  `private`    类内可以访问, 类外不可以访问, 子类不能访问


```c++
class Person
{
private:
    int m_Password;

public:
    string m_Name;

protected:
    string m_Car;

public:
    void func()// 函数体 属于类内
    {
        m_Name = "张三";
        m_Car = "拖拉机";
        m_Password = 123456;

        cout << m_Name << " " << m_Car << " " << m_Password << endl;
    }
};

int main()
{
    Person p1;
    p1.m_Name="李四";
    // p1.m_Car="奔驰";// 类外不可访问
    // p1.m_Password =123;// 类外不可访问
    p1.func();
    return 0;
}
```

### 4.1.2 struct 和 class
- struct 默认权限为公共
- class默认权限是私有权限

```c++
struct S
{
    int m_A;
};

class C
{
    int m_A;
};

int main()
{
    S s1;
    C c1;
    s1.m_A = 1;
    // c1.m_A = 2;// class里成员默认为私有类privae

    return 0;

}
```

### 4.1.3 成员属性设置为私有

优点1: 将所有成员设置为私有, 可以自己控制读写权限

优点2: 对于写权限, 我们可以检测数据的有效性

[示例](./140105.cpp)
```c++
class Person
{
private:
    string m_Name;
    int m_Age;
    string m_Lover;

public:
    //姓名可读可写
    void setName(string name)
    {
        m_Name = name;
    }
    string getName()
    {
        return m_Name;
    }

    //获取年龄 可读写 想修改范围0~150
    int getAge()
    {
        return m_Age;
    }
    void setAge(int age)
    {
        if (age < 0 || age > 150)
        {
            m_Age = 0;
            cout << "年龄错误! " << endl;
            return;
        }
        m_Age = age;
    }

    //爱人只写
    void setLover(string love)
    {
        m_Lover = love;
    }
};

int main()
{
    Person p;
    p.setName("张三");

    cout << "姓名: " << p.getName() << endl;
    p.setAge(11);
    cout << "年龄" << p.getAge() << endl;
    return 0;
}
```

### 4.1.4 案例:设计立方体类

设计立方体类(Cube)

求出立方体的面积和体积

分别用全局函数和成员函数判断两个立方体是否相等

[设计案例](./140106.cpp)

```c++
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
```

### 4.1.5 案例:点与圆的位置关系

设计一个圆类(Circle),和一个点类(Point),计算点与圆的位置关系

$$
\sqrt{(x_1 -x_2)^2 + (y_1 - y_2)^2} 与 m_R 比较
$$

编程中使用${(x_1 -x_2)^2 + (y_1 - y_2)^2} 与 {m_R}^2 比较$

$$
当{(x_1 -x_2)^2 + (y_1 - y_2)^2} == {m_R}^2 :  点在圆上
$$
$$
当{(x_1 -x_2)^2 + (y_1 - y_2)^2} > {m_R}^2 :点在圆外
$$
$$
当{(x_1 -x_2)^2 + (y_1 - y_2)^2} < {m_R}^2 :点在圆内
$$


[示例](./140207.cpp)
```c++
// 点类
class Point
{
private:
    int m_X;
    int m_Y;

public:
    void setX(int x)
    {
        m_X = x;
    }
    int getX()
    {
        return m_X;
    }
    void setY(int y)
    {
        m_Y = y;
    }
    int getY()
    {
        return m_Y;
    }
};

// 圆类
class Circle
{
private:
    int m_R;
    Point m_Center;

public:
    void setR(int r)
    {
        m_R = r;
    }
    int getR()
    {
        return m_R;
    }

    void setCenter(Point center)
    {
        m_Center = center;
    }
    Point getCenter()
    {
        return m_Center;
    }
};

void isInCircle(Circle &c, Point p)
{
    // 两点距离的平方
    int distance2 =
        (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
        (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
    // 半径的平方
    int rDistance2 = c.getR() * c.getR();

    // 判断关系
    if (distance2 == rDistance2)
    {
        cout << "点在圆上" << endl;
    }
    else if (distance2 > rDistance2)
    {
        cout << "点在圆外" << endl;
    }
    else
    {
        cout << "点在圆内" << endl;
    }
}

int main()
{
    // 创建圆
    Circle c;
    c.setR(10);
    Point center;
    center.setX(10);
    center.setY(0);
    c.setCenter(center);

    // 创建点
    Point p;
    p.setX(10);
    p.setY(10);

    // 比较
    isInCircle(c, p);
    return 0;
}
```

## 4.2 对象初始化和清理

- C++中的面向对象来源于生活, 每个对象也都会有初始设置以及对象销毁前的清理数据的设置

### 4.2.1 构造函数和析构函数

对象的**初始化**和**清理**也是两个非常重要的安全问题
1. 一个对象或者变量没有初始状态, 对其使用后果是未知
2. 同样的, 在使用完一个对象或者变量, 没有及时清理, 也会造成一定的安全问题

C++利用了**构造函数**和**析构函数**解决上述问题, 这两个函数会被编译器自动调用, 完成对象初始化和清理工作, 对象的初始化和清理工作是编译器强制我们要做的事情, 因此如果**我们不提供构造和析构, 编译器会提供的构造函数和析构函数是空实现**

- 构造函数: 主要是作用在于创建对象时为对象的成员属性赋值, 构造函数由编译器自动调用, 无需手动调用
- 析构函数: 主要作用在于对象**销毁前**系统自动调用, 执行一些清理工作

- **构造函数语法**: `类名(){}`
  1. 构造函数, 没有返回值也不写void
  2. 函数名和类名相同
  3. 构造函数可以有参数, 因此可以发生重载
  4. 程序在调用对象时候会自动调用构造, 无需手动调用, 而且只会调用一次

- **析构函数语法**: `~类名(){}`
  1. 析构函数, 没有返回值也不写void
  2. 函数名称与类名相同, 在名称前加上符号 `~`
  3. 析构函数不可以有参数, 因此不可以发生重载
  4. 程序在对象销毁前会自动调用析构, 无需手动调用, 而且只会调用一次

[示例](./140202.cpp)
```C++
class Person
{
private:
    /* data */
public:
    Person(/* args */);
    ~Person();
};

Person::Person(/* args */)
{
    cout<<"构造函数的调用"<<endl;
}

Person::~Person()
{
    cout<<"析构函数的调用"<<endl;
}

void test01(){ 
    Person p;//数据在栈上, 执行完毕后,再做释放
}

int main(){
    // test01();
    Person p; // 数据在栈上, 执行完毕后,再做释放, 
              // 但是注意此时需要整个main函数执行完毕才会释放
    return 0;
}
```

### 4.2.2 构造函数的分类及调用

两种分类的方式:
- 按参数分类: 有参构造和无参构造
- 按类型分类: 普通构造和拷贝构造

三种调用方式
- 括号法
- 显示法
- 隐式转换法

注意事项:
- 默认构造不用括号,否则会认为函数声明
- 注意不要用拷贝构造函数来初始化匿名对象 `Person(p3);`会认为是对象声明, 系统会报重定义
- 
```C++
#include <iostream>

using namespace std;

class Person
{
private:
public:
    int age;

    Person(/* args */);
    Person(int a);
    Person(const Person &p);

    ~Person();
};

// 构造函数
Person::Person() // 无参构造,默认构造
{
    cout << "构造函数的调用" << endl;
}
Person::Person(int a) // 有参构造
{
    age = a;
    cout << "构造函数的调用, 参数" << endl;
}

// 拷贝构造,要求不改变原始的方法
Person::Person(const Person &p)
{
    age = p.age;
    cout << "构造函数的调用, 拷贝" << endl;
}

Person::~Person()
{
    cout << "析构函数的调用" << endl;
}

// 调用
void test01()
{
    // 括号法
    Person p1; // 注意: 默认构造不用括号,否则会认为函数声明
    Person p2(10);
    Person p3(p2);

    cout << "p2: " << p2.age << endl;
    cout << "p3: " << p3.age << endl
         << endl;

    //显示法

    Person a1;
    Person a2 = Person(10);
    Person a3 = Person(a2);
    Person(20); //匿名对象,当前执行结束后 系统会立即回收对象
    cout<<"测试匿名对象,紧跟在析构函数之后"<<endl;

    // 注意不要用拷贝构造函数来初始化匿名对象
    // Person(p3);会认为是对象声明, 系统会报冲定义

    // 隐式转化法
    Person p4 = 10;// 有参构造
    Person p5 = p4;// 拷贝构造

}

int main()
{
    test01();

    return 0;
}
```

### 4.2.3 拷贝函数调用的时机

C++拷贝构造函数调用的时机通常有三种情况
- 使用一个已经创建完毕的对象来初始化一个新对象
- 值传递的方式给函数参数传值
- 以值方式返回局部对象

[示例](./140204.cpp)
```C++
#include <iostream>

using namespace std;

class Person
{
private:
    /* data */
public:
    int m_Age;
    Person(/* args */);
    Person(int age);
    Person(const Person &p);
    ~Person();
};

Person::Person(/* args */)
{
    cout << "默认构造函数调用" << endl;
}
Person::Person(int age)
{
    m_Age = age;
    cout << "有参构造函数调用" << endl;
}
Person::Person(const Person &p)
{
    cout << "拷贝构造函数调用" << endl;
    m_Age = p.m_Age;
}

Person::~Person()
{
    cout << "析构函数调用" << endl;
}

// 使用已经创建好的对象来初始化一个新对象
void test01()
{
    Person p1(20);
    Person p2(p1);
    cout << "p2: " << p2.m_Age << endl;
}

// 值传递的方式给函数参数传值
void doWork(Person p)
{
    p.m_Age = 1000;
    cout << "拷贝的p.Age" << p.m_Age << endl;
}
void test02()
{
    Person p(10);
    doWork(p); //利用拷贝构造函数进行值传递
    cout << "方法的的p.Age" << p.m_Age << endl;
}
// 值方式返回局部对象
Person doWork2()
{
    Person p1;
    cout << &p1 << endl;
    return p1;
}
void test03()
{
    Person p = doWork2();
    cout << &p << endl;
}
int main()
{
    // test01();
    // test02();
    test03();

    return 0;
}
```