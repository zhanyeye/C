#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int func(int n) {
    int a[10000];
    a[0] = 1;
    int m = 0;
    for (int i = 1; i <= n; i++) {
        int up = 0;
        for (int j = 0; j <= m; j++) {
            a[j] = a[j] * i + up;
            up = a[j] / 10000;
            a[j] = a[j] % 10000;
        }
        if (up > 0) {
            m++;
            a[m] = up;
        }
    }
    // for (int i = m; i >= 0; i--) {
    //     cout << a[i];
    // }
    // cout << endl;
    return 4 * m + log10(a[m]) + 1;
}


int main() {
    int n;
    cin >> n;
    int i;
    for (i = 1; i <= n; i++) {
        if(func(i) >= 10000) {
            cout << i;
            break;
        }
    }
    if (i == n + 1) {
        cout << "no found" << endl;
    }

    return 0;
}