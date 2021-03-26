#include <algorithm>
#include <iostream>
using namespace std;
#define DEBUG

const int maxn = 100005;
int cou[maxn], pro[maxn];
int n, m;

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif // DEBUG
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &cou[i]);
    sort(cou, cou + n);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
        scanf("%d", &pro[i]);
    sort(pro, pro + m);
    int i = 0, j = 0;
    long long ans = 0;
    while (i < n && j < m && cou[i] < 0 && pro[j] < 0)
        ans += cou[i++] * pro[j++];
    i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0 && cou[i] > 0 && pro[j] > 0)
        ans += cou[i--] * pro[j--];
    printf("%lld", ans);
    return 0;
}
