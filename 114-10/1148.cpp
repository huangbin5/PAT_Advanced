#include <iostream>
using namespace std;
// #define DEBUG

const int maxn = 105;
int word[maxn] = { 0 }, n;
int w1, w2;

bool judge() {
    int manLie = 0, wolLie = 0;
    for (int x = 1; x <= n; ++x) {
        if ((word[x] < 0 && word[x] != -w1 && word[x] != -w2) || (word[x] > 0 && (word[x] == w1 || word[x] == w2))) {
            if (x == w1 || x == w2) {
                ++wolLie;
                if (wolLie > 1)
                    return false;
            } else {
                ++manLie;
                if (manLie > 1)
                    return false;
            }
        }
    }
    if (wolLie == 1 && manLie == 1)
        return true;
    else
        return false;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &word[i]);
    }
    //对每一对狼
    for (w1 = 1; w1 < n; ++w1) {
        for (w2 = w1 + 1; w2 <= n; ++w2) {
            if (judge()) {
                printf("%d %d", w1, w2);
                return 0;
            }
        }
    }
    printf("No Solution");
    return 0;
}