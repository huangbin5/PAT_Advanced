#include <algorithm>
#include <iostream>
using namespace std;
// #define DEBUG

int coin[100005];

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &coin[i]);
    }
    sort(coin, coin + N);
    int left = 0, right = N - 1;
    while (left < right) {
        if (coin[left] + coin[right] == M) {
            printf("%d %d", coin[left], coin[right]);
            return 0;
        }
        if (coin[left] + coin[right] > M)
            --right;
        else
            ++left;
    }
    printf("No Solution");
    return 0;
}