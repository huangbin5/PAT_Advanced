#include <iostream>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
// #define DEBUG

const int maxn = 10005;
vector<int> edge[maxn];
int color[maxn];
set<int> types;
bool vis[maxn];
int n, m, k;

void init() {
    fill(color, color + n, -1);
    types.clear();
    memset(vis, false, n * sizeof(bool));
}

bool dfs(int u) {
    vis[u] = true;
    if (!types.count(color[u]))
        types.insert(color[u]);
    for (int i = 0; i < edge[u].size(); ++i) {
        int v = edge[u][i];
        if (color[u] == color[v]) {
            return false;
        } else if (!vis[v])
            if (!dfs(v))
                return false;
    }
    return true;
}

bool DFS() {
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            if (!dfs(i))
                return false;
        }
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    int u, v;
    while (m--) {
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    scanf("%d", &k);
    while (k--) {
        init();
        for (int i = 0; i < n; ++i) {
            scanf("%d", &color[i]);
        }
        if (DFS())
            printf("%d-coloring\n", types.size());
        else
            printf("No\n");
    }
    return 0;
}