#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    int s1[n1], s2[n2];
    if ("./ky144.data" != NULL){
        freopen("./ky144.data", "r", stdin);
    }
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cin >> s1[i];
    }
    cin >> n2;
    for (int j = 0; j < n2; j++) {
        cin >> s2[j];
    }
    int n = (n1 + n2 + 1) / 2;
    int ans;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (s1[a] < s2[b]) {
            ans = s1[a];
            a++;
        } else {
            ans = s2[b];
            b++;
        }
    }
    cout << ans << endl;
    return 0;
}