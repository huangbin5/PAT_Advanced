#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define DEBUG

struct People {
    int vip, visited, arrive, serve, play;
    People() {}
    People(int _vip, int _visited, int _arrive, int _serve)
        : vip(_vip)
        , visited(_visited)
        , arrive(_arrive)
        , serve(_serve) {}
} player[10005];
struct Table {
    int vip = 0, finish, cnt = 0;
} table[105];
int openTime = 8 * 60 * 60, closeTime = 21 * 60 * 60;
int n, m, k;

int findTableForFirst(int idx) {
    int ans = 1;
    People& p = player[idx];
    //找到最小的和队首一样身份的桌子
    for (int i = 2; i <= m; ++i) {
        if (table[i].finish < table[ans].finish
            || (table[i].finish == table[ans].finish && table[ans].vip == 1 - p.vip && table[i].vip == p.vip)) {
            ans = i;
        }
    }
    //如果球桌结束时还没有人来，可以放宽时间
    if (table[ans].finish < p.arrive) {
        for (int i = 1; i <= m; ++i) {
            if (table[i].finish < p.arrive
                && ((table[ans].vip == 1 - p.vip && table[i].vip == p.vip) || (table[ans].vip == table[i].vip && i < ans))) {
                ans = i;
            }
        }
    }
    return ans;
}

bool cmpArrive(People a, People b) { return a.arrive < b.arrive; }
bool cmpPlay(People a, People b) {
    if (a.play != b.play)
        return a.play < b.play;
    return a.arrive < b.arrive;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    int hh, mm, ss, t, f;
    for (int i = 0; i < n; ++i) {
        scanf("%d:%d:%d%d%d", &hh, &mm, &ss, &t, &f);
        if (t > 120)
            t = 120;
        player[i] = People(f, 0, (hh * 60 + mm) * 60 + ss, t);
    }
    sort(player, player + n, cmpArrive);
    scanf("%d%d", &m, &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &f);
        table[f].vip = 1;
    }
    //初始化m张桌子
    for (int i = 1; i <= m; ++i) {
        table[i].finish = openTime;
    }
    int idx = 0, choose;
    //分配
    while (idx < n) {
        choose = findTableForFirst(idx);
        Table& tb = table[choose];
        int tmpIdx = idx;
        if (tb.vip == 1)
            while (
                tmpIdx < n && (player[tmpIdx].visited == 1 || (player[tmpIdx].arrive <= tb.finish && player[tmpIdx].vip == 0))) {
                ++tmpIdx;
            }
        if (tmpIdx >= n || player[tmpIdx].arrive > tb.finish)
            tmpIdx = idx;
        People& p = player[tmpIdx];
        if (p.arrive <= tb.finish) {
            p.play = tb.finish;
            tb.finish += p.serve * 60;
        } else {
            p.play = p.arrive;
            tb.finish = p.arrive + p.serve * 60;
        }
        if (p.play < closeTime)
            ++tb.cnt;
        p.visited = 1;
        while (player[idx].visited == 1)
            ++idx;
    }
    sort(player, player + n, cmpPlay);
    for (int i = 0; i < n; ++i) {
        People& p = player[i];
        if (p.play < closeTime) {
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", p.arrive / 3600, (p.arrive % 3600) / 60, p.arrive % 60, p.play / 3600,
                (p.play % 3600) / 60, p.play % 60, (int)round((p.play - p.arrive) / 60.0));
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (i == m)
            printf("%d\n", table[i].cnt);
        else
            printf("%d ", table[i].cnt);
    }
    return 0;
}