#include <iostream>
#include <vector>
using namespace std;

const int maxn = 505;
const int INF = 0x3fffffff;
struct Node {
    int v, e;
    Node(int _v, int _e)
        : v(_v)
        , e(_e) {}
};
vector<Node> edge[maxn];
int c[maxn];
vector<int> pre[maxn];
int dis[maxn];
bool vis[maxn] = { false };
vector<int> tmp, path;
int n, m, cmax, half, sp, send = INF, recv = INF;

void dij() {
    for (int i = 0; i <= n; ++i)
        dis[i] = INF;
    dis[0] = 0;
    for (;;) {
        int u = -1;
        for (int i = 0; i <= n; ++i) {
            if (!vis[i] && (u == -1 || dis[i] < dis[u]))
                u = i;
        }
        vis[u] = true;
        if (u == sp)
            break;
        for (int i = 0; i < edge[u].size(); ++i) {
            int v = edge[u][i].v, e = edge[u][i].e;
            if (!vis[v]) {
                if (dis[u] + e < dis[v]) {
                    dis[v] = dis[u] + e;
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[u] + e == dis[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void dfs(int x) {
    if (x == 0) {
        int b = 0, r = 0;
        for (int i = tmp.size() - 1; i >= 0; --i) {
            if (c[tmp[i]] < half) {
                int need = half - c[tmp[i]];
                if (r < need) {
                    b += need - r;
                    r = 0;
                } else {
                    r -= need;
                }
            } else if (c[tmp[i]] > half) {
                r += c[tmp[i]] - half;
            }
        }
        if (b < send) {
            path = tmp;
            send = b;
            recv = r;
        } else if (b == send && r < recv) {
            recv = r;
            path = tmp;
        }
        return;
    }
    tmp.push_back(x);
    for (int i = 0; i < pre[x].size(); ++i) {
        dfs(pre[x][i]);
    }
    tmp.pop_back();
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif // DEBUG
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    half = cmax / 2;
    int u, v, e;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &c[i]);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &e);
        edge[u].push_back(Node(v, e));
        edge[v].push_back(Node(u, e));
    }
    dij();
    dfs(sp);
    printf("%d 0", send);
    for (int i = path.size() - 1; i >= 0; --i)
        printf("->%d", path[i]);
    printf(" %d", recv);
    return 0;
}
