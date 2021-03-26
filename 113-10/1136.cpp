#include <cstring>
#include <iostream>
using namespace std;
// #define DEBUG

struct BigInt {
    int d[1005], size;
    BigInt() { size = 0; }
    BigInt(char* s) {
        size = strlen(s);
        for (int i = 0; i < size; ++i) {
            d[size - 1 - i] = s[i] - '0';
        }
    }
    BigInt reverse() {
        BigInt ans;
        for (int i = 0; i < size; ++i) {
            ans.d[size - 1 - i] = d[i];
        }
        ans.size = size;
        return ans;
    }
    void operator+=(const BigInt bi) {
        int carry = 0, tmp;
        for (int i = 0; i < size; ++i) {
            tmp = d[i] + bi.d[i] + carry;
            d[i] = tmp % 10;
            carry = tmp / 10;
        }
        if (carry)
            d[size++] = carry;
    }
    bool isPalind() {
        for (int i = 0; i < (size >> 1); ++i) {
            if (d[i] != d[size - 1 - i])
                return false;
        }
        return true;
    }
    void printBigInt() {
        for (int i = size - 1; i >= 0; --i) {
            printf("%d", d[i]);
        }
    }
};

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    char s[1005];
    scanf("%s", s);
    BigInt ori(s);
    int cnt = 0;
    while (!ori.isPalind() && cnt < 10) {
        ori.printBigInt();
        printf(" + ");
        BigInt rev = ori.reverse();
        rev.printBigInt();
        printf(" = ");
        ori += rev;
        ori.printBigInt();
        puts("");
        ++cnt;
    }
    if (ori.isPalind()) {
        ori.printBigInt();
        printf(" is a palindromic number.");
    } else
        printf("Not found in 10 iterations.");
    return 0;
}