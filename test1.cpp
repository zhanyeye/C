#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void deletestr(char *s, char *t, char *u) {
    int cnt = 0;
    int i, j;
    for (i = 0; s[i] != '\0'; i++) {
        int flag = 0;
        for (j = 0; t[j] != '\0'; j++) {
            if (s[i] == t[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            u[cnt++] = s[i];
        }
    }
    u[cnt] = '\0';
}

int main() {
    int m=3,n=4,x;
    x=-m++;
    cout << x << endl;
    cout << m << endl;
    int y = -++m;
    cout << y;
    x=x+8/++n;
    printf("%d\n",x);
    
}