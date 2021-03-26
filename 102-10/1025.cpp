#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
// #define DEBUG

struct student {
    char id[15];
    int score;
    int location;
    int rank;
};

student students[30005];

bool cmp(student s1, student s2) { return (s1.score == s2.score) ? strcmp(s1.id, s2.id) < 0 : s1.score > s2.score; }

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int N, n, num = 0;
    scanf("%d", &N);
    for (int location = 1; location <= N; ++location) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            students[num].location = location;
            scanf("%s%d", students[num].id, &students[num].score);
            ++num;
        }
        sort(students + num - n, students + num, cmp);
        int rank;
        for (int i = num - n; i < num; ++i) {
            rank = (i != num - n && students[i].score == students[i - 1].score) ? rank : i + 1 - (num - n);
            students[i].rank = rank;
        }
    }
    printf("%d\n", num);
    sort(students, students + num, cmp);
    int totalRank;
    for (int i = 0; i < num; ++i) {
        totalRank = (i != 0 && students[i].score == students[i - 1].score) ? totalRank : i + 1;
        printf("%s %d %d %d\n", students[i].id, totalRank, students[i].location, students[i].rank);
    }
    return 0;
}