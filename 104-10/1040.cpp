#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
// #define DEBUG

const int maxn = 1005;
// dp[i][j]=1表示s[i...j]为回文串
int dp[maxn][maxn] = { 0 };

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    string s;
    getline(cin, s);
    int len = s.size();
    // int ans = 1;
    // for (int i = 0; i < len; ++i) {
    //     dp[i][i] = 1;
    //     if (i && s[i - 1] == s[i]) {
    //         dp[i - 1][i] = 2;
    //         ans = 2;
    //     }
    // }
    // for (int k = 3; k <= len; ++k) {
    //     for (int i = 0; i + k - 1 < len; ++i) {
    //         int j = i + k - 1;
    //         if (s[i] == s[j] && dp[i + 1][j - 1]) {
    //             dp[i][j] = 1;
    //             ans = k;
    //         }
    //     }
    // }
    // printf("%d\n", ans);
    int ans = 1, i;
    //长度为奇数时
    for (int c = 0; c < len; ++c) {
        bool flag = true;
        for (i = 1; c - i >= 0 && c + i < len; ++i) {
            if (s[c - i] != s[c + i]) {
                flag = false;
                break;
            }
        }
        ans = max(ans, 2 * i - 1);
    }
    //长度为偶数时
    for (int c = 0; c < len - 1; ++c) {
        bool flag = true;
        for (i = 0; c - i >= 0 && c + i + 1 < len; ++i) {
            if (s[c - i] != s[c + i + 1]) {
                flag = false;
                break;
            }
        }
        ans = max(ans, 2 * i);
    }
    printf("%d\n", ans);
    return 0;
}