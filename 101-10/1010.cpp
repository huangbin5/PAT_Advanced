#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
// #define DEBUG

const ll LL_MAX = (1ll << 63) - 1;

int toInt(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    return c - 'a' + 10;
}

ll transform(char* s, ll radix) {
    ll ans = 0;
    while (*s) {
        ans = ans * radix + toInt(*s);
        if (ans < 0)
            return LL_MAX;
        ++s;
    }
    return ans;
}

int findMin(char* s) {
    int ans = 2;
    while (*s) {
        if (toInt(*s) + 1 > ans)
            ans = toInt(*s) + 1;
        ++s;
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    char n1[15], n2[15];
    int mark, radix;
    scanf("%s%s%d%d", n1, n2, &mark, &radix);
    if (mark == 2)
        swap(n1, n2);
    // transform有可能溢出
    ll n = transform(n1, radix);
    //最小值要从合法的进制开始，否则有可能错误
    ll left = findMin(n2), right = n, mid;
    while (left < right) {
        mid = (left + right) >> 1;
        if (transform(n2, mid) >= n) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    if (transform(n2, left) == n)
        printf("%lld", left);
    else
        printf("Impossible");
    return 0;
}