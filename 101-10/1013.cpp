#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// #define DEBUG

//需要修建的路数就是连通分量的个数减1
const int maxn = 1005;
int n, m, k, query, ans;
vector<int> edge[maxn];
bool visited[maxn];

void init() { fill(visited, visited + maxn, false); }

void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < edge[v].size(); ++i) {
        if (edge[v][i] != query && !visited[edge[v][i]]) {
            dfs(edge[v][i]);
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &k);
    int v1, v2;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &v1, &v2);
        edge[v1].push_back(v2);
        edge[v2].push_back(v1);
    }
    while (k--) {
        scanf("%d", &query);
        init();
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (i != query && !visited[i]) {
                dfs(i);
                ++ans;
            }
        }
        printf("%d\n", ans - 1);
    }
    return 0;
}