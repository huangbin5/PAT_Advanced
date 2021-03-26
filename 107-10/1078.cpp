#include <cmath>
#include <iostream>
using namespace std;
// #define DEBUG

const int maxn = 10010;
// 0-是；1-不是
int prime[maxn] = { 0 };
int hashTable[maxn] = { 0 };

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
    int m, n;
    scanf("%d%d", &m, &n);
    while (prime[m])
        ++m;
    int num, hc, inc, newHc;
    bool isFirst = true;
    while (n--) {
        scanf("%d", &num);
        hc = num % m;
        if (!hashTable[hc]) {
            hashTable[hc] = 1;
            if (isFirst) {
                printf("%d", hc);
                isFirst = false;
            } else
                printf(" %d", hc);
        } else {
            inc = 1;
            do {
                newHc = (hc + (int)pow(inc, 2)) % m;
                if (!hashTable[newHc]) {
                    hashTable[newHc] = 1;
                    break;
                }
                ++inc;
            } while (newHc != hc);
            if (newHc == hc)
                printf(" -");
            else
                printf(" %d", newHc);
        }
    }
    return 0;
}