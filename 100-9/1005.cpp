#include <cstring>
#include <iostream>
using namespace std;
#define DEBUG

const char* digit[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

void print(int n) {
    if (n < 10) {
        printf("%s", digit[n]);
        return;
    }
    print(n / 10);
    printf(" %s", digit[n % 10]);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    char s[105];
    scanf("%s", s);
    int sum = 0, len = strlen(s);
    for (int i = 0; i < len; ++i) {
        sum += (s[i] - '0');
    }
    print(sum);
    return 0;
}