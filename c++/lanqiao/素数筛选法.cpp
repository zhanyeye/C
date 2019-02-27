#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool p[1000005];

void is_prime(int n) {
    for (int i = 2; i <= n; i++) {
        p[i] = true;
    }
    for (int i = 2; i * i <= n; i++) {
        if (p[i]) {
            for (int j = i * i; j <= n; j += i) {  //这里直接忽略了小于i的倍数，因为之前肯定已经出现过了
                p[j] = false;  //注意这里是j,
            }
        } 
    }
}

int main() {
    int t, n;
    scanf("%d", &t);
    is_prime(1000000);   //调用函数也会消耗时间，这一题最好写在主函数里
    while (t--) {
        scanf ("%d", &n);
        for (int i = 2; i < n; i++) {
            if (p[i] && p[n - i]) {
                printf("%d %d\n", i, n - i);
                break;
            }
        }
    }
}