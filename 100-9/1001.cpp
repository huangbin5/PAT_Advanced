#include <algorithm>
#include <iostream>
using namespace std;
// #define DEBUG

void format(int n) {
    if (!n) {
        printf("0");
        return;
    }
    int num[3], size = 0;
    while (n) {
        num[size++] = n % 1000;
        n /= 1000;
    }
    for (int i = size - 1; i >= 0; --i) {
        if (i == size - 1)
            printf("%d", num[i]);
        else
            printf(",%03d", num[i]);
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int a, b, c;
    scanf("%d%d", &a, &b);
    c = a + b;
    if (c < 0)
        printf("-");
    format(abs(c));
    return 0;
}