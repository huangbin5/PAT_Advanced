#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define DEBUG

const int maxn = 1005;
const int open = 8 * 60;
const int close = 17 * 60;
struct Man {
    int id, t1, t2, proc;
    Man() {}
    Man(int _proc)
        : proc(_proc) {}
} man[maxn];
int n, m, k, r;

struct cmp {
    bool operator()(queue<int> a, queue<int> b) {
        if (man[a.front()].t2 != man[b.front()].t2)
            return man[a.front()].t2 > man[b.front()].t2;
        return man[a.front()].id > man[b.front()].id;
    }
};

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif // DEBUG
    scanf("%d%d%d%d", &n, &m, &k, &r);
    for (int i = 1; i <= k; ++i) {
        scanf("%d", &man[i].proc);
        man[i].id = i;
    }
    //前n个人8点服务
    for (int i = 1; i <= min(n, k); ++i) {
        man[i].t1 = open;
        man[i].t2 = man[i].t1 + man[i].proc;
    }
    priority_queue<queue<int>, vector<queue<int>>, cmp> pq;
    //将前n*m个人加入队列
    for (int i = 1; i <= n; ++i) {
        queue<int> q;
        for (int j = 0; j < m && i + j * n <= k; ++j)
            q.push(i + j * n);
        if (!q.empty())
            pq.push(q);
    }
    int next = min(n * m, k) + 1;
    while (!pq.empty()) {
        queue<int> q = pq.top();
        pq.pop();
        int cur = q.front();
        q.pop();
        // printf("%d\t%02d:%02d\t%02d:%02d\n",cur,man[cur].t1/60,man[cur].t1%60,man[cur].t2/60,man[cur].t2%60);
        if (next <= k)
            q.push(next++);
        if (!q.empty()) {
            int fr = q.front();
            man[fr].t1 = man[cur].t2;
            man[fr].t2 = man[fr].t1 + man[fr].proc;
            pq.push(q);
        }
    }
    for (int i = 0; i < r; ++i) {
        scanf("%d", &next);
        if (man[next].t1 >= close)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n", man[next].t2 / 60, man[next].t2 % 60);
    }
    return 0;
}
