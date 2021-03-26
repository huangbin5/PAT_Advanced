#include <iostream>
using namespace std;
// #define DEBUG

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, m10 = 1, ans = 0;
    scanf("%d", &n);
    while (m10 <= n) {
        if (n / m10 % 10 == 0) {
            ans += n / (m10 * 10) * m10;
        } else if (n / m10 % 10 == 1) {
            ans += n / (m10 * 10) * m10 + n % m10 + 1;
        } else {
            ans += (n / (m10 * 10) + 1) * m10;
        }
        m10 *= 10;
    }
    printf("%d", ans);
    return 0;
}