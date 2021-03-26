#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define DEBUG

const int maxn = 10005;
const int open = 8 * 60 * 60;
const int close = 17 * 60 * 60;
struct Man {
    int t1, t2, proc;
} man[maxn];
int n, k;

bool cmp1(Man& a, Man& b) { return a.t1 < b.t1; }

struct cmp2 {
    bool operator()(int a, int b) { return man[a].t2 > man[b].t2; }
};

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif // DEBUG
    scanf("%d%d", &n, &k);
    int a, b, c, d;
    for (int i = 0; i < n; ++i) {
        scanf("%d:%d:%d %d", &a, &b, &c, &d);
        man[i].t1 = a * 60 * 60 + b * 60 + c;
        man[i].proc = d * 60;
    }
    sort(man, man + n, cmp1);
    priority_queue<int, vector<int>, cmp2> pq;
    int i;
    for (i = 0; i < min(n, k); ++i) {
        man[i].t2 = max(open, man[i].t1) + man[i].proc;
        pq.push(i);
    }
    int tot = 0, cnt = 0;
    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        ++cnt;
        tot += man[cur].t2 - man[cur].t1 - man[cur].proc;
        // printf("%d\t%02d:%02d:%02d\t%02d:%02d:%02d\n",cur,man[cur].t1/3600,man[cur].t1%3600/60,man[cur].t1%60,man[cur].t2/3600,man[cur].t2%3600/60,man[cur].t2%60);
        if (i < n && man[i].t1 <= close) {
            man[i].t2 = max(man[cur].t2, man[i].t1) + man[i].proc;
            pq.push(i++);
        }
    }
    printf("%.1f", (double)tot / 60 / cnt);
    return 0;
}
