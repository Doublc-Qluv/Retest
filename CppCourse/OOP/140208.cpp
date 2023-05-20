#include <iostream>
using namespace std;

class Phone
{
private:
    /* data */
public:
    string m_PhoneName;
    Phone(string name);
    ~Phone();
};

Phone::Phone(string name)
{
    m_PhoneName=name;
    cout <<"Phone 构造"<<endl;
}

Phone ::~Phone()
{
    cout <<"Phone 析构"<<endl;
}

class Person
{
private:
    /* data */
public:
    string m_Name;
    Phone m_Phone;
    Person(string name, string pName):m_Name(name),m_Phone(pName){
        cout <<"Person 构造"<<endl;
    }
    ~Person(){
        cout <<"Person 析构"<<endl;
    }
    void playGame(){
        cout <<m_Name<<" 使用 "<< m_Phone.m_PhoneName<<" 牌 手机。"<<endl;
    }
};


void test01(){
    Person p("张三","Apple");
    p.playGame();    
}

int main(){
    test01();
    return 0;
}
