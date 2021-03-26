#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
// #define DEBUG

map<int, int> couple;
int exist[100005] = { 0 };

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int a, b, n;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        couple[a] = b;
        couple[b] = a;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        exist[a] = 1;
    }
    int count = 0;
    for (int i = 0; i < 100000; ++i) {
        if (exist[i]) {
            if (exist[couple[i]]) {
                exist[i] = 0;
                exist[couple[i]] = 0;
            } else
                ++count;
        }
    }
    printf("%d\n", count);
    bool first = true;
    for (int i = 0; i < 100000; ++i) {
        if (exist[i]) {
            if (first) {
                printf("%05d", i);
                first = false;
            } else
                printf(" %05d", i);
        }
    }
    return 0;
}