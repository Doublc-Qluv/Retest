#include <iostream>
using namespace std;

int nofac(int n, int m) {
    int sum = 0, tmp = 1;
    for (int i = n - m + 1; i <= n; i++) {
        tmp = tmp * i;
        while (tmp % 2 == 0) {
            tmp /= 2;
            sum++;
        }
    }
    return sum;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        if(n*m==0) return 0;
        cout << nofac(n, m) << endl;
    }
    return 0;
}