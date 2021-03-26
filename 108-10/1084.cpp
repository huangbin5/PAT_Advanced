#include <cstring>
#include <iostream>
#include <set>
using namespace std;
// #define DEBUG

set<char> isPrint;

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    char s1[100], s2[100];
    scanf("%s%s", s1, s2);
    int i = 0, j = 0, len = strlen(s1);
    while (i < len) {
        if (s1[i] == s2[j])
            ++j;
        else {
            if (!isPrint.count(toupper(s1[i]))) {
                printf("%c", toupper(s1[i]));
                isPrint.insert(toupper(s1[i]));
            }
        }
        ++i;
    }
    return 0;
}