#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string fun(string str){
    int up,t;
    int d=10,b=2; 
    string res="";
    for(int i=0;i<str.size();){
        up=0;//进位
        for(int j=i;j<str.size();j++){
            t=(up*d+str[j]-'0')%b;
            str[j]=(up*d+str[j]-'0')/b+'0';
            up=t;
        }
        res+=char(up+'0');
        while(str[i]=='0')i++;
    }
    reverse(res.begin(),res.end());
    return res;
}
int main(){
    string dec;
    if ("./j4.data" != NULL){
        freopen("./j4.data", "r", stdin);
    }
    while(cin>>dec){
        // string bin=fun(dec);
        // for(int i=0;i<=bin.size();i++){
        //     cout<<bin[bin.size()-i];
        // }
        // // cout<<dec<<endl;
        cout<<fun(dec)<<endl;
    }
    
    return 0;
}