#include <iostream>
#include <cstring>
using namespace std;
const int MAX_N = 100;
const int MAX_M = 10000;
struct edge {
    int v, next;
    int len;
} E[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v) {
    E[eid].v = v;
    E[eid].next = p[u];
    p[u] = eid++;
}

int n, m;
int degree[MAX_N];

int cnt;
bool vis[MAX_N];
void dfs(int u) {
    vis[u] = true;
    cnt++;
    for (int i = p[u]; i != -1; i = E[i].next) {
        int v = E[i].v;
        if (!vis[v]) {
			dfs(v);
        }
    }
}

void euler() {
    dfs(1);
    if (cnt != n) {
        cout << "It doesn't have an euler path!" << endl;
        return;
    }
    int cntodd = 0;
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 == 1) {
            cntodd++;
        }
    }
    if (cntodd == 0) {
        cout << "It has an euler circuit!" << endl;
    } else if (cntodd == 2) {
        cout << "It has an euler path!" << endl;
    } else {
        cout << "It doesn't have an euler path!" << endl;
    }
}


int main() {
    init();
    memset(degree, 0, sizeof(degree));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
		int u, v;
        cin >> u >> v;
        insert(u, v);
        insert(v, u);
        degree[u]++;
        degree[v]++;
    }
    euler();
    return 0;
}