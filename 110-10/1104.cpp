#include <iostream>
using namespace std;
#define DEBUG

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    double a, ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &a);
        ans += a * (i + 1) * (n - i);
    }
    printf("%.2f", ans);
    return 0;
}