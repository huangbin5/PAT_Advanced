#include <algorithm>
#include <iostream>
using namespace std;
// #define DEBUG

int full[6];

struct student {
    int id;
    int score[6] = { -2, -2, -2, -2, -2, -2 };
    int total = -1;
    int perfect = 0;
} st[10005];

bool cmp(student a, student b) {
    if (a.total != b.total)
        return a.total > b.total;
    if (a.perfect != b.perfect)
        return a.perfect > b.perfect;
    return a.id < b.id;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int N, M, K;
    scanf("%d%d%d", &N, &K, &M);
    for (int i = 1; i <= K; ++i)
        scanf("%d", &full[i]);
    int userId, promId, score;
    while (M--) {
        scanf("%d%d%d", &userId, &promId, &score);
        st[userId].id = userId;
        //更新总分
        if (score > -1 && score > st[userId].score[promId]) {
            if (st[userId].total == -1)
                st[userId].total = 0;
            if (st[userId].score[promId] > -1)
                st[userId].total += score - st[userId].score[promId];
            else
                st[userId].total += score;
        }
        //更新满分题数
        if (st[userId].score[promId] != full[promId] && score == full[promId])
            ++st[userId].perfect;
        //更新某题分数
        if (score > st[userId].score[promId])
            st[userId].score[promId] = score;
    }
    sort(st + 1, st + N + 1, cmp);
    int r;
    for (int i = 1; i <= N; ++i) {
        if (st[i].total == -1)
            break;
        if (i == 1 || st[i].total != st[i - 1].total)
            r = i;
        printf("%d %05d %d", r, st[i].id, st[i].total);
        for (int j = 1; j <= K; ++j) {
            if (st[i].score[j] == -2)
                printf(" -");
            else if (st[i].score[j] == -1)
                printf(" 0");
            else
                printf(" %d", st[i].score[j]);
        }
        puts("");
    }
    return 0;
}