#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// #define DEBUG

set<int> s[55];

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, m, tmp, k, a, b;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &tmp);
            s[i].insert(tmp);
        }
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &a, &b);
        // set<int> commom, total;
        // set_intersection(s[a].begin(), s[a].end(), s[b].begin(), s[b].end(), inserter(commom, commom.begin()));
        // set_union(s[a].begin(), s[a].end(), s[b].begin(), s[b].end(), inserter(total, total.begin()));
        // printf("%.1f%%\n", 100.0 * commom.size() / total.size());
        int common = 0;
        for (set<int>::iterator it = s[a].begin(); it != s[a].end(); ++it) {
            if (s[b].find(*it) != s[b].end())
                ++common;
        }
        printf("%.1f%%\n", 100.0 * common / (s[a].size() + s[b].size() - common));
    }
    return 0;
}