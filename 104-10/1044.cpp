#include <algorithm>
#include <iostream>
using namespace std;
#define DEBUG

struct solution {
    int start, end, loss;
} solu[100005];

int diomand[100005];

bool cmp(solution a, solution b) {
    if (a.loss != b.loss)
        return a.loss < b.loss;
    return a.start < b.start;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &diomand[i]);
    }
    int last = 1, sum = diomand[1], size = 0;
    for (int i = 1; i <= n; ++i) {
        while (last <= n && sum < m) {
            ++last;
            if (last > n)
                break;
            sum += diomand[last];
        }
        if (last > n)
            break;
        solu[size++] = { i, last, sum - m };
        sum -= diomand[i];
    }
    sort(solu, solu + size, cmp);
    for (int i = 0; i < size; ++i) {
        if (i && solu[i].loss != solu[i - 1].loss)
            break;
        printf("%d-%d\n", solu[i].start, solu[i].end);
    }
    return 0;
}