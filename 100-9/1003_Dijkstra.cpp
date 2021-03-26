#include <algorithm>
#include <iostream>
using namespace std;
// #define DEBUG

const int maxInt = 0x3fffffff;
const int maxn = 500;

int n, m, s, d;
int man[maxn];
int matrix[maxn][maxn];
bool visited[maxn] = { false };

//最短路径
int dist[maxn];
//能带的最多人数
int team[maxn] = { 0 };
//最短路径条数
int num[maxn] = { 0 };

void init() {
    fill(matrix[0], matrix[0] + maxn * maxn, maxInt);
    fill(dist, dist + maxn, maxInt);
}

void getMinDist() {
    dist[s] = 0;
    team[s] = man[s];
    num[s] = 1;
    for (;;) {
        //选择最近的顶点
        int u = -1, minDist = maxInt;
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }
        visited[u] = true;
        //到达目的地
        if (u == d) {
            printf("%d %d", num[u], team[u]);
            break;
        }
        //更新其它顶点的距离
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && matrix[u][i] != maxInt) {
                if (dist[u] + matrix[u][i] < dist[i]) {
                    dist[i] = dist[u] + matrix[u][i];
                    team[i] = team[u] + man[i];
                    num[i] = num[u];
                } else if (dist[u] + matrix[u][i] == dist[i]) {
                    num[i] += num[u];
                    //注意team更新的条件
                    if (team[u] + man[i] > team[i])
                        team[i] = team[u] + man[i];
                }
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    init();
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &man[i]);
    }
    int c1, c2, l;
    while (m--) {
        scanf("%d%d%d", &c1, &c2, &l);
        matrix[c1][c2] = matrix[c2][c1] = l;
    }
    getMinDist();
    return 0;
}