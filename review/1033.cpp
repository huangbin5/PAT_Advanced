#include <algorithm>
#include <iostream>
using namespace std;
#define DEBUG

const int maxn = 505;
struct Station {
    double dis, pri;
    Station() {}
} sta[maxn];
int n;
double des, dmax, per;

bool cmp(Station& a, Station& b) { return a.dis < b.dis; }

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif // DEBUG
    scanf("%lf%lf%lf%d", &dmax, &des, &per, &n);
    dmax *= per;
    //为了统一处理，构造两个虚拟加油站
    // dis设置为-1，不与已有加油站冲突；pri设置为0，计算的时候累计上去的价格为0
    sta[0].dis = -1;
    sta[0].pri = 0;
    for (int i = 1; i <= n; ++i)
        scanf("%lf%lf", &sta[i].pri, &sta[i].dis);
    sta[n + 1].dis = des;
    sta[n + 1].pri = 0;
    sort(sta, sta + n + 2, cmp);
    double ans = 0;
    //寻找下一个加油站
    // p-pre;c-current;n-next;f-farest;s-station
    int cs = 0, ns;
    double pf = 0, cf = 0;
    while (pf != des) {
        ns = -1;
        for (int i = cs + 1; i <= n + 1 && sta[i].dis <= cf; ++i) {
            if (sta[i].pri <= sta[cs].pri) {
                ns = i;
                break;
            }
            if (ns == -1 || sta[i].pri <= sta[ns].pri)
                ns = i;
        }
        //没找着，到达不了终点
        if (ns == -1) {
            printf("The maximum travel distance = %.2f", cf);
            return 0;
        }
        if (sta[ns].pri <= sta[cs].pri) {
            ans += (sta[ns].dis - pf) / per * sta[cs].pri;
            pf = sta[ns].dis;
        } else {
            ans += (cf - pf) / per * sta[cs].pri;
            pf = cf;
        }
        cs = ns;
        cf = sta[cs].dis + dmax;
    }
    printf("%.2f", ans);
    return 0;
}
