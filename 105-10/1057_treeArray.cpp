#include <iostream>
#include <stack>
using namespace std;
#define lowbit(x) ((x) & (-x))
// #define DEBUG

const int maxn = 100005;
//树状数组
int c[maxn] = { 0 };

void update(int x, int v) {
    for (int i = x; i < maxn; i += lowbit(i)) {
        c[i] += v;
    }
}

int getSum(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        sum += c[i];
    }
    return sum;
}

int getK(int k) {
    int lo = 1, hi = maxn - 1, mid;
    //寻找第一个≥k的mid
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (getSum(mid) < k) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int m, a;
    scanf("%d", &m);
    char order[15];
    stack<int> s;
    while (m--) {
        scanf("%s", order);
        if (order[1] == 'u') {
            scanf("%d", &a);
            s.push(a);
            update(a, 1);
        } else if (order[1] == 'o') {
            if (s.empty()) {
                printf("Invalid\n");
            } else {
                a = s.top();
                s.pop();
                printf("%d\n", a);
                update(a, -1);
            }
        } else {
            if (s.empty()) {
                printf("Invalid\n");
            } else {
                printf("%d\n", getK((s.size() + 1) >> 1));
            }
        }
    }
    return 0;
}