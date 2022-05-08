#include "main.h"

void showMenu() //菜单
{
    string stars(28, '*');
    cout << stars << endl;
    cout << "****\t1、添加联系人\t****" << endl;
    cout << "****\t2、显示联系人\t****" << endl;
    cout << "****\t3、删除联系人\t****" << endl;
    cout << "****\t4、查找联系人\t****" << endl;
    cout << "****\t5、修改联系人\t****" << endl;
    cout << "****\t6、清空联系人\t****" << endl;
    cout << "****\t0、退出通讯录\t****" << endl;
    cout << stars << endl;
    cout << "请选择: ";
}
void inputSex(AddressBooks *abs, int num)
{
    int sex;
    while (1)
    {
        cout << "请输入性别(1:男 / 2:女): ";
        cin >> sex;
        if (cin.fail())
        {
            cout << endl
                 << "输入非数字" << endl;
            cin.clear();
            cin.ignore();
        }
        else
        {
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            else
            {
                cout << endl
                     << "输入错误,请重新输入" << endl;
            }
        }
    }
}
void addPerson(AddressBooks *abs) //添加联系人
{
    if (abs->m_Size == MAX)
    {
        cout << "通讯录已满,无法添加!" << endl;
        return;
    }
    else
    {
        //姓名
        string name;
        cout << "请输入姓名: ";
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;
        cout << endl;

        //性别
        inputSex(abs, abs->m_Size);

        //年龄
        cout << "请输入年龄: ";
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        //联系电话
        cout << "请输入联系电话: ";
        string phone = " ";
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        //家庭住址
        cout << "请输入家庭住址: ";
        string addr = " ";
        cin >> addr;
        abs->personArray[abs->m_Size].m_Addr = addr;

        cout << endl
             << "添加成功" << endl;
        abs->m_Size++;
    }
}

void showPerson(AddressBooks *abs)
{
    if (abs->m_Size == 0)
    {
        cout << "当前记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "姓名: " << abs->personArray[i].m_Name << "\t"
                 << "性别: " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t"
                 << "年龄: " << abs->personArray[i].m_Age << "\t"
                 << "电话: " << abs->personArray[i].m_Phone << "\t"
                 << "联系地址: " << abs->personArray[i].m_Addr << endl;
        }
    }
}

int isExist(AddressBooks *abs, string name) //检测是否存在? i : -1
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;
}

void deletePerson(AddressBooks *abs)
{
    cout << "输入想要删除的联系人: ";
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1)
    {
        for (int i = ret; i < abs->m_Size; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
}

void findPerson(AddressBooks *abs)
{
    cout << "输入想要查询的联系人: ";
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "姓名: " << abs->personArray[ret].m_Name << "\t"
             << "性别: " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t"
             << "年龄: " << abs->personArray[ret].m_Age << "\t"
             << "电话: " << abs->personArray[ret].m_Phone << "\t"
             << "联系地址: " << abs->personArray[ret].m_Addr << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
}

void modifyPerson(AddressBooks *abs)
{
    cout << "请输入要修改的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        //
        string name;
        cout << "请输入姓名: ";
        cin >> name;
        abs->personArray[ret].m_Name = name;

        cout << endl;
        inputSex(abs, ret);

        cout << endl;
        int phone;
        cout << "请输电话: ";
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        cout << endl;
        string address;
        cout << "请输入地址: ";
        cin >> address;
        abs->personArray[ret].m_Addr = address;

        cout << endl
             << "修改成功!";
    }
    else
    {
        cout << "查无此人!";
    }
}

void cleanPerson(AddressBooks *abs)
{
    abs->m_Size = 0;
    cout << "通讯录已清空" << endl;
}

int main()
{
    AddressBooks abs;
    abs.m_Size = 0; //初始化
    int select = 0;
    while (true)
    {

        showMenu();
        cin >> select;
        switch (select)
        {
        case 1:
            addPerson(&abs); // add
            break;
        case 2:
            showPerson(&abs); // show
            break;
        case 3:
            deletePerson(&abs); // delete
            break;
        case 4:
            findPerson(&abs); // detail
            break;
        case 5:
            modifyPerson(&abs); // change
            break;
        case 6:
            cleanPerson(&abs); // clean
            break;
        case 0:
            cout << "欢迎下次使用" << endl;
            return 0;
        default:
            break;
        }
    }

    return 0;
}