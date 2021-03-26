#include <iostream>
#include <queue>
#include <utility>
using namespace std;
// #define DEBUG

int n, m, k, q, openTime = 8 * 60, closeTime = 17 * 60;
queue<pair<int, int>> line[20];
int endTime[1005];

int getShortestLine() {
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (line[i].size() < line[ans].size()) {
            ans = i;
        }
    }
    return ans;
}

int getFastestLine() {
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (line[i].front().second < line[ans].front().second) {
            ans = i;
        }
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d%d%d", &n, &m, &k, &q);
    int mm, choose;
    for (int i = 1; i <= k; ++i) {
        scanf("%d", &mm);
        if (i <= n * m) {
            choose = getShortestLine();
            if (line[choose].empty())
                //队首保存结束时间
                line[choose].push(make_pair(i, openTime + mm));
            else
                //非队首保存服务时间
                line[choose].push(make_pair(i, mm));
        } else {
            choose = getFastestLine();
            int t = line[choose].front().second;
            //保存结束时间
            endTime[line[choose].front().first] = t;
            line[choose].pop();
            //更新队首结束时间
            //注意不能仅仅判断t >= closeTime，t==-1也是
            if (t == -1 || t >= closeTime)
                line[choose].front().second = -1;
            else
                line[choose].front().second += t;
            line[choose].push(make_pair(i, mm));
        }
    }
    //清空每个队列
    for (int i = 0; i < n; ++i) {
        while (!line[i].empty()) {
            int t = line[i].front().second;
            endTime[line[i].front().first] = t;
            line[i].pop();
            if (!line[i].empty()) {
                if (t == -1 || t >= closeTime)
                    line[i].front().second = -1;
                else
                    line[i].front().second += t;
            }
        }
    }
    int query;
    while (q--) {
        scanf("%d", &query);
        if (endTime[query] == -1)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n", endTime[query] / 60, endTime[query] % 60);
    }
    return 0;
}