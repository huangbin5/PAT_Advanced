#include <iostream>
using namespace std;
// #define DEBUG

struct student {
    char name[15];
    char gender;
    char id[15];
    int score;
} stu[1005];

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int N, minM = -1, maxF = -1;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s %c%s%d", stu[i].name, &stu[i].gender, stu[i].id, &stu[i].score);
        if (stu[i].gender == 'M' && (minM == -1 || stu[i].score < stu[minM].score))
            minM = i;
        if (stu[i].gender == 'F' && (maxF == -1 || stu[i].score > stu[maxF].score))
            maxF = i;
    }
    if (maxF == -1)
        printf("Absent\n");
    else
        printf("%s %s\n", stu[maxF].name, stu[maxF].id);
    if (minM == -1)
        printf("Absent\n");
    else
        printf("%s %s\n", stu[minM].name, stu[minM].id);
    if (maxF == -1 || minM == -1)
        printf("NA\n");
    else
        printf("%d\n", stu[maxF].score - stu[minM].score);
    return 0;
}