#include <iostream>
using namespace std;
#define DEBUG

void p(int n) {
    if (n >= 0 && n <= 9)
        printf("%d", n);
    else
        printf("%c", n - 10 + 'A');
}

void print(int n) {
    p(n / 13);
    p(n % 13);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    printf("#");
    int r, g, b;
    scanf("%d%d%d", &r, &g, &b);
    print(r);
    print(g);
    print(b);
    return 0;
}