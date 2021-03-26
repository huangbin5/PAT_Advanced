#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define DEBUG

string num[10005];

bool cmp(string a, string b) { return a + b < b + a; }

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n;
    char tmp[10];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", tmp);
        num[i] = string(tmp);
    }
    sort(num, num + n, cmp);
    string ans;
    for (int i = 0; i < n; ++i) {
        ans += num[i];
    }
    const char* t = ans.c_str();
    while (*t == '0')
        ++t;
    if (*t)
        printf("%s", t);
    else
        printf("0");
    return 0;
}