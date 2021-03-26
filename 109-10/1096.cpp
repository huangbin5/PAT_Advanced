#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
// #define DEBUG

bool isPrime(int n) {
    if (n <= 1)
        return false;
    int sqt = sqrt(n);
    for (int i = 2; i <= sqt; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    if (isPrime(n)) {
        printf("1\n%d", n);
        return 0;
    }
    int sqt = sqrt(n) + 1, len = 0, start;
    for (int i = 2; i <= sqt; ++i) {
        int tmp = n;
        for (int j = i; j <= sqt; ++j) {
            if (tmp % j)
                break;
            tmp /= j;
            if (j - i + 1 > len) {
                len = j - i + 1;
                start = i;
            }
        }
    }
    printf("%d\n", len);
    for (int i = 0; i < len; ++i) {
        if (i == 0)
            printf("%d", start);
        else
            printf("*%d", start + i);
    }
    return 0;
}