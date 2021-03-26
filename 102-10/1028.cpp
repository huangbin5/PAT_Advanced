#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
// #define DEBUG

struct student {
    int id;
    char name[10];
    int score;
} stu[100005];

bool cmp1(student a, student b) { return a.id < b.id; }
bool cmp2(student a, student b) {
    if (strcmp(a.name, b.name))
        return strcmp(a.name, b.name) < 0;
    return a.id < b.id;
}
bool cmp3(student a, student b) {
    if (a.score != b.score)
        return a.score < b.score;
    return a.id < b.id;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d%s%d", &stu[i].id, stu[i].name, &stu[i].score);
    }
    if (M == 1)
        sort(stu, stu + N, cmp1);
    if (M == 2)
        sort(stu, stu + N, cmp2);
    if (M == 3)
        sort(stu, stu + N, cmp3);
    for (int i = 0; i < N; ++i) {
        printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
    }
    return 0;
}