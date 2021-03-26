#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// #define DEBUG

struct Node {
    int v, time;
    Node(int _v, int _time)
        : v(_v)
        , time(_time) {}
};

const int maxInt = 0x3fffffff;
const int maxn = 505;
int cmax, n, sp, m;
//每个站点多余的单车数，负数表示不够
int c[maxn];
//边
vector<Node> edge[maxn];
bool visited[maxn] = { false };

//花费时间
int cost[maxn];
//路径前驱
vector<int> pre[maxn];
//需要带最少的单车数
int minBring = maxInt;
int minRemain = maxInt;
vector<int> tmp, ans;

void init() { fill(cost, cost + maxn, maxInt); }

void getAns() {
    init();
    cost[0] = 0;
    for (;;) {
        //选择最小值
        int u, minCost = maxInt;
        for (int i = 0; i <= n; ++i) {
            if (!visited[i] && cost[i] < minCost) {
                u = i;
                minCost = cost[i];
            }
        }
        visited[u] = true;
        if (u == sp)
            break;
        //更新花费
        for (int i = 0; i < edge[u].size(); ++i) {
            int v = edge[u][i].v;
            int t = edge[u][i].time;
            if (!visited[v]) {
                if (cost[u] + t < cost[v]) {
                    cost[v] = cost[u] + t;
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (cost[u] + t == cost[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

// bfs是关键，浪费了三四个小时。只在递归基计算！
void dfs(int v) {
    tmp.push_back(v);
    if (v) {
        for (int i = 0; i < pre[v].size(); ++i) {
            dfs(pre[v][i]);
        }
    } else {
        int bring = 0, remain = 0;
        for (int i = tmp.size() - 1; i >= 0; --i) {
            int u = tmp[i];
            if (remain + c[u] >= 0) {
                //剩余的单车足够补偿
                remain += c[u];
            } else {
                //需要携带的单车数累计
                bring -= remain + c[u];
                //需要后更新remain，因为更新bring要用到remain
                remain = 0;
            }
        }
        if (bring < minBring || bring == minBring && remain < minRemain) {
            minBring = bring;
            minRemain = remain;
            ans = tmp;
        }
    }
    tmp.pop_back();
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    int r;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &r);
        c[i] = r - (cmax >> 1);
    }
    int v1, v2, t;
    while (m--) {
        scanf("%d%d%d", &v1, &v2, &t);
        edge[v1].push_back(Node(v2, t));
        edge[v2].push_back(Node(v1, t));
    }
    getAns();
    dfs(sp);
    printf("%d ", minBring);
    for (int i = ans.size() - 1; i >= 0; --i) {
        printf("%d", ans[i]);
        if (i > 0)
            printf("->");
    }
    printf(" %d", minRemain);
    return 0;
}