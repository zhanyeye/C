#include <iostream>
#include <cstring>

using namespace std;

const int N = 100;
const int M = 10000;

struct edge {
    int v, next;
    edge() {}
    edge(int _v, int _next): v(_v), next(_next) {}
} E[N];

int p[N], eid;

void init() {
    memset(p, -1, sizeof p);
    eid = 0;
}

void insert(int u, int v) {
    E[eid] = edge(v, p[u]);
    p[u] = eid++;
}

int degree[N];
int n, m;

int euler() {
    int first = 0, last = 0;
    for (int i = 1; i <= n; i++) {
        if (degree[i] < -1 || degree[i] > 1) {
            cout << "It doesn't have an euler path!" << endl;
            return 0;
        } else if (degree[i] == -1) {
            if (first != 0) {
                cout << "It doesn't have an euler path!" << endl;
                return 0;
            } else {
                first = i;
            }
        } else if (degree[i] == 1) {
            if (last != 0) {
                cout << "It doesn't have an euler path!" << endl;
                return 0;
            } else {
                last = i;
            }
        }
    }

    if (first == 0 && last == 0) {
        cout << "It has an euler circuit!" << endl;
        return 1;
    } else if (first != 0 && last != 0) {
        cout << "It has an euler path" << endl;
        return first;
    } else {
        return 0;
    }
}

int main() {
    init();
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        insert(u, v);
        degree[u]--;
        degree[v]++;
    }
    euler();
    return 0;
}