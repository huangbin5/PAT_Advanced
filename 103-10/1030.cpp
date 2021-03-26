#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// #define DEBUG

struct Node {
    int v, dist, cost;
    Node() {}
    Node(int _v, int _dist, int _cost)
        : v(_v)
        , dist(_dist)
        , cost(_cost) {}
};

const int maxInt = 0x3fffffff;
const int maxn = 500;

int n, m, s, d;
vector<Node> edge[maxn];
bool visited[maxn] = { false };

int dist[maxn];
int cost[maxn];
int pre[maxn];

void init() {
    fill(dist, dist + maxn, maxInt);
    fill(cost, cost + maxn, maxInt);
    for (int i = 0; i < maxn; ++i) {
        pre[i] = i;
    }
}

void findBest() {
    dist[s] = 0;
    cost[s] = 0;
    Node node;
    for (;;) {
        //选择最小距离的点
        int u = -1, minD = maxInt;
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && dist[i] < minD) {
                u = i;
                minD = dist[i];
            }
        }
        visited[u] = true;
        //找到目标
        if (u == d) {
            break;
        }
        //更新距离和花费
        for (int i = 0; i < edge[u].size(); ++i) {
            node = edge[u][i];
            if (!visited[node.v]) {
                if (dist[u] + node.dist < dist[node.v]) {
                    dist[node.v] = dist[u] + node.dist;
                    cost[node.v] = cost[u] + node.cost;
                    pre[node.v] = u;
                } else if (dist[u] + node.dist == dist[node.v] && cost[u] + node.cost < cost[node.v]) {
                    cost[node.v] = cost[u] + node.cost;
                    pre[node.v] = u;
                }
            }
        }
    }
}

void printPath(int v) {
    if (v != s) {
        printPath(pre[v]);
    }
    printf("%d ", v);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    init();
    scanf("%d%d%d%d", &n, &m, &s, &d);
    int v1, v2, a, b;
    while (m--) {
        scanf("%d%d%d%d", &v1, &v2, &a, &b);
        edge[v1].push_back(Node(v2, a, b));
        edge[v2].push_back(Node(v1, a, b));
    }
    findBest();
    printPath(d);
    printf("%d %d\n", dist[d], cost[d]);
    return 0;
}