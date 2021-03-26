#include <iostream>
#include <queue>
using namespace std;
#define DEBUG

struct programmer {
    int weight;
    int rank = 0;
} pros[1005];
queue<int> order;

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int np, ng, tmp;
    scanf("%d%d", &np, &ng);
    for (int i = 0; i < np; ++i) {
        scanf("%d", &pros[i].weight);
    }
    for (int i = 0; i < np; ++i) {
        scanf("%d", &tmp);
        order.push(tmp);
    }
    int remain = np, curn, maxn, rankn = (remain - 1) / ng + 2;
    while (order.size() > 1) {
        for (int i = 0; i < ng && remain > 0; ++i) {
            curn = order.front();
            order.pop();
            --remain;
            pros[curn].rank = rankn;
            if (i == 0 || pros[curn].weight > pros[maxn].weight)
                maxn = curn;
        }
        order.push(maxn);
        if (remain == 0) {
            remain = order.size();
            rankn = (remain - 1) / ng + 2;
        }
    }
    pros[order.front()].rank = 1;
    for (int i = 0; i < np; ++i) {
        if (i)
            printf(" %d", pros[i].rank);
        else
            printf("%d", pros[i].rank);
    }
    return 0;
}