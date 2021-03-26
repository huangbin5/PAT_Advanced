#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
//#define DEBUG

int idx;
pair<int, char> ran[1000000] = {};
char subject[4] = { 'A', 'C', 'M', 'E' };

struct student {
    int id;
    int score[4];
} stu[2005];

bool cmp(student s1, student s2) { return s1.score[idx] > s2.score[idx]; }

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d%d%d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
        stu[i].score[0] = stu[i].score[1] + stu[i].score[2] + stu[i].score[3];
    }
    int r;
    for (idx = 0; idx < 4; ++idx) {
        sort(stu, stu + N, cmp);
        for (int i = 0; i < N; ++i) {
            if (i == 0 || stu[i].score[idx] != stu[i - 1].score[idx])
                r = i + 1;
            if (idx == 0 || r < ran[stu[i].id].first)
                ran[stu[i].id] = make_pair(r, subject[idx]);
        }
    }
    int id;
    while (M--) {
        scanf("%d", &id);
        if (ran[id].first)
            printf("%d %c\n", ran[id].first, ran[id].second);
        else
            printf("N/A\n");
    }
    return 0;
}