#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
// #define DEBUG

const int maxn = 100005;
vector<int> child[maxn];
int n, minLevel = maxn, minCount;
double p, r;

void dfs(int index, int level) {
    if (child[index].size() == 0) {
        if (level < minLevel) {
            minLevel = level;
            minCount = 1;
        } else if (level == minLevel)
            ++minCount;
        return;
    }
    for (int i = 0; i < child[index].size(); ++i) {
        dfs(child[index][i], level + 1);
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    int k, ch;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &ch);
            child[i].push_back(ch);
        }
    }
    dfs(0, 0);
    printf("%.4f %d\n", p * pow(1 + r, minLevel), minCount);
    return 0;
}