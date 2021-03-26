#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define DEBUG

const int maxn = 10005, maxm = 105;
// dp[i][j]表示前i枚硬币在价值小于j的条件下能组合的最大价值
int cost[maxn];
//表示最大最大价值
int dp[maxm] = { 0 };
// choose[i][j]=1表示价值为i时选用了第j个硬币
bool choose[maxm][maxn] = { false };

bool cmp(int a, int b) { return a > b; }

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &cost[i]);
    }
    sort(cost + 1, cost + n + 1, cmp);
    // dp[j]=max{dp[j],dp[j-cost[i]]+cost[i]}
    //每次加入一枚硬币
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= cost[i]; --j) {
            if (dp[j - cost[i]] + cost[i] >= dp[j]) {
                dp[j] = dp[j - cost[i]] + cost[i];
                choose[j][i] = true;
            }
        }
    }
    if (dp[m] != m) {
        printf("No Solution");
    } else {
        vector<int> s;
        while (m) {
            if (choose[m][n]) {
                s.push_back(n);
                m -= cost[n];
            }
            --n;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (i)
                printf(" %d", cost[s[i]]);
            else
                printf("%d", cost[s[i]]);
        }
    }
    return 0;
}