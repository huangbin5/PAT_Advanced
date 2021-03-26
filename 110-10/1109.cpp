#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
// #define DEBUG

struct student {
    char name[10];
    int height;
    bool operator<(student a) {
        if (height != a.height)
            return height > a.height;
        return strcmp(name, a.name) < 0;
    }
} s[10005], *ans[10005];

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d", s[i].name, &s[i].height);
    }
    sort(s, s + n);
    int col = n / k, lastCol = col + n - n / k * k;
    for (int i = 0; i < lastCol; ++i) {
        if (i % 2) {
            ans[lastCol / 2 - (i + 1) / 2] = &s[i];
        } else {
            ans[lastCol / 2 + (i + 1) / 2] = &s[i];
        }
    }
    for (int i = 1; i < k; ++i) {
        int pos = lastCol + (i - 1) * col;
        for (int j = 0; j < col; ++j) {
            if (j % 2) {
                ans[pos + col / 2 - (j + 1) / 2] = &s[pos + j];
            } else {
                ans[pos + col / 2 + (j + 1) / 2] = &s[pos + j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%s", ans[i]->name);
        if (i >= lastCol - 1 && (i - lastCol + 1) % col == 0) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
    return 0;
}