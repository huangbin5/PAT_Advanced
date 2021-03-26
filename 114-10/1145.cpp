#include <cmath>
#include <iostream>
using namespace std;
#define DEBUG

const int maxn = 10100;
int ht[maxn] = { 0 };
int mSize, n, m, searchTime = 0;

bool isPrime(int x) {
    int up = sqrt(x);
    for (int i = 2; i <= up; ++i) {
        if (x % i == 0)
            return false;
    }
    return true;
}

void insert(int x) {
    int pos = x % mSize, inc = 1, cnt = 1;
    // while (ht[pos] && cnt <= (mSize + 1) / 2) {
    while (ht[pos] && cnt <= mSize) {
        pos = (pos + inc) % mSize;
        inc += 2;
        ++cnt;
    }
    if (!ht[pos])
        ht[pos] = x;
    else
        printf("%d cannot be inserted.\n", x);
}

void search(int x) {
    int pos = x % mSize, inc = 1, cnt = 1;
    //不知道为什么上限是这个
    // while (ht[pos] && ht[pos] != x && cnt <= (mSize + 1) / 2) {
    while (ht[pos] && ht[pos] != x && cnt <= mSize) {
        pos = (pos + inc) % mSize;
        inc += 2;
        ++cnt;
    }
    searchTime += cnt;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d%d", &mSize, &n, &m);
    while (!isPrime(mSize))
        ++mSize;
    int a;
    while (n--) {
        scanf("%d", &a);
        insert(a);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &a);
        search(a);
    }
    printf("%.1f\n", (double)searchTime / m);
    return 0;
}