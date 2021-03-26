#include <cstring>
#include <iostream>
using namespace std;
#define DEBUG

struct bigInt {
    int len = 0;
    int num[100] = { 0 };
    bigInt operator+(bigInt a) {
        bigInt ans;
        int carry = 0;
        for (int i = 0; i < len || i < a.len; ++i) {
            int tmp = carry + num[i] + a.num[i];
            ans.num[ans.len++] = tmp % 10;
            carry = tmp / 10;
        }
        if (carry)
            ans.num[ans.len++] = carry;
        return ans;
    }
    bigInt operator+=(bigInt a) { *this = *this + a; }
};

bool isPalind(bigInt a) {
    int i = 0, j = a.len - 1;
    while (i < j) {
        if (a.num[i++] != a.num[j--])
            return false;
    }
    return true;
}

bigInt reverse(bigInt a) {
    int i = 0, j = a.len - 1;
    while (i < j)
        swap(a.num[i++], a.num[j--]);
    return a;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    char s[15];
    int k;
    scanf("%s%d", s, &k);
    bigInt a;
    a.len = strlen(s);
    for (int i = a.len - 1; i >= 0; --i) {
        a.num[a.len - 1 - i] = s[i] - '0';
    }
    int step = 0;
    while (step < k && !isPalind(a)) {
        a += reverse(a);
        ++step;
    }
    for (int i = a.len - 1; i >= 0; --i) {
        printf("%d", a.num[i]);
    }
    printf("\n%d", step);
    return 0;
}