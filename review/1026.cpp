/**
 * 非vip球员没有vip球桌和非vip球桌之分
 * 也就是说，当轮到非vip球员的时候，只是分配号码最小的球桌即可！！！
 * 日后再整理一遍，改的太乱了。。。
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define DEBUG

const int maxn = 10005;
const int open = 8 * 60 * 60;
const int close = 21 * 60 * 60;
const int two = 2 * 60 * 60;
struct Table {
    int id, vip, fTime, cnt;
} table[105];
struct cmpFree {
    bool operator()(int a, int b) { return table[a].id > table[b].id; }
};
struct cmpBusy {
    bool operator()(int a, int b) { return table[a].fTime > table[b].fTime; }
};
priority_queue<int, vector<int>, cmpFree> vip, nVip;
priority_queue<int, vector<int>, cmpBusy> busy;
struct People {
    int arrive, serve, play, vip;
    People() {}
    People(int _arrive, int _serve, int _play, int _vip)
        : arrive(_arrive)
        , serve(_serve)
        , play(_play)
        , vip(_vip) {}
};
vector<People> man;
int n, m, k;

bool cmpArr(People& a, People& b) { return a.arrive < b.arrive; }
bool cmpSer(People& a, People& b) { return a.serve < b.serve; }

int getTable(int i) {
    int a;
    if (man[i].vip == 0) {
        if (vip.empty()) {
            a = nVip.top();
            nVip.pop();
        } else if (nVip.empty()) {
            a = vip.top();
            vip.pop();
        } else {
            if (vip.top() < nVip.top()) {
                a = vip.top();
                vip.pop();
            } else {
                a = nVip.top();
                nVip.pop();
            }
        }
    } else {
        if (!vip.empty()) {
            a = vip.top();
            vip.pop();
        } else {
            a = nVip.top();
            nVip.pop();
        }
    }
    return a;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif // DEBUG
    //球员信息
    scanf("%d", &n);
    int a, b, c, d, e;
    for (int i = 0; i < n; ++i) {
        scanf("%d:%d:%d %d %d", &a, &b, &c, &d, &e);
        man.push_back(People(a * 60 * 60 + b * 60 + c, close, d * 60, e));
    }
    sort(man.begin(), man.end(), cmpArr);
    //球桌信息
    scanf("%d%d", &m, &k);
    for (int i = 1; i <= m; ++i) {
        table[i].id = i;
        table[i].vip = 0;
        table[i].cnt = 0;
        table[i].fTime = open;
    }
    for (int i = 0; i < k; ++i) {
        scanf("%d", &a);
        table[a].vip = 1;
    }
    for (int i = 1; i <= m; ++i) {
        if (table[i].vip == 0)
            nVip.push(i);
        else
            vip.push(i);
    }
    //对球员分配球桌
    int i = 0;
    while (i < n) {
        while (!busy.empty() && table[busy.top()].fTime <= man[i].arrive) {
            a = busy.top();
            busy.pop();
            if (table[a].vip == 0)
                nVip.push(a);
            else
                vip.push(a);
        }
        if (vip.empty() && nVip.empty()) {
            b = table[busy.top()].fTime;
            while (!busy.empty() && table[busy.top()].fTime == b) {
                a = busy.top();
                busy.pop();
                if (table[a].vip == 0)
                    nVip.push(a);
                else
                    vip.push(a);
            }
        }
        if (man[i].vip == 0 && !vip.empty()) {
            b = i;
            c = table[vip.top()].fTime;
            while (b < n && man[b].arrive <= c) {
                if (man[b].vip == 1) {
                    People pp = man[b];
                    man.erase(man.begin() + b);
                    man.insert(man.begin() + i, pp);
                    break;
                }
                ++b;
            }
        }
        a = getTable(i);
        man[i].serve = max(man[i].arrive, table[a].fTime);
        if (man[i].serve >= close)
            break;
        ++table[a].cnt;
        table[a].fTime = man[i].serve + min(man[i].play, two);
        busy.push(a);
        ++i;
    }
    sort(man.begin(), man.end(), cmpSer);
    for (i = 0; i < n; ++i) {
        if (man[i].serve < close) {
            a = man[i].arrive;
            b = man[i].serve;
            c = (b - a) / 60.0 + 0.5;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", a / 3600, a % 3600 / 60, a % 60, b / 3600, b % 3600 / 60, b % 60, c);
        } else
            break;
    }
    for (i = 1; i <= m; ++i) {
        if (i == 1)
            printf("%d", table[i].cnt);
        else
            printf(" %d", table[i].cnt);
    }
    return 0;
}
