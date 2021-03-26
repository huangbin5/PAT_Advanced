#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
// #define DEBUG

const int maxn = 10005;
vector<int> edge[maxn];
int cnt[maxn], n, m, k;

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    int v1, v2;
    while (m--) {
        scanf("%d%d", &v1, &v2);
        edge[v1].push_back(v2);
        edge[v2].push_back(v1);
    }
    scanf("%d", &m);
    while (m--) {
        memset(cnt, 0, sizeof(cnt));
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &v1);
            cnt[v1] += edge[v1].size();
            for (int i = 0; i < edge[v1].size(); ++i) {
                ++cnt[edge[v1][i]];
            }
        }
        int i;
        for (i = 0; i < n; ++i) {
            if (cnt[i] < edge[i].size())
                break;
        }
        if (i < n)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}