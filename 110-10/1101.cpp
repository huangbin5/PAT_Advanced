#include <iostream>
using namespace std;
// #define DEBUG

const int maxn = 100005;
int a[maxn], lmax[maxn], pivot[maxn];

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (i)
            if (a[i - 1] > lmax[i - 1])
                lmax[i] = a[i - 1];
            else
                lmax[i] = lmax[i - 1];
        else
            lmax[i] = 0;
    }
    int size = 0, rmin;
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1) {
            if (lmax[i] <= a[i])
                pivot[size++] = a[i];
            rmin = a[i];
        } else {
            if (lmax[i] <= a[i] && a[i] <= rmin)
                pivot[size++] = a[i];
            if (a[i] < rmin)
                rmin = a[i];
        }
    }
    printf("%d\n", size);
    for (int i = size - 1; i >= 0; --i) {
        if (i)
            printf("%d ", pivot[i]);
        else
            printf("%d", pivot[i]);
    }
    puts("");
    return 0;
}