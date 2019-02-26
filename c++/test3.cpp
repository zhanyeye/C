#include <iostream>
#include <algorithm>
using namespace std;
int G[20][20];
bool vis[20];
int n, ans = 0x3f3f3f;

void dfs(int u, int cnt, int sum) {
    if (sum > ans) { //最优性剪枝
        return;
    }
    if (cnt == n - 1) {
        ans = min(ans, sum + G[u][0]);
    }
    vis[u] = true; //
    for (int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, cnt + 1, sum + G[u][i]);
        }
    }
    vis[u] = false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }
    dfs(0, 0, 0);
    cout << ans;
    return 0;
}