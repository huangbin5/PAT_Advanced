#include <iostream>
using namespace std;
// #define DEBUG

double w, t, l, odd = 1.0;

void getMax() {
    double m = w;
    char c = 'W';
    if (t > m) {
        m = t;
        c = 'T';
    }
    if (l > m) {
        m = l;
        c = 'L';
    }
    odd *= m;
    printf("%c ", c);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    for (int i = 0; i < 3; ++i) {
        scanf("%lf%lf%lf", &w, &t, &l);
        getMax();
    }
    printf("%.2f", (odd * 0.65 - 1) * 2);
    return 0;
}