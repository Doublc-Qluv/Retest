#include <iostream>
using namespace std;
#define MAX 1000
int main() {
    char a[MAX];
    int i=0;
    if ("./j2.data" != NULL){
        freopen("./j2.data", "r", stdin);
    }
    for(int i=0;i<MAX;i++){
        cin.get(a[i]);
    }
    // cout <<a<<endl;
    for(int i=0;i<MAX;i++){
        if(a[i]>='a'&&a[i]<='z'){
            a[i]=(a[i]-'a'+1)%26+'a'; 
        }
        if(a[i]>='A'&&a[i]<='Z'){
            a[i]=(a[i]-'A'+1)%26+'A'; 
        }   
    }
    cout <<a<<endl;
}
// 64 位输出请用 printf("%lld")