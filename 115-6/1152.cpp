#include <cmath>
#include <iostream>
using namespace std;
// #define DEBUG

char s[1005];
int n, k, idx, num = 0, pow10k = 1;

void findFirst() {
    for (int i = 0; i < k; ++i) {
        num = num * 10 + s[i] - '0';
    }
}

void findNext() {
    ++idx;
    num = (num - (s[idx - k] - '0') * pow10k) * 10 + s[idx] - '0';
}

bool isPrime() {
    int sqr = sqrt(num);
    for (int i = 2; i <= sqr; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d%s", &n, &k, s);
    if (n < k) {
        printf("404");
        return 0;
    }
    for (int i = 0; i < k - 1; ++i) {
        pow10k *= 10;
    }
    idx = k - 1;
    for (findFirst(); idx < n; findNext()) {
        if (isPrime()) {
            char format[] = "%00d";
            format[2] = k + '0';
            printf(format, num);
            return 0;
        }
    }
    printf("404");
    return 0;
}