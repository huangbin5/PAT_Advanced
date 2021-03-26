#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
// #define DEBUG

ll c[100005];
ll p[100005];

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int nc, np;
    scanf("%d", &nc);
    for (int i = 0; i < nc; ++i) {
        scanf("%lld", &c[i]);
    }
    scanf("%d", &np);
    for (int i = 0; i < np; ++i) {
        scanf("%lld", &p[i]);
    }
    sort(c, c + nc);
    sort(p, p + np);
    ll ans = 0;
    int i = 0, j = 0;
    while (i < nc && j < np && c[i] < 0 && p[j] < 0) {
        ans += c[i] * p[j];
        ++i;
        ++j;
    }
    i = nc - 1, j = np - 1;
    while (i >= 0 && j >= 0 && c[i] > 0 && p[j] > 0) {
        ans += c[i] * p[j];
        --i;
        --j;
    }
    printf("%lld", ans);
    return 0;
}