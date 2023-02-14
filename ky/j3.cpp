#include <iostream>
#include <cmath>
using namespace std;
#define MAX 100

int main(){
    string str;
    if ("./j3.data" != NULL){
        freopen("./j3.data", "r", stdin);
    }
    while(cin>>str){
        int ans=0;
        int n=str.size();
        for(int i=0;i<n;i++){
            // cout<<"ans:"<<ans<<"   str[i]:"<<int(str[i])-'0'<<" * "<<pow(2,(n-i))-1<<endl;
            ans+=(pow(2,n-i)-1)*(int(str[i])-'0');
        }
        cout<<ans<<endl;
        // cout<<str.size()<<endl;
    }
    return 0;
}