#include <iostream>
#include <string>

using namespace std;

#define MAX 1000

struct Person
{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
};

struct AddressBooks
{
    struct Person personArray[MAX];
    int m_Size;
};

