#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
#define DEBUG

const double eps = 1e-8;

bool check(char* s) {
    if (s[0] == '-')
        ++s;
    //只有一个负号
    if (!*s)
        return false;
    int len = strlen(s);
    char* dot = strchr(s, '.');
    //只允许出现0-9
    for (int i = 0; i < len; ++i) {
        if (s + i != dot && (s[i] < '0' || s[i] > '9'))
            return false;
    }
    //小数点后超过3位
    if (dot && s + len - 1 - dot > 2)
        return false;
    double in;
    sscanf(s, "%lf", &in);
    return in <= 1000;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, count = 0;
    scanf("%d", &n);
    double sum = 0, in;
    char s[100];
    while (n--) {
        scanf("%s", s);
        if (!check(s)) {
            printf("ERROR: %s is not a legal number\n", s);
            continue;
        }
        sscanf(s, "%lf", &in);
        sum += in;
        ++count;
    }
    printf("The average of %d ", count);
    if (count == 1)
        printf("number");
    else
        printf("numbers");
    printf(" is ");
    if (count)
        printf("%.2f", sum / count + eps);
    else
        printf("Undefined");
    return 0;
}