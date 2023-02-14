#include <iostream>
using namespace std;
#define N 100

int main(){
    int n;
    int p[N],q[N];
    if ("./j1.data" != NULL){
        freopen("./j1.data", "r", stdin);
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i]>>q[i];
    }
    int tmp;
    for(int j=0;j<n-1;j++){
        for(int i=0;i<n-j-1;i++){
            if(q[i]>q[i+1]){
                tmp=q[i];
                q[i]=q[i+1];
                q[i+1]=tmp;

                tmp=p[i];
                p[i]=p[i+1];
                p[i+1]=tmp;
            }
            if(q[i]==q[i+1] && p[i]>p[i+1]){
                tmp=p[i];
                p[i]=p[i+1];
                p[i+1]=tmp;
            }
        }
    }


    for(int i=0;i<n;i++){
        cout<<p[i]<<" "<<q[i]<<endl;
    }

}
