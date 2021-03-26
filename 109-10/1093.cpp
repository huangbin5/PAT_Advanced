#include <cstring>
#include <iostream>
using namespace std;
// #define DEBUG
const int MOD = 1000000007;

char str[100005];
int p[100005] = { 0 }, pa[100005] = { 0 }, pat[100005] = { 0 };

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%s", str);
    int len = strlen(str);
    if (len < 3) {
        printf("0\n");
        return 0;
    }
    if (str[0] == 'P')
        p[0] = 1;
    for (int i = 1; i < len; ++i) {
        switch (str[i]) {
        case 'P':
            p[i] = (p[i - 1] + 1) % MOD;
            pa[i] = pa[i - 1];
            pat[i] = pat[i - 1];
            break;
        case 'A':
            p[i] = p[i - 1];
            pa[i] = (pa[i - 1] + p[i - 1]) % MOD;
            pat[i] = pat[i - 1];
            break;
        case 'T':
            p[i] = p[i - 1];
            pa[i] = pa[i - 1];
            pat[i] = (pat[i - 1] + pa[i - 1]) % MOD;
            break;
        default:
            break;
        }
    }
    printf("%d\n", pat[len - 1]);
    return 0;
}