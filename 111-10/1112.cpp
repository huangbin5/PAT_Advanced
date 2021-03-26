#include <cstring>
#include <iostream>
#include <map>
using namespace std;
// #define DEBUG

map<char, bool> mp;

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int k;
    scanf("%d", &k);
    char s[1005];
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        if (mp.count(s[i]) && !mp[s[i]])
            continue;
        int j;
        for (j = 1; j < k; ++j) {
            if (s[i + j] != s[i]) {
                mp[s[i]] = false;
                break;
            }
        }
        if (j == k)
            mp[s[i]] = true;
        i += j - 1;
    }
    char ans[1005];
    int pos = 0;
    for (int i = 0; i < len; ++i) {
        ans[pos++] = s[i];
        if (mp[s[i]]) {
            i += k - 1;
        }
    }
    ans[pos] = '\0';
    for (int i = 0; i < len; ++i) {
        if (mp[s[i]]) {
            printf("%c", s[i]);
            mp[s[i]] = false;
        }
    }
    printf("\n%s", ans);
    return 0;
}