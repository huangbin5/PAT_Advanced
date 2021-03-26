#include <iostream>
#include <set>
using namespace std;
// #define DEBUG

int getFriend(int n) {
    int ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    set<int> s;
    int n, m;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &m);
        s.insert(getFriend(m));
    }
    printf("%d\n", s.size());
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        if (it == s.begin())
            printf("%d", *it);
        else
            printf(" %d", *it);
    }
    return 0;
}