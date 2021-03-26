#include <algorithm>
#include <iostream>
using namespace std;
// #define DEBUG

int numArr[5];
int num;

void numToArr() {
    int n = num;
    for (int i = 3; i >= 0; --i) {
        numArr[i] = n % 10;
        n /= 10;
    }
}

int arrToNum() {
    num = 0;
    for (int i = 0; i < 4; ++i) {
        num = num * 10 + numArr[i];
    }
    return num;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &num);
    numToArr();
    for (;;) {
        sort(numArr, numArr + 4, greater<int>());
        int bigger = arrToNum();
        sort(numArr, numArr + 4);
        int smaller = arrToNum();
        num = bigger - smaller;
        numToArr();
        printf("%04d - %04d = %04d\n", bigger, smaller, num);
        if (num == 0 || num == 6174)
            break;
    }
    return 0;
}