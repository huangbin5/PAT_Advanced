#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
// #define DEBUG

struct student {
    char name[15];
    char id[15];
    int score;
} s[10005];

bool cmp(student a, student b) { return a.score > b.score; }

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int N, low, high;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s%s%d", s[i].name, s[i].id, &s[i].score);
    }
    scanf("%d%d", &low, &high);
    sort(s, s + N, cmp);
    int i = 0;
    bool flag = false;
    while (i < N && s[i].score > high)
        ++i;
    for (; i < N; ++i) {
        if (s[i].score < low)
            break;
        flag = true;
        printf("%s %s\n", s[i].name, s[i].id);
    }
    if (!flag)
        printf("NONE\n");
    return 0;
}