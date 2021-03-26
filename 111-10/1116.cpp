#include <iostream>
using namespace std;
// #define DEBUG

const int maxn = 10010;
// 0-是；1-不是
int prime[maxn] = { 0 };
int score[maxn] = { 0 };
int checked[maxn] = { 0 };

void initPrime() {
    prime[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        if (!prime[i]) {
            for (int j = i + i; j < maxn; j += i) {
                prime[j] = 1;
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    initPrime();
    int n, k, id;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &id);
        score[id] = i;
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &id);
        if (checked[id]) {
            printf("%04d: Checked\n", id);
        } else {
            if (score[id] == 0) {
                printf("%04d: Are you kidding?\n", id);
            } else {
                if (score[id] == 1) {
                    printf("%04d: Mystery Award\n", id);
                } else if (prime[score[id]]) {
                    printf("%04d: Chocolate\n", id);
                } else {
                    printf("%04d: Minion\n", id);
                }
                checked[id] = 1;
            }
        }
    }
    return 0;
}