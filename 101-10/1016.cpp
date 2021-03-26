#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define DEBUG

int fee[24];

struct Call {
    char name[25];
    int mon, day, hour, minu;
    char status[10];
} call[1005];

bool cmp(Call a, Call b) {
    if (strcmp(a.name, b.name))
        return strcmp(a.name, b.name) < 0;
    if (a.day != b.day)
        return a.day < b.day;
    if (a.hour != b.hour)
        return a.hour < b.hour;
    return a.minu < b.minu;
}

int cacul(int start, int end) {
    printf("%02d:%02d:%02d %02d:%02d:%02d ", call[start].day, call[start].hour, call[start].minu, call[end].day, call[end].hour,
        call[end].minu);
    int day = call[start].day, hour = call[start].hour, stime = 0, sfee = 0;
    if (day == call[end].day && hour == call[end].hour) {
        stime = call[end].minu - call[start].minu;
        sfee = stime * fee[hour];
        printf("%d $%.2f\n", stime, 1.0 * sfee / 100);
        return sfee;
    }
    stime += 60 - call[start].minu;
    sfee += stime * fee[hour];
    for (;;) {
        ++hour;
        if (hour > 23) {
            hour = 0;
            ++day;
        }
        if (day == call[end].day && hour == call[end].hour) {
            stime += call[end].minu;
            sfee += (call[end].minu) * fee[hour];
            printf("%d $%.2f\n", stime, 1.0 * sfee / 100);
            return sfee;
        }
        stime += 60;
        sfee += 60 * fee[hour];
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    for (int i = 0; i < 24; ++i)
        scanf("%d", &fee[i]);
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s%d:%d:%d:%d%s", call[i].name, &call[i].mon, &call[i].day, &call[i].hour, &call[i].minu, call[i].status);
    }
    sort(call, call + N, cmp);
    int start = -1, total = 0;
    //判断这个人的信息是否已经输出过了
    bool isPrint = false;
    for (int i = 0; i < N; ++i) {
        //换人了
        if (i && strcmp(call[i].name, call[i - 1].name)) {
            if (isPrint)
                printf("Total amount: $%.2f\n", 1.0 * total / 100);
            start = -1, total = 0, isPrint = false;
        }
        if (strcmp(call[i].status, "on-line") == 0) {
            start = i;
        } else {
            if (start != -1) {
                if (!isPrint) {
                    printf("%s %02d\n", call[i].name, call[i].mon);
                    isPrint = true;
                }
                total += cacul(start, i);
                start = -1;
            }
        }
    }
    if (isPrint)
        printf("Total amount: $%.2f\n", 1.0 * total / 100);
    return 0;
}