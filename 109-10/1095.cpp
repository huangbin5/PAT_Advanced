#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
// #define DEBUG

struct Record {
    char name[10];
    int time;
    // 0-in, 1-out
    int status;
    //有效
    int use;
    Record() {}
} records[10005];
int n, q;
map<string, int> carTime;

bool cmpNameTime(Record a, Record b) {
    if (strcmp(a.name, b.name) == 0)
        return a.time < b.time;
    return strcmp(a.name, b.name) < 0;
}

bool cmpTime(Record a, Record b) { return a.time < b.time; }

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &q);
    int hh, mm, ss;
    char status[5];
    for (int i = 0; i < n; ++i) {
        scanf("%s %d:%d:%d %s", records[i].name, &hh, &mm, &ss, status);
        records[i].time = (hh * 60 + mm) * 60 + ss;
        records[i].status = strcmp(status, "in") ? 1 : 0;
        records[i].use = 1;
    }
    sort(records, records + n, cmpNameTime);
    //找出停留时间最长的车辆
    int longestTime = 0;
    //标识无效记录
    for (int i = 0; i < n; ++i) {
        //分进的或出的
        if (records[i].status == 0) {
            //上一个也是进的
            if (i != 0 && records[i - 1].status == 0) {
                records[i - 1].use = 0;
            }
        } else {
            //上一个不是自己的进的
            if (i == 0) {
                records[i].use = 0;
            } else {
                if (records[i - 1].status == 0) {
                    //更新车辆停留时间
                    if (strcmp(records[i].name, records[i - 1].name) == 0) {
                        string carName(records[i].name);
                        if (carTime.count(carName)) {
                            carTime[carName] += records[i].time - records[i - 1].time;
                        } else {
                            carTime[carName] = records[i].time - records[i - 1].time;
                        }
                        if (carTime[carName] > longestTime)
                            longestTime = carTime[carName];
                    } else {
                        records[i - 1].use = 0;
                        records[i].use = 0;
                    }
                } else {
                    records[i].use = 0;
                }
            }
        }
    }
    //最后一个记录如果是in也要设置为无效!!!!!
    if (records[n - 1].status == 0)
        records[n - 1].use = 0;
    sort(records, records + n, cmpTime);
    //计算车辆数变动的时间点并查询
    int cnt = 0, idx = 0, query;
    while (q--) {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        query = (hh * 60 + mm) * 60 + ss;
        while (idx < n && records[idx].time <= query) {
            if (records[idx].use == 1) {
                if (records[idx].status == 0)
                    ++cnt;
                else
                    --cnt;
            }
            ++idx;
        }
        printf("%d\n", cnt);
    }
    for (map<string, int>::iterator it = carTime.begin(); it != carTime.end(); ++it) {
        if (it->second == longestTime) {
            printf("%s ", it->first.c_str());
        }
    }
    printf("%02d:%02d:%02d\n", longestTime / 3600, (longestTime % 3600) / 60, longestTime % 60);
    return 0;
}