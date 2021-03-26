#include <iostream>
#include <vector>
using namespace std;
#define DEBUG

const int maxn = 505;
struct Node {
    int v, e;
    Node(int _v, int _e)
        : v(_v)
        , e(_e) {}
};
vector<Node> edge[maxn];
int team[maxn];
int dis[maxn], pathNum[maxn], people[maxn];
bool vis[maxn] = { false };
int n, m, c1, c2;

void sol() {
    for (int i = 0; i < maxn; ++i)
        dis[i] = 0x3fffffff;
    dis[c1] = 0;
    pathNum[c1] = 1;
    people[c1] = team[c1];
    for (;;) {
        int u = -1;
        for (int i = 0; i < n; ++i) {
            if (!vis[i] && (u == -1 || dis[i] < dis[u]))
                u = i;
        }
        if (u == c2)
            break;
        vis[u] = true;
        for (int i = 0; i < edge[u].size(); ++i) {
            int v = edge[u][i].v, e = edge[u][i].e;
            if (!vis[v]) {
                if (dis[u] + e < dis[v]) {
                    dis[v] = dis[u] + e;
                    pathNum[v] = pathNum[u];
                    people[v] = people[u] + team[v];
                } else if (dis[u] + e == dis[v]) {
                    pathNum[v] += pathNum[u];
                    if (people[u] + team[v] > people[v])
                        people[v] = people[u] + team[v];
                }
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif // DEBUG
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for (int i = 0; i < n; ++i)
        scanf("%d", &team[i]);
    int u, v, d;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &d);
        edge[u].push_back(Node(v, d));
        edge[v].push_back(Node(u, d));
    }
    sol();
    printf("%d %d", pathNum[c2], people[c2]);
}
