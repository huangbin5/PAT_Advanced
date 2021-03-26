#include <algorithm>
#include <iostream>
using namespace std;
// #define DEBUG

double Cmax, D, Davg;
int N;

struct station {
    double Pi, Di;
    bool operator<(station s) { return Di < s.Di; }
} sta[505];

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &N);
    for (int i = 0; i < N; ++i) {
        scanf("%lf%lf", &sta[i].Pi, &sta[i].Di);
    }
    sta[N].Di = D;
    sta[N].Pi = 0;
    sort(sta, sta + N + 1);
    if (sta[0].Di) {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    double dist = 0, cost = 0;
    int cheapest = -1, cur = 1, last = 0;
    for (;;) {
        //寻找下一个最佳加油站
        while (cur <= N && sta[cur].Di - sta[last].Di <= Cmax * Davg) {
            if (sta[cur].Pi <= sta[last].Pi) {
                cheapest = cur;
                ++cur;
                break;
            }
            if (cheapest == -1 || sta[cur].Pi < sta[cheapest].Pi) {
                cheapest = cur;
            }
            ++cur;
        }
        //找不到说明到不了目的地
        if (cheapest == -1) {
            dist += Cmax * Davg;
            printf("The maximum travel distance = %.2f", dist);
            return 0;
        }
        //根据油价是否比上一个便宜分别处理
        if (sta[cheapest].Di > dist) {
            if (sta[cheapest].Pi <= sta[last].Pi) {
                cost += (sta[cheapest].Di - dist) / Davg * sta[last].Pi;
                dist = sta[cheapest].Di;
            } else {
                cost += (sta[last].Di + Cmax * Davg - dist) / Davg * sta[last].Pi;
                dist = sta[last].Di + Cmax * Davg;
            }
        }
        //到达目的地
        if (cheapest == N)
            break;
        last = cheapest;
        cheapest = -1;
    }
    printf("%.2f", cost);
    return 0;
}