#include <cstring>
#include <iostream>
#include <map>
using namespace std;
#define DEBUG

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    map<char, int> need;
    char s1[1005], s2[1005];
    scanf("%s%s", s1, s2);
    int len1 = strlen(s1), len2 = strlen(s2);
    for (int i = 0; i < len2; ++i) {
        ++need[s2[i]];
    }
    for (int i = 0; i < len1; ++i) {
        if (need[s1[i]])
            --need[s1[i]];
    }
    int count = 0;
    for (map<char, int>::iterator it = need.begin(); it != need.end(); ++it) {
        count += it->second;
    }
    if (count)
        printf("No %d", count);
    else
        printf("Yes %d", len1 - len2);
    return 0;
}