#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define DEBUG

// 0-是，1-b不是
int prime[100000] = { 0 };

void initPrime() {
    prime[1] = 1;
    for (int i = 2; i < 100000; ++i) {
        if (!prime[i]) {
            for (int j = i + i; j < 100000; j += i) {
                prime[j] = 1;
            }
        }
    }
}

int getReverse(int n, int radix) {
    queue<int> s;
    while (n) {
        s.push(n % radix);
        n /= radix;
    }
    int ans = 0;
    while (!s.empty()) {
        ans = ans * radix + s.front();
        s.pop();
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    initPrime();
    int n, r;
    while (scanf("%d%d", &n, &r) == 2 && n > 0) {
        if (prime[n] || prime[getReverse(n, r)]) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
    return 0;
}