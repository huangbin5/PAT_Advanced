#include <iostream>
#include <vector>
using namespace std;
#define DEBUG

const int maxn = 505;
const int INF = 0xfffffff;
struct Node {
    int v, d, c;
    Node(int _v, int _d, int _c)
        : v(_v)
        , d(_d)
        , c(_c) {}
};
vector<Node> edge[maxn];
int dis[maxn], cos[maxn], pre[maxn];
bool vis[maxn] = { false };
int n, m, x, y;

void sol() {
    for (int i = 0; i < n; ++i) {
        dis[i] = INF;
        cos[i] = INF;
    }
    dis[x] = 0;
    cos[x] = 0;
    pre[x] = x;
    for (;;) {
        int u = -1;
        for (int i = 0; i < n; ++i) {
            if (!vis[i] && (u == -1 || dis[i] < dis[u]))
                u = i;
        }
        vis[u] = true;
        if (u == y)
            break;
        for (int i = 0; i < edge[u].size(); ++i) {
            int v = edge[u][i].v, d = edge[u][i].d, c = edge[u][i].c;
            if (dis[u] + d < dis[v]) {
                dis[v] = dis[u] + d;
                cos[v] = cos[u] + c;
                pre[v] = u;
            } else if (dis[u] + d == dis[v] && cos[u] + c < cos[v]) {
                cos[v] = cos[u] + c;
                pre[v] = u;
            }
        }
    }
}

void dfs(int r) {
    if (pre[r] != r)
        dfs(pre[r]);
    printf("%d ", r);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif // DEBUG
    scanf("%d%d%d%d", &n, &m, &x, &y);
    int u, v, d, c;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d%d", &u, &v, &d, &c);
        edge[u].push_back(Node(v, d, c));
        edge[v].push_back(Node(u, d, c));
    }
    sol();
    dfs(y);
    printf("%d %d", dis[y], cos[y]);
    return 0;
}
