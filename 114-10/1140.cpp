#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
// #define DEBUG

const int maxn = 100000;
char s1[maxn], s2[maxn];

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n;
    scanf("%s%d", &s1, &n);
    char *p1 = s1, *p2 = s2;
    for (int i = 2; i <= n; ++i) {
        swap(p1, p2);
        // p1的下标
        int idx = 0, len = strlen(p2);
        for (int j = 0; j < len; ++j) {
            int cnt = 1;
            while (j < len - 1 && p2[j] == p2[j + 1]) {
                ++j;
                ++cnt;
            }
            p1[idx++] = p2[j];
            p1[idx++] = cnt + '0';
        }
        p1[idx] = '\0';
    }
    printf("%s", p1);
    return 0;
}