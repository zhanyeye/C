#include <iostream>
#include <cstring>
using namespace std;

const int N = 1000000;
const int M = 10000;
struct edge {
    int v, w;
    int next; //其实这里的next指向前驱
    edge() {}
    edge(int _v, int _w, int _next): v(_v), w(_w), next(_next) {} 
} e[M];

int head[N]; //head[i] 表示从点 i 
int cnt; //记录边的数量，来作为边的索引

void init() {
    memset(head, -1, sizeof head); //开始链表为空，头指针都初始化为 -1
    cnt = 0;
}

// 插入单向边
void insert(int u, int v, int w) {  
    e[cnt] = edge(v, w, head[u]); //新建一个终点为 v, 权值为 w 的边，插入到表示 u 的链表尾部
    head[u] = cnt; //将点 u 的 head指针移向后移一位，即刚刚插入的那个节点
    cnt++; 
}

// 插入双向边
void insert2(int u, int v, int w) { 
    insert(u, v, w);
    insert(v, u, w);
}

// 输出整张图中的所有边: !注意：输出的顺序和插入的顺序是相反的
void output(int n) { 
    for (int i = 0; i < n; i++) {
        cout << i << " : ";
        for (int j = head[i]; ~j; j = e[j].next) { // 遍历从 i 连出的所有边
            cout << "-> <[" << e[j].v << "]," << e[j].w << ">";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    init();
    int u, v, w;
    cin >> n >> m;
    while (m--) {
        cin >> u >> v >> w;
        insert2(u, v, w);
    }   
    output(n);
}