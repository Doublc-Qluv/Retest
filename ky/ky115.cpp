/*
描述
对于一个字符串，将其后缀子串进行排序，
例如grain 其子串有： grain rain ain in n 
然后对各子串按字典顺序排序，即： ain,grain,in,n,rain

输入描述：
每个案例为一行字符串。

输出描述：
将子串排序输出
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    char s[105];
    cin >> s;
    int count = strlen(s);
    string t[count];
    for(int i=0; s[i]!='\0'; i++){
        for(int j=i; s[j]!='\0'; j++){
            t[i] += s[j];
        }
    }
    sort(t,t+count);
    for(int i=0; i<count; i++){
        cout << t[i] << endl;
    }
    return 0;
}