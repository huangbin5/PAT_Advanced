#include <cstring>
#include <iostream>
using namespace std;
// #define DEBUG

int n, num, high, low;
char str[15];

//注意字符串转数字时str[i]指的是ASCII码
void cut() {
    int len = strlen(str);
    num = high = low = 0;
    for (int i = 0; i < (len >> 1); ++i) {
        high = high * 10 + str[i] - '0';
        num = num * 10 + str[i] - '0';
    }
    for (int i = (len >> 1); i < len; ++i) {
        low = low * 10 + str[i] - '0';
        num = num * 10 + str[i] - '0';
    }
}

//如果high和low其中一个为0，则返回false
bool judge() {
    if (!(high && low))
        return false;
    if (num % (high * low))
        return false;
    return true;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    while (n--) {
        scanf("%s", str);
        cut();
        printf(judge() ? "Yes\n" : "No\n");
    }
    return 0;
}