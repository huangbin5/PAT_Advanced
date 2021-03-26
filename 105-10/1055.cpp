#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
// #define DEBUG

struct people {
    char name[10];
    int age;
    int worth;
} p[100005];

bool cmp(people a, people b) {
    if (a.worth != b.worth)
        return a.worth > b.worth;
    if (a.age != b.age)
        return a.age < b.age;
    return strcmp(a.name, b.name) < 0;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int N, M, K, low, high;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%s%d%d", p[i].name, &p[i].age, &p[i].worth);
    }
    sort(p, p + N, cmp);
    for (int i = 1; i <= M; ++i) {
        bool flag = false;
        printf("Case #%d:\n", i);
        scanf("%d%d%d", &K, &low, &high);
        for (int j = 0; j < N && K; ++j) {
            if (p[j].age >= low && p[j].age <= high) {
                printf("%s %d %d\n", p[j].name, p[j].age, p[j].worth);
                flag = true;
                --K;
            }
        }
        if (!flag)
            printf("None\n");
    }
    return 0;
}