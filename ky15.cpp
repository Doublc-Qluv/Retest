//设a、b、c均是0到9之间的数字，abc、bcc是两个三位数，且有：abc+bcc=532。求满足条件的所有a、b、c的值。
#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    for(a=0;a<10;a++){
        for(b=0;b<10;b++){
            for(c=0;c<10;c++){
                int sum =100*a +10*b +c +100*b + 11*c;
                if(sum==532){printf("%d %d %d",a,b,c);}

            }
        }
    }
    return 0;

}