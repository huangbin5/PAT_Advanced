#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
// #define DEBUG

const int maxn = 1005;
vector<int> edge[maxn];
bool vis[maxn], ans;
int n, m, k;

void init() {
    memset(vis, false, sizeof(vis));
    ans = true;
}

//每次遍历一个顶点时判断一它为起点的边的另一个顶点是否已经访问，如是，则不是拓扑排序
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
    }
    scanf("%d", &k);
    bool first = true;
    for (int i = 0; i < k; ++i) {
        init();
        for (int j = 0; j < n; ++j) {
            scanf("%d", &v);
            vis[v] = true;
            if (ans)
                for (int k = 0; k < edge[v].size(); ++k) {
                    if (vis[edge[v][k]])
                        ans = false;
                }
        }
        if (!ans)
            if (first) {
                printf("%d", i);
                first = false;
            } else
                printf(" %d", i);
    }
    return 0;
}