#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
// #define DEBUG

const int maxn = 10005;
//用秒数表示时间，不要用结构体，会超时！！！
const int openTime = 8 * 60 * 60, closeTime = 17 * 60 * 60;
struct people {
    int arrive, serve;
    people() {}
    people(int _arrive, int _serve)
        : arrive(_arrive)
        , serve(_serve) {}
    bool operator<(people p) { return arrive < p.arrive; }
} man[maxn];
int k, n;

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    int hh, mm, ss, t;
    for (int i = 0; i < n; ++i) {
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &t);
        int tmp = (hh * 60 + mm) * 60 + ss;
        if (closeTime < tmp) {
            --i;
            --n;
            continue;
        }
        man[i] = people(tmp, t);
    }
    sort(man, man + n);
    int ans = 0, idx = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    //先给k个人服务
    while (idx < n && idx < k) {
        if (man[idx].arrive < openTime) {
            ans += openTime - man[idx].arrive;
            //注意服务时间是分钟
            pq.push(openTime + man[idx].serve * 60);
        } else {
            pq.push(man[idx].arrive + man[idx].serve * 60);
        }
        ++idx;
    }
    //如果人数多于k，就要等待服务
    if (idx == k) {
        while (idx < n) {
            int tmp = pq.top();
            pq.pop();
            if (man[idx].arrive < tmp) {
                ans += tmp - man[idx].arrive;
                pq.push(tmp + man[idx].serve * 60);
            } else {
                pq.push(man[idx].arrive + man[idx].serve * 60);
            }
            ++idx;
        }
    }
    printf("%.1f", (double)ans / 60 / n);
    return 0;
}