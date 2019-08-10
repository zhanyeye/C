#include <iostream>
#include <cstring>

using namespace std;

const int N = 1001;
const int M = 10001;
const int INF = 0x3f3f3f3f;

struct edge {
    int v, w, next;
    edge() {}
    edge(int _v, int _w, int _next): v(_v), w(_w), next(_next) {}
} e[M * 2];

int head[N];
int cnt = 0; //链表大小

void insert(int u, int v, int w) {
    e[cnt] = edge(v, w, head[u]);
    head[u] = cnt++;
}

void insert2(int u, int v, int w) {
    insert(u, v, w);
    insert(v, u, w);
}

void init() {
    memset(head, -1, sizeof head);
    cnt = 0;
}

int n, m;
int dis[N];
bool vis[N];

void dijkstra(int u) {
    memset(vis, false, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    dis[u] = 0;
    for (int i = 0; i < n; i++) {
        int min_dis = INF, min_index = -1;
        for (int j = 1; j <= n; j++) { //j 从0 还是从 1 根据情况而定
            if (!vis[j] && dis[j] < min_dis) {
                min_index = j;
                min_dis = dis[j];
            }
        }
        if (min_dis == -1) { //图不是连通图
            return;
        }
        vis[min_index] = true;
        for (int j = head[min_index]; ~j; j = e[j].next) {
            int v = e[j].v;
            int w = e[j].w;
            if (!vis[v] && dis[v] > dis[min_index] + w) {
                dis[v] = dis[min_index] + w;
            }
        }
    }
}

int main() {
    init();
    int u, v, w;
    cin >> n >> m;
    while (m--) {
        cin >> u >> v >> w;
        insert2(u, v, w);
    }
    dijkstra(1);
    cout << dis[n] << endl;
    return 0;
}