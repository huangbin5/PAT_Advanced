#include <cmath>
#include <iostream>
using namespace std;
// #define DEBUG

const int MAX_N = 100005;
int prime[MAX_N], primeNum = 0;
bool p[MAX_N] = { false };
int N;

struct factor {
    int x, cnt;
} fac[10];

void initPrime() {
    for (int i = 2; i < MAX_N; ++i) {
        if (!p[i]) {
            prime[primeNum++] = i;
            for (int j = i + i; j < MAX_N; j += i) {
                p[j] = true;
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
    printf("%d\n", prime[primeNum - 1]);
    scanf("%d", &N);
    if (N == 1)
        printf("1=1\n");
    else {
        printf("%d=", N);
        int i = 0, sqr = (int)sqrt(1.0 * N), count = 0;
        while (prime[i] <= sqr) {
            if (N % prime[i] == 0) {
                fac[count].x = prime[i];
                fac[count].cnt = 0;
                while (N % prime[i] == 0) {
                    ++fac[count].cnt;
                    N /= prime[i];
                }
                ++count;
            }
            ++i;
        }
        if (N != 1) {
            fac[count].x = N;
            fac[count++].cnt = 1;
        }
        for (i = 0; i < count; ++i) {
            if (i)
                printf("*");
            printf("%d", fac[i].x);
            if (fac[i].cnt > 1)
                printf("^%d", fac[i].cnt);
        }
        puts("");
    }
    return 0;
}