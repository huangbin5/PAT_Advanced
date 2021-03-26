#include <iostream>
using namespace std;
// #define DEBUG

const int SIZE = 200005;
int a[SIZE], n1, n2;

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &n1);
    for (int i = 0; i < n1; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &n2);
    int mid = (n1 + n2 - 1) >> 1, count = -1;
    int pos = 0, tmp;
    while (n2--) {
        scanf("%d", &tmp);
        while (pos < n1 && a[pos] <= tmp) {
            ++pos;
            ++count;
            if (count == mid) {
                printf("%d", a[pos - 1]);
                return 0;
            }
        }
        ++count;
        if (count == mid) {
            printf("%d", tmp);
            return 0;
        }
    }
    printf("%d", pos + mid - count - 1);
    return 0;
}