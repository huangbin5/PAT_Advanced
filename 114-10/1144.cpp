#include <iostream>
using namespace std;
// #define DEBUG

const int maxn = 100005;
bool flag[maxn] = { false };
int n;

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    int a;
    while (n--) {
        scanf("%d", &a);
        if (a > 0 && a < maxn)
            flag[a] = true;
    }
    for (int i = 1; i < maxn; ++i) {
        if (!flag[i]) {
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}