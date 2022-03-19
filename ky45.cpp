/*
描述
在 skew binary 表示中，第 k 位的值 x[k] 表示 x[k]×(2^(k+1)-1)。每个位上的可能数字是 0 或 1，
最后面一个非零位可以是 2，
例如，10120(skew) = 1×(2^5-1) + 0×(2^4-1) + 1×(2^3-1) + 2×(2^2-1) + 0×(2^1-1) 
= 31 + 0 + 7 + 6 + 0 = 44。前十个 skew 数是 0、1、2、10、11、12、20、100、101、以及 102。
输入描述：
输入包括多组数据，每组数据包含一个 skew 数。
输出描述：
对应每一组数据，输出相应的十进制形式。结果不超过 2^31-1。
*/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>

using namespace std;

long int skew(string num) 
{
    long int ans=0;
    long int n=num.size();
    for(int i=0; i<n; i++) 
    {
        if(num[i]!='0') 
        {
            ans+=(num[i]-'0')*(pow(2,n-i)-1);
        } 
        else 
        {
            continue;
        }
    }
    return ans;
}

int main()
{
    freopen("./ky45.data","r",stdin);
    string str;
    while(cin>>str)
    {
        cout<<skew(str)<<endl;
    }
    return 0;
}