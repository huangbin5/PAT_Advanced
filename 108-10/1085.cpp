#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
// #define DEBUG

int n;
ll num[100005], p;

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%lld", &n, &p);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &num[i]);
    }
    sort(num, num + n);
    int ans = 0, left = 0, right = 0;
    while (right < n) {
        while (right < n && num[right] <= p * num[left]) {
            ++right;
        }
        ans = max(ans, right - left);
        ++left;
    }
    printf("%d", ans);
    return 0;
}