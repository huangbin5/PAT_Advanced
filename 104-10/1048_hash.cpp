#include <algorithm>
#include <iostream>
using namespace std;
// #define DEBUG

int coinNum[505] = { 0 };

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int N, M, value;
    scanf("%d%d", &N, &M);
    while (N--) {
        scanf("%d", &value);
        ++coinNum[value];
    }
    for (int i = max(1, M - 500); i <= min(M / 2 + 1, 500); ++i) {
        if ((i == M - i && coinNum[i] >= 2) || (i != M - i && coinNum[i] >= 1 && coinNum[M - i] >= 1)) {
            printf("%d %d", i, M - i);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}