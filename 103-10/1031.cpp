#include <cstring>
#include <iostream>
using namespace std;
// #define DEBUG

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    char s[85];
    scanf("%s", s);
    int len = strlen(s);
    int n1 = (len + 2) / 3, n3 = n1, n2 = len + 2 - n1 - n3;
    for (int i = 0; i < n1 - 1; ++i) {
        printf("%c", s[i]);
        for (int j = 0; j < n2 - 2; ++j)
            printf(" ");
        printf("%c\n", s[len - 1 - i]);
    }
    for (int i = 0; i < n2; ++i) {
        printf("%c", s[n1 - 1 + i]);
    }
    return 0;
}