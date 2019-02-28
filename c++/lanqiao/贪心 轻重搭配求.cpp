#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;

int a[505][505];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Node {
    int x, y;
};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        queue<Node> q;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &a[i][j]);
                if (a[i][j] > 0 && (i == 1 || i == n || j == 1 || j == m)) {
                    q.push()
                }
            }
        }      
    }
}