#include <cstring>
#include <iostream>
using namespace std;
//撇马腿的位置（从上开始顺时针方向）
int px[4] = {-1, 0, 1, 0};
int py[4] = {0, 1, 0, -1};
//与4个撇马腿方向对应的8步
int dx[4][2] = {{-2, -2}, {-1, 1}, {2, 2}, {1, -1}};
int dy[4][2] = {{-1, 1}, {2, 2}, {-1, 1}, {-2, -2}};

int g[5][5]; //标记改点是否有马
int vis[5][5]; //标记该点是否可被马控制
int n = 5, m =5;

bool in(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}


int main() {
    int r = n * m;
    int minx = r + r, ans = 0;
    for (int s = 0; s < 1 << r; s++) {//2进制枚举2^n*m次，共 n*m 位，将s转化为2进制，就是一种布局方式
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        for (int i = 0 ; i < r; i++)  {//将s布局方式转化为数组记录下来
             if (s >> i & 1) { //如果第i位是1
                 g[i / m][i % m] = 1;
                 cnt++;
             } else { //如果第i位是0
                 g[i / m][i % m] = 0;
             }
        }
        if (cnt > minx) continue;

        //检查方案是否满足要求
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 0) continue;
                vis[i][j] = 1;
                for (int k = 0; k < 4; k++) {
                    int x = i + px[k];
                    int y = j + py[k];
                    if (in(x, y) && g[x][y] == 0) {
                        for (int u = 0; u < 2; u++) {
                            int tx = i + dx[k][u];
                            int ty = j + dy[k][u];
                            if (in(tx, ty)) {
                                vis[tx][ty] = true;
                            }
                        }
                    }
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == false) {
                    ok = false;
                    break;
                }
            }
            if (ok == false) break;
        }
        if (ok) {
            if (cnt < minx) {
                minx = cnt;
                ans = 1;
            } else if (cnt == minx) {
                ans++;
            }
        }
    }
    cout << minx << " " << ans << endl;
    return 0;
}