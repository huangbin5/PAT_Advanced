#include <iostream>
#include <stack>
using namespace std;
// #define DEBUG

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, b;
    scanf("%d %d", &n, &b);
    if (!n) {
        printf("Yes\n0");
        return 0;
    }
    stack<int> s;
    while (n) {
        s.push(n % b);
        n /= b;
    }
    int digit[40], idx = 0;
    while (!s.empty()) {
        digit[idx++] = s.top();
        s.pop();
    }
    bool flag = true;
    for (int i = 0; i <= idx / 2; ++i) {
        if (digit[i] != digit[idx - 1 - i]) {
            flag = false;
            break;
        }
    }
    if (flag)
        printf("Yes\n");
    else
        printf("No\n");
    for (int i = 0; i < idx; ++i) {
        if (i == 0)
            printf("%d", digit[i]);
        else
            printf(" %d", digit[i]);
    }
    return 0;
}