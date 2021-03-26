#include <cstring>
#include <iostream>
using namespace std;
// #define DEBUG

char juzi[105][260], ans[260];

void findAns(int idx) {
    int j = strlen(juzi[idx]) - 1;
    for (int i = strlen(ans) - 1; i >= 0 && j >= 0; --i, --j) {
        if (ans[i] != juzi[idx][j])
            break;
    }
    strcpy(ans, juzi[idx] + j + 1);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        getchar();
        scanf("%[^\n]", juzi[i]);
        if (!i)
            strcpy(ans, juzi[0]);
        else {
            findAns(i);
        }
    }
    if (strlen(ans))
        printf("%s", ans);
    else
        printf("nai");
    return 0;
}