#include <cstring>
#include <iostream>
using namespace std;
#define DEBUG

char num[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
char sym[3][5] = { "Qian", "Bai", "Shi" };
char ans[100][15];
int count = 0;

struct digit {
    char yi = 0, wan[5], ge[5];
    digit() {
        memset(wan, 0, 5);
        memset(ge, 0, 5);
    }
} d;

void handel(char* s, bool flag) {
    if (s[0] != '0') {
        sprintf(ans[count++], "%s %s", num[s[0] - '0'], sym[0]);
    }
    if (s[1] != '0') {
        if (flag && s[0] == '0') {
            sprintf(ans[count++], "%s", num[0]);
        }
        sprintf(ans[count++], "%s %s", num[s[1] - '0'], sym[1]);
    }
    if (s[2] != '0') {
        if (flag && s[1] == '0') {
            sprintf(ans[count++], "%s", num[0]);
        }
        sprintf(ans[count++], "%s %s", num[s[2] - '0'], sym[2]);
    }
    if (s[3] != '0') {
        if (flag && s[2] == '0') {
            sprintf(ans[count++], "%s", num[0]);
        }
        sprintf(ans[count++], "%s", num[s[3] - '0']);
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    char str[15], *s;
    scanf("%s", str);
    if (!strcmp(str, "0")) {
        printf("ling");
        return 0;
    }
    s = str;
    if (str[0] == '-') {
        strcpy(ans[count++], "Fu");
        ++s;
    }

    int len = strlen(s);
    if (len > 8)
        d.yi = s[0];
    int i;
    if (len > 4) {
        for (i = len - 5; i >= 0 && i >= len - 8; --i) {
            d.wan[i - len + 8] = s[i];
        }
        while (i >= len - 8)
            d.wan[i-- - len + 8] = '0';
    }
    for (i = len - 1; i >= 0 && i >= len - 4; --i) {
        d.ge[i - len + 4] = s[i];
    }
    while (i >= len - 4)
        d.ge[i-- - len + 4] = '0';

    if (d.yi)
        sprintf(ans[count++], "%s %s", num[d.yi - '0'], "Yi");
    if (strlen(d.wan)) {
        if (d.yi)
            handel(d.wan, true);
        else
            handel(d.wan, false);
        if (strcmp(d.wan, "0000"))
            sprintf(ans[count++], "%s", "Wan");
    }
    if (d.yi || strlen(d.wan))
        handel(d.ge, true);
    else
        handel(d.ge, false);

    for (int i = 0; i < count; ++i) {
        if (i)
            printf(" %s", ans[i]);
        else
            printf("%s", ans[i]);
    }
    return 0;
}