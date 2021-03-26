#include <iostream>
using namespace std;
// #define DEBUG
typedef long long ll;

ll A, B, C;
int N;

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%lld%lld%lld", &A, &B, &C);
        ll sum = A + B;
        if (A > 0 && B > 0 && sum < 0)
            printf("Case #%d: %s\n", i, "true");
        else if (A < 0 && B < 0 && sum >= 0)
            printf("Case #%d: %s\n", i, "false");
        else
            printf("Case #%d: %s\n", i, sum > C ? "true" : "false");
    }
    return 0;
}