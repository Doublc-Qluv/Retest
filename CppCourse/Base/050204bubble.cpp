#include <iostream>

using namespace std;

int main(){
    int arr[9]={4,2,8,0,5,7,1,3,9};
    for(int i=0;i<9-1;i++){//轮数
        for(int j=0;j<9-1-i;j++){
            if(arr[j]>arr[j+1]){//>从小到大,<从大到小
                int tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }

    for(int i=0;i<9;i++){
        cout << arr[i]<<" ";
    }
    return 0;
}