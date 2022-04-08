/*描述
    读入两个不超过25位的火星正整数A和B，计算A+B。
    需要注意的是：在火星上，整数不是单一进制的，第n位的进制就是第n个素数。
    例如：地球上的10进制数2，在火星上记为“1,0”，因为火星个位数是2进制的；
    地球上的10进制数38，在火星上记为“1,1,1,0”，因为火星个位数是2进制的，十位数是3进制的，百位数是5进制的，千位数是7进制的……
输入描述：
    测试输入包含若干测试用例，每个测试用例占一行，包含两个火星正整数A和B，火星整数的相邻两位数用逗号分隔，A和B之间有一个空格间隔。
输出描述：对每个测试用例输出1行，即火星表示法的A+B的值。*/



#include <iostream>
#include <string>
#include <vector>

using namespace std;

int odd[] = { 2,3,5,7,11,13,17,19 };
vector<int> vec;

int substring2int(string x, int from, int to)
{
	int ans = 0;
	for (int i = from; i < to; i++)
	{
		ans = ans * 10 + (x[i] - '0');
	}
	return ans;
}

void string2int(string x)
{
	vec.clear();
	int from = 0;
	for (int i = 0; i < x.length(); i++)
	{
		if (x[i] == ',')
		{
			vec.push_back(substring2int(x, from, i));
			from = i + 1;
		}
		else if (i == x.length() - 1)
			vec.push_back(substring2int(x, from, i+1));
	}
}

int mar2int(string x)
{
	int ans = 0, j = 0;
	string2int(x);
	for (int i = 0; i < vec.size(); i++)
	{
		ans = ans * odd[vec.size() - 1 - i] + vec[i];
	}
	return ans;
}

void int2mar(int x)
{
	string ans;
	int i = 0;
	while (x)
	{
		ans.push_back('0' + x % odd[i]);
		x /= odd[i];
		i++;
	}
	for (int i = ans.length() - 1; i >= 0; i--)
	{
		if (i == ans.length() - 1)
			printf("%d", ans[i] - '0');
		else
			printf(",%d", ans[i] - '0');
	}
}

int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		vec.clear();
		if (a == "0" || b == "0")
			break;
		int e_a = mar2int(a);
		int e_b = mar2int(b);
		int2mar(e_a + e_b);
	}
	return 0;
}