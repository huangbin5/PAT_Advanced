#include <algorithm>
#include <iostream>
using namespace std;
// #define DEBUG

const int maxn = 205;
const int INF = 0x3fffffff;
int matrix[maxn][maxn] = { 0 };
int n, m, k, minDis = INF, minIdx;
bool vis[maxn] = { false };

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    int u, v, d;
    while (m--) {
        scanf("%d%d%d", &u, &v, &d);
        matrix[u][v] = matrix[v][u] = d;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        fill(vis, vis + maxn, false);
        bool NA = false, repeat = false;
        int totalDis = 0, start, finish;
        scanf("%d%d", &k, &u);
        start = u;
        while (--k) {
            scanf("%d", &v);
            if (!NA) {
                finish = v;
                if (matrix[u][v] == 0) {
                    NA = true;
                } else {
                    totalDis += matrix[u][v];
                    if (vis[v])
                        repeat = true;
                    else
                        vis[v] = true;
                }
                u = v;
            }
        }
        //有断路
        if (NA) {
            printf("Path %d: NA (Not a TS cycle)\n", i);
        } else {
            bool notCycle = false;
            for (int i = 1; i <= n; ++i) {
                if (!vis[i]) {
                    notCycle = true;
                    break;
                }
            }
            //有无访问节点或不是环
            if (notCycle || start != finish) {
                printf("Path %d: %d (Not a TS cycle)\n", i, totalDis);
            } else {
                if (repeat) {
                    //有重复节点
                    printf("Path %d: %d (TS cycle)\n", i, totalDis);
                } else {
                    printf("Path %d: %d (TS simple cycle)\n", i, totalDis);
                }
                if (totalDis < minDis) {
                    minDis = totalDis;
                    minIdx = i;
                }
            }
        }
    }
    printf("Shortest Dist(%d) = %d\n", minIdx, minDis);
    return 0;
}