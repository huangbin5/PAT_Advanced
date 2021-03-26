#include <algorithm>
#include <iostream>
using namespace std;
// #define DEBUG

/**
 * 数组大小不够在OJ上有的时候不会显示段错误，而是答案错误！！！
 */
const int maxn = 10005;
// k种颜色，m种颜色序列，n个序列
int k, m, n;
int eva[205], stripe[maxn];
// dp[i]表示只使用前i种颜色所能获得的最大长度
int dp[205];

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d", &k, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &eva[i]);
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &stripe[i]);
    }
    for (int i = 1; i <= m; ++i) {
        dp[i] = 0;
    }
    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= m; ++i) {
            if (stripe[j] == eva[i]) {
                ++dp[i];
                for (int t = 1; t < i; ++t) {
                    dp[i] = max(dp[i], dp[t] + 1);
                }
            }
        }
    }
    int ans = dp[1];
    for (int i = 2; i <= m; ++i) {
        ans = max(ans, dp[i]);
    }
    printf("%d", ans);
    return 0;
}