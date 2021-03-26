#include <iostream>
#include <stack>
using namespace std;
// #define DEBUG

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);
    while (k--) {
        stack<int> s;
        int next = 1, cur;
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &cur);
            if (!flag)
                continue;
            while (s.size() <= m && (s.empty() || s.top() != cur)) {
                s.push(next++);
            }
            if (s.size() <= m) {
                s.pop();
            } else {
                flag = false;
            }
        }
        printf(flag ? "YES\n" : "NO\n");
    }
    return 0;
}