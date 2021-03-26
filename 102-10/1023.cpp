#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
// #define DEBUG

struct bigInt {
    int num[25] = { 0 };
    int len = 0;
    bigInt operator+(bigInt b) {
        bigInt ans;
        int carry = 0, i;
        for (i = 0; i < len || i < b.len; ++i) {
            int tmp = num[i] + b.num[i] + carry;
            ans.num[i] = tmp % 10;
            carry = tmp / 10;
        }
        if (carry) {
            ans.num[i++] = carry;
        }
        ans.len = i;
        return ans;
    }
} a;

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    char s[25];
    scanf("%s", s);
    a.len = strlen(s);
    for (int i = a.len - 1; i >= 0; --i) {
        a.num[a.len - 1 - i] = s[i] - '0';
    }
    bigInt b = a + a, c = b;
    if (a.len != b.len) {
        printf("No\n");
    } else {
        sort(a.num, a.num + a.len);
        sort(b.num, b.num + b.len);
        int i;
        for (i = 0; i < a.len; ++i) {
            if (a.num[i] != b.num[i])
                break;
        }
        if (i == a.len)
            printf("Yes\n");
        else
            printf("No\n");
    }
    for (int i = c.len - 1; i >= 0; --i) {
        printf("%d", c.num[i]);
    }
    return 0;
}