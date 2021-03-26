#include <iostream>
using namespace std;
// #define DEBUG

double num1[1005] = { 0 }, num2[1005] = { 0 }, ans[1005] = { 0 };

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, exp;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &exp);
        scanf("%lf", &num1[exp]);
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &exp);
        scanf("%lf", &num2[exp]);
    }
    int count = 0;
    for (int i = 0; i < 1001; ++i) {
        if (num1[i] || num2[i]) {
            ans[i] = num1[i] + num2[i];
            if (ans[i])
                ++count;
        }
    }
    printf("%d", count);
    for (int i = 1000; i >= 0; --i) {
        if (ans[i])
            printf(" %d %.1f", i, ans[i]);
    }
    return 0;
}