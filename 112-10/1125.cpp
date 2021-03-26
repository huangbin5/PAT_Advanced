#include <algorithm>
#include <iostream>
using namespace std;
// #define DEBUG

const int maxn = 10005;
double rope[maxn];

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &rope[i]);
    }
    sort(rope, rope + n);
    double ans = rope[0];
    for (int i = 1; i < n; ++i) {
        ans = (ans + rope[i]) / 2;
    }
    printf("%d\n", (int)ans);
    return 0;
}