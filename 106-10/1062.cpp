#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
// #define DEBUG

int n, low, high;

struct student {
    char id[10];
    int virtue, talent, sum;
    int level;
} stu[100005];

int getLevel(student s) {
    if (s.virtue < low || s.talent < low)
        return 0;
    if (s.virtue >= high && s.talent >= high)
        return 4;
    if (s.virtue >= high)
        return 3;
    if (s.virtue >= s.talent)
        return 2;
    return 1;
}

bool cmp(student s1, student s2) {
    if (s1.level != s2.level)
        return s1.level > s2.level;
    if (s1.sum != s2.sum)
        return s1.sum > s2.sum;
    if (s1.virtue != s2.virtue)
        return s1.virtue > s2.virtue;
    return strcmp(s1.id, s2.id) < 0;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &low, &high);
    int size = 0;
    while (n--) {
        scanf("%s%d%d", &stu[size].id, &stu[size].virtue, &stu[size].talent);
        stu[size].level = getLevel(stu[size]);
        stu[size].sum = stu[size].virtue + stu[size].talent;
        if (stu[size].level > 0)
            ++size;
    }
    printf("%d\n", size);
    sort(stu, stu + size, cmp);
    for (int i = 0; i < size; ++i) {
        printf("%s %d %d\n", stu[i].id, stu[i].virtue, stu[i].talent);
    }
    return 0;
}