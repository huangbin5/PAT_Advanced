#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// #define DEBUG

struct Node {
    int v, len, time;
    Node() {}
    Node(int _v, int _len, int _time)
        : v(_v)
        , len(_len)
        , time(_time) {}
};

const int maxn = 510;
const int INF = 0x3fffffff;
int n, m, from, to;
vector<Node> edge[maxn];
bool visited[maxn] = { false };

int pre[maxn];
int dist[maxn];
int dime[maxn];
vector<int> dAns;
int cost[maxn];
int tnum[maxn];
vector<int> tAns;

void init() {
    fill(dist, dist + maxn, INF);
    fill(dime, dime + maxn, INF);
    fill(cost, cost + maxn, INF);
    fill(tnum, tnum + maxn, INF);
}

//遍历之前要重置
void reset() {
    for (int i = 0; i < maxn; ++i) {
        pre[i] = i;
    }
    fill(visited, visited + maxn, false);
}

void dfs(int v, vector<int>& ans) {
    ans.push_back(v);
    if (v != from)
        dfs(pre[v], ans);
}

void getShortest() {
    reset();
    dist[from] = 0;
    dime[from] = 0;
    for (;;) {
        int u, minD = INF;
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && dist[i] < minD) {
                u = i;
                minD = dist[i];
            }
        }
        visited[u] = true;
        if (u == to)
            break;
        for (int i = 0; i < edge[u].size(); ++i) {
            Node node = edge[u][i];
            if (!visited[node.v]) {
                if (dist[u] + node.len < dist[node.v]
                    || (dist[u] + node.len == dist[node.v] && dime[u] + node.time < dime[node.v])) {
                    dist[node.v] = dist[u] + node.len;
                    dime[node.v] = dime[u] + node.time;
                    pre[node.v] = u;
                }
            }
        }
    }
}

void getFastest() {
    reset();
    cost[from] = 0;
    tnum[from] = 0;
    for (;;) {
        int u, minT = INF;
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && cost[i] < minT) {
                u = i;
                minT = cost[i];
            }
        }
        visited[u] = true;
        if (u == to)
            break;
        for (int i = 0; i < edge[u].size(); ++i) {
            Node node = edge[u][i];
            if (!visited[node.v]) {
                if (cost[u] + node.time < cost[node.v] || (cost[u] + node.time == cost[node.v] && tnum[u] + 1 < tnum[node.v])) {
                    cost[node.v] = cost[u] + node.time;
                    tnum[node.v] = tnum[u] + 1;
                    pre[node.v] = u;
                }
            }
        }
    }
}

void print(vector<int>& ans) {
    for (int i = ans.size() - 1; i >= 0; --i) {
        if (i)
            printf("%d -> ", ans[i]);
        else
            printf("%d\n", ans[i]);
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    init();
    scanf("%d%d", &n, &m);
    int v1, v2, one, l, t;
    while (m--) {
        scanf("%d%d%d%d%d", &v1, &v2, &one, &l, &t);
        edge[v1].push_back(Node(v2, l, t));
        if (!one)
            edge[v2].push_back(Node(v1, l, t));
    }
    scanf("%d%d", &from, &to);
    getShortest();
    dfs(to, dAns);
    getFastest();
    dfs(to, tAns);
    if (dAns == tAns) {
        printf("Distance = %d; Time = %d: ", dist[to], cost[to]);
        print(dAns);
    } else {
        printf("Distance = %d: ", dist[to]);
        print(dAns);
        printf("Time = %d: ", cost[to]);
        print(tAns);
    }
    return 0;
}