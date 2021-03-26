#include <iostream>
using namespace std;
// #define DEBUG

const int maxn = 10005;
int k, n[maxn];
// dp[i]为以n[i]为结尾的最大子串和
struct Node {
    //起点，和
    int s, sum;
    Node() {}
    Node(int _s, int _sum)
        : s(_s)
        , sum(_sum) {}
} dp[maxn];

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &n[i]);
    }
    dp[0] = Node(0, n[0]);
    for (int i = 1; i < k; ++i) {
        if (dp[i - 1].sum >= 0) {
            dp[i] = Node(dp[i - 1].s, dp[i - 1].sum + n[i]);
        } else {
            dp[i] = Node(i, n[i]);
        }
    }
    int idx = 0;
    for (int i = 1; i < k; ++i) {
        if (dp[i].sum > dp[idx].sum) {
            idx = i;
        }
    }
    if (dp[idx].sum < 0) {
        printf("0 %d %d\n", n[0], n[k - 1]);
    } else {
        printf("%d %d %d\n", dp[idx].sum, n[dp[idx].s], n[idx]);
    }
    return 0;
}