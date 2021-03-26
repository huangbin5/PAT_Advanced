#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
// #define DEBUG

struct Node {
    int v, dist;
    Node() {}
    Node(int _v, int _dist)
        : v(_v)
        , dist(_dist) {}
};

const int maxInt = 0x3fffffff;
const int maxn = 500;

int n, m, s, d;
int man[maxn];
vector<Node> edge[maxn];

int dist[maxn];
int team[maxn] = { 0 };
int num[maxn] = { 0 };
set<int> pre[maxn];

void init() { fill(dist, dist + maxn, maxInt); }

void bf() {
    dist[s] = 0;
    team[s] = man[s];
    num[s] = 1;
    for (int i = 0; i < n - 1; ++i) {
        for (int u = 0; u < n; ++u) {
            for (int j = 0; j < edge[u].size(); ++j) {
                int v = edge[u][j].v;
                int e = edge[u][j].dist;
                if (dist[u] + e < dist[v]) {
                    dist[v] = dist[u] + e;
                    team[v] = team[u] + man[v];
                    num[v] = num[u];
                    pre[v].clear();
                    pre[v].insert(u);
                } else if (dist[u] + e == dist[v]) {
                    if (team[u] + man[v] > team[v])
                        team[v] = team[u] + man[v];
                    num[v] = 0;
                    pre[v].insert(u);
                    for (set<int>::iterator it = pre[v].begin(); it != pre[v].end(); ++it) {
                        num[v] += num[*it];
                    }
                }
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    init();
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &man[i]);
    }
    int v1, v2, e;
    while (m--) {
        scanf("%d%d%d", &v1, &v2, &e);
        edge[v1].push_back(Node(v2, e));
        edge[v2].push_back(Node(v1, e));
    }
    bf();
    printf("%d %d\n", num[d], team[d]);
    return 0;
}