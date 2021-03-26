#include <algorithm>
#include <iostream>
using namespace std;
// #define DEBUG

bool cmp(int* a1, int* a2, int n) {
    while (n--) {
        if (*a1 != *a2)
            return false;
        ++a1;
        ++a2;
    }
    return true;
}

void myMerge(int* a1, int n, int step) {
    for (int i = 0; i < n; i += step) {
        sort(a1 + i, a1 + min(n, i + step));
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, a1[105], a2[105];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a1[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a2[i]);
    }
    int i = 1;
    while (a2[i - 1] <= a2[i]) {
        ++i;
    }
    if (cmp(a1 + i, a2 + i, n - i)) {
        printf("Insertion Sort\n");
        sort(a2, a2 + i + 1);
        for (i = 0; i < n; ++i) {
            if (i)
                printf(" %d", a2[i]);
            else
                printf("%d", a2[i]);
        }
    } else {
        printf("Merge Sort\n");
        i = 1;
        while (i <= n) {
            i <<= 1;
            myMerge(a1, n, i);
            if (cmp(a1, a2, n))
                break;
        }
        while (i <= n) {
            i <<= 1;
            myMerge(a1, n, i);
            if (!cmp(a1, a2, n)) {
                for (i = 0; i < n; ++i) {
                    if (i)
                        printf(" %d", a1[i]);
                    else
                        printf("%d", a1[i]);
                }
                break;
            }
        }
    }
    return 0;
}