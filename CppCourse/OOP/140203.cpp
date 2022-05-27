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
    // Person(p3);会认为是对象声明, 系统会报重定义

    // 隐式转化法
    Person p4 = 10;// 有参构造
    Person p5 = p4;// 拷贝构造

}

int main()
{
    test01();

    return 0;
}