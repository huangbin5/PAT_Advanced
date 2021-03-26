#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// #define DEBUG

struct Node {
    int v, line;
    Node() {}
    Node(int _v, int _line)
        : v(_v)
        , line(_line) {}
};
struct dNode {
    int v, dis, cnt;
    dNode(int _v, int _dis, int _cnt)
        : v(_v)
        , dis(_dis)
        , cnt(_cnt) {}
    bool operator<(const dNode& tmp) const {
        if (dis != tmp.dis)
            return dis > tmp.dis;
        return cnt > tmp.cnt;
    }
};
const int maxn = 10000;
const int INF = 0x3fffffff;
vector<Node> edge[maxn];
int n, m, k, v1, v2;
//距离，前驱，前驱到该站的线路，换乘站数目
int dis[maxn], pre[maxn], line[maxn], cnt[maxn];
bool vis[maxn];
priority_queue<dNode> pq;

void init() {
    fill(dis, dis + maxn, INF);
    for (int i = 0; i < maxn; ++i)
        pre[i] = i;
    // memset大小要注意
    memset(line, 0, sizeof(line));
    fill(cnt, cnt + maxn, INF);
    memset(vis, false, sizeof(vis));
    //记得队列要清空
    while (!pq.empty()) {
        pq.pop();
    }
}

void dijkstra(int s) {
    init();
    dis[s] = 0;
    pq.push(dNode(s, 0, 0));
    while (!pq.empty()) {
        int u = pq.top().v;
        pq.pop();
        if (u == v2)
            break;
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = 0; i < edge[u].size(); ++i) {
            int v = edge[u][i].v, nextLine = edge[u][i].line;
            if (!vis[v]) {
                if (dis[u] + 1 < dis[v]) {
                    dis[v] = dis[u] + 1;
                    pre[v] = u;
                    line[v] = nextLine;
                    cnt[v] = cnt[u] + (line[v] != line[u]);
                    pq.push(dNode(v, dis[v], cnt[v]));
                } else if (dis[u] + 1 == dis[v] && cnt[u] + (nextLine != line[u]) < cnt[v]) {
                    //注意这个判断条件是+nextLine而不是line[v]，因为此时line[v]还没有更新
                    pre[v] = u;
                    line[v] = nextLine;
                    cnt[v] = cnt[u] + (line[v] != line[u]);
                    pq.push(dNode(v, dis[v], cnt[v]));
                }
            }
        }
    }
}

void dfs(int x, int nextLine, int nextTrans) {
    if (line[x] == nextLine) {
        dfs(pre[x], nextLine, nextTrans);
    } else {
        if (pre[x] != x)
            dfs(pre[x], line[x], x);
        //编号是4位数
        printf("Take Line#%d from %04d to %04d.\n", nextLine, x, nextTrans);
    }
}

void printLine() {
    printf("%d\n", dis[v2]);
    dfs(v2, line[v2], v2);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &m, &v1);
        while (--m) {
            scanf("%d", &v2);
            edge[v1].push_back(Node(v2, i));
            edge[v2].push_back(Node(v1, i));
            v1 = v2;
        }
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &v1, &v2);
        dijkstra(v1);
        printLine();
    }
    return 0;
}