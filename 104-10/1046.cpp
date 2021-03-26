#include <algorithm>
#include <iostream>
using namespace std;
// #define DEBUG

int N, dist[100005], kase, a, b, totalDist = 0, toI[100005];

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &dist[i]);
        totalDist += dist[i];
        toI[i + 1] = totalDist;
    }
    scanf("%d", &kase);
    while (kase--) {
        scanf("%d%d", &a, &b);
        if (a > b)
            swap(a, b);
        int aToB = toI[b - 1] - toI[a - 1];
        printf("%d\n", min(aToB, totalDist - aToB));
    }
    return 0;
}