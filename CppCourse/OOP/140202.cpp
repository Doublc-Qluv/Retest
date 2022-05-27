#include <iostream>

using namespace std;

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