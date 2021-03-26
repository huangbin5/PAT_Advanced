#include <iostream>
#include <vector>
using namespace std;
// #define DEBUG

vector<int> child[100];
int ans[100] = { 0 }, maxLevel;

void dfs(int idx, int level) {
    if (child[idx].size() == 0) {
        ++ans[level];
        if (level > maxLevel)
            maxLevel = level;
        return;
    }
    for (int i = 0; i < child[idx].size(); ++i) {
        dfs(child[idx][i], level + 1);
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, m, id, k, ch;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &id, &k);
        while (k--) {
            scanf("%d", &ch);
            child[id].push_back(ch);
        }
    }
    dfs(1, 0);
    for (int i = 0; i <= maxLevel; ++i) {
        if (i)
            printf(" %d", ans[i]);
        else
            printf("%d", ans[i]);
    }
    return 0;
}