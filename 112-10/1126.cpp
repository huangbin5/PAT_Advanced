#include <iostream>
#include <vector>
using namespace std;
// #define DEBUG

//欧拉图首先要连通
const int maxn = 505;
vector<int> edge[maxn];
bool vis[maxn] = { false };

void dfs(int x) {
    vis[x] = true;
    for (int i = 0; i < edge[x].size(); ++i)
        if (!vis[edge[x][i]])
            dfs(edge[x][i]);
}

//有欧拉环路：所有的点度数为偶数
//只有欧拉路径：只有两个点度数为奇数，剩余的点度数为偶数
int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    int v1, v2;
    while (m--) {
        scanf("%d%d", &v1, &v2);
        edge[v1].push_back(v2);
        edge[v2].push_back(v1);
    }
    int odd = 0;
    for (int i = 1; i <= n; ++i) {
        int size = edge[i].size();
        if (size & 1)
            ++odd;
        if (i == n)
            printf("%d\n", size);
        else
            printf("%d ", size);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            printf("Non-Eulerian");
            return 0;
        }
    }
    if (odd == 2)
        printf("Semi-Eulerian");
    else if (!odd)
        printf("Eulerian");
    else
        printf("Non-Eulerian");
    return 0;
}