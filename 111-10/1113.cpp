#include <algorithm>
#include <iostream>
using namespace std;
// #define DEBUG

int a[100005];

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if (n % 2)
        printf("1 ");
    else
        printf("0 ");
    sort(a, a + n);
    int lsum = 0;
    for (int i = 0; i < (n >> 1); ++i) {
        lsum += a[i];
    }
    printf("%d", sum - lsum * 2);
    return 0;
}