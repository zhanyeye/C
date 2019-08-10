#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int N = 1001;
const int M = 10001;

struct edge {
    int v, w, next;
    edge() {}
    edge(int _v, int _w, int _next) : v(_v), w(_w), next(_next) {}
} E[M << 1];

int p[N];
int eid;

void init() {
    memset(p, -1, sizeof p);
    eid = 0;
}

void insert(int u, int v, int w) {
    E[eid] = edge(v, w, p[u]);
    p[u] = eid++;
}

int dis[N];
int cnt[N];
bool vis[N];
queue<int> q;
int n, m;


bool spfa(int s) {
    memset(dis, 0x3f, sizeof dis);
    memset(vis, false, sizeof vis);
    memset(cnt, 0, sizeof cnt);
    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    cnt[s] = 1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;

        for (int e = p[u]; e != -1; e = E[e].next) {
            int v = E[e].v;
            int w = E[e].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                    cnt[v]++;
                    if (cnt[v] > n) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    int a, b, c;
    init();
    while (m--) {
        cin >> a >> b >> c;
        insert(a, b, c);
    }

    for (int i = 1; i <= n; i++) {
        insert(0, i, 0);
    }

    if (spfa(0)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}