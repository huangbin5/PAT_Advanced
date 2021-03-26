#include <algorithm>
#include <iostream>
using namespace std;
// #define DEBUG

int n, arr[1005], node[1005], cnt = 0;

void inTrav(int r) {
    if (r > n)
        return;
    inTrav(2 * r);
    node[r] = arr[cnt++];
    inTrav(2 * r + 1);
}

void levelTrav() {
    for (int i = 1; i <= n; ++i) {
        if (i==1)
            printf("%d", node[i]);
        else
            printf(" %d", node[i]);
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    inTrav(1);
    levelTrav();
    return 0;
}