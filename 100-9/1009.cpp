#include <iostream>
using namespace std;
// #define DEBUG

double num[1005] = { 0 }, ans[2005] = { 0 };

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, exp;
    double an;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &exp);
        scanf("%lf", &num[exp]);
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &exp);
        scanf("%lf", &an);
        for (int i = 0; i < 1001; ++i) {
            if (num[i]) {
                ans[i + exp] += an * num[i];
            }
        }
    }
    int count = 0;
    for (int i = 0; i < 2005; ++i) {
        if (ans[i]) {
            ++count;
        }
    }
    printf("%d", count);
    for (int i = 2005; i >= 0; --i) {
        if (ans[i])
            printf(" %d %.1f", i, ans[i]);
    }
    return 0;
}