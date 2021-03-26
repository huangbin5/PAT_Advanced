#include <iostream>
using namespace std;
// #define DEBUG

int flag[130] = { 0 };

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    char s1[10005], s2[10005];
    scanf("%[^\n]\n%[^\n]", s1, s2);
    int i = 0;
    while (s2[i]) {
        flag[s2[i]] = 1;
        ++i;
    }
    i = 0;
    while (s1[i]) {
        if (!flag[s1[i]])
            printf("%c", s1[i]);
        ++i;
    }
    return 0;
}