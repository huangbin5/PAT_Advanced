#include <iostream>
using namespace std;
// #define DEBUG

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int m, n, in, count = 0, cadidate;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &in);
            if (count) {
                in == cadidate ? ++count : --count;
            } else {
                cadidate = in;
                count = 1;
            }
        }
    }
    printf("%d", cadidate);
    return 0;
}