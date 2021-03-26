#include <algorithm>
#include <iostream>
using namespace std;
#define DEBUG

struct fraction {
    int son, mother;
};

int gcd(int a, int b) {
    if (!a)
        return b;
    if (abs(a) > abs(b))
        swap(a, b);
    return gcd(b % a, a);
}

void simplify(fraction& f) {
    int g = gcd(f.son, f.mother);
    f.mother /= g;
    f.son /= g;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, son, mother;
    scanf("%d", &n);
    fraction fra = { 0, 1 };
    while (n--) {
        scanf("%d/%d", &son, &mother);
        fra.son = fra.son * mother + son * fra.mother;
        fra.mother *= mother;
        simplify(fra);
    }
    if (fra.son == 0) {
        printf("0");
        return 0;
    }
    if (abs(fra.son) > abs(fra.mother)) {
        printf("%d", fra.son / fra.mother);
        fra.son %= fra.mother;
        if (fra.son != 0) {
            printf(" %d/%d", fra.son, fra.mother);
        }
    } else {
        printf("%d/%d", fra.son, fra.mother);
    }
    return 0;
}