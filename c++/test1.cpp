#include <iostream>
#include <cmath>
using namespace std;


int factorial(int n) {
    int a[10000];
    int c, m = 0;
    a[0] = 1;
    for (int i = 1; i <= n; i++) {
        c = 0; //进位
        for (int j = 0; j <= m; j++) {
            a[j] = a[j] * i + c;
            c = a[j] / 10000;  //注意进位用除法 /
            a[j] = a[j] % 10000;  //注意余数用取模 %
        }
        if(c > 0) { //如果最高位还有进位
            m++;   
            a[m] = c;
        }
    }

    for (int i = m; i >= 0; i--) {
        cout << a[i];
    }
    cout << endl;

    return log10(a[m]) + 1 + 4 * m; //返回阶乘的位数
}

int main() {
    int n;
    cin >> n;
    
    cout << n << "的阶乘位数是" << factorial(n);
    return 0;
}