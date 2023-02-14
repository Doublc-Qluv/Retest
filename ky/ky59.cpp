/*
描述
有一个神奇的口袋，总的容积是40，用这个口袋可以变出一些物品，这些物品的总体积必须是40。John现在有n个想要得到的物品，
每个物品的体积分别是a1，a2……an。John可以从这些物品中选择一些，如果选出的物体的总体积是40，那么利用这个神奇的口袋，
John就可以得到这些物品。现在的问题是，John有多少种不同的选择物品的方式。
输入描述：
输入的第一行是正整数n (1 <= n <= 20)，表示不同的物品的数目。接下来的n行，每行有一个1到40之间的正整数，分别给出a1，a2……an的值。
输出描述：
输出不同的选择物品的方式的数目
*/

#include <iostream>

using namespace std;
int sum(int a[],int n, int s){
    if(s==0)return 1;
    if(n == 1){
        if(a[0]!=s)return 0;
        else return 1;
    }
    return(sum(a,n-1,s)+sum(a,n-1,s-a[n-1]));
}


int main() {
    int a[20];
    int n;
    if ("./ky59.data" != NULL)
    {
        freopen("./ky59.data", "r", stdin);
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<sum(a,n,40);
    return 0;
}
// 64 位输出请用 printf("%lld")