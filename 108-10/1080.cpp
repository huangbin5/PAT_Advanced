#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// #define DEBUG

int quota[105];
vector<int> school[105];

struct student {
    int id;
    int score[2];
    int volun[5];
} s[40005];

bool cmp(student a, student b) {
    if (a.score[0] + a.score[1] != b.score[0] + b.score[1])
        return a.score[0] + a.score[1] > b.score[0] + b.score[1];
    return a.score[0] > b.score[0];
}

bool cmpId(int a, int b) { return s[a].id < s[b].id; }

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int N, M, K;
    //输入
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < M; ++i) {
        scanf("%d", &quota[i]);
    }
    for (int i = 0; i < N; ++i) {
        s[i].id = i;
        scanf("%d%d", &s[i].score[0], &s[i].score[1]);
        for (int j = 0; j < K; ++j) {
            scanf("%d", &s[i].volun[j]);
        }
    }
    sort(s, s + N, cmp);
    //录取
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            int idx = s[i].volun[j];
            if (quota[idx] > 0 || (!school[idx].empty() && !cmp(s[school[idx].back()], s[i]))) {
                school[idx].push_back(i);
                --quota[idx];
                break;
            }
        }
    }
    //输出
    for (int i = 0; i < M; ++i) {
        sort(school[i].begin(), school[i].end(), cmpId);
        for (vector<int>::iterator it = school[i].begin(); it != school[i].end(); ++it) {
            if (it == school[i].begin())
                printf("%d", s[*it].id);
            else
                printf(" %d", s[*it].id);
        }
        puts("");
    }
    return 0;
}