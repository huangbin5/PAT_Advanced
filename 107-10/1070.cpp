#include <algorithm>
#include <iostream>
using namespace std;
// #define DEBUG

struct mooncake {
    double inventory;
    double prices;
    double cost;
    bool operator<(mooncake m) { return cost > m.cost; }
} cake[1005];

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int kind;
    double demand;
    scanf("%d%lf", &kind, &demand);
    for (int i = 0; i < kind; ++i) {
        scanf("%lf", &cake[i].inventory);
    }
    for (int i = 0; i < kind; ++i) {
        scanf("%lf", &cake[i].prices);
        cake[i].cost = cake[i].prices / cake[i].inventory;
    }
    sort(cake, cake + kind);
    int i = 0;
    double ans = 0;
    while (demand > 0 && i < kind) {
        if (demand >= cake[i].inventory)
            ans += cake[i].prices;
        else
            ans += cake[i].cost * demand;
        demand -= cake[i].inventory;
        ++i;
    }
    printf("%.2f", ans);
    return 0;
}