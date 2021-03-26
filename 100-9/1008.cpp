#include <iostream>
using namespace std;
// #define DEBUG

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, f, p = 0, ans = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &f);
        if (f > p) {
            ans += (f - p) * 6 + 5;
        } else {
            ans += (p - f) * 4 + 5;
        }
        p = f;
    }
    printf("%d", ans);
    return 0;
}