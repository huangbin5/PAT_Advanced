#include <iostream>
using namespace std;
// #define DEBUG

const int maxn = 10005;
int n, k, total = 0, cnt = 0;
int father[maxn];

void init() {
    for (int i = 0; i < maxn; ++i)
        father[i] = i;
}

int find(int x) {
    if (father[x] == x)
        return x;
    int f = find(father[x]);
    father[x] = f;
    return f;
}

void merge(int a, int b) { father[find(b)] = find(a); }

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    init();
    scanf("%d", &n);
    int a, b;
    while (n--) {
        scanf("%d%d", &k, &a);
        total = max(total, a);
        k--;
        while (k--) {
            scanf("%d", &b);
            total = max(total, b);
            merge(a, b);
        }
    }
    for (int i = 1; i <= total; ++i) {
        if (i == father[i])
            ++cnt;
    }
    printf("%d %d\n", cnt, total);
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &a, &b);
        if (find(a) == find(b))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}