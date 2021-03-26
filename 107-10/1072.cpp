#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
// #define DEBUG

struct Node {
    int v, e;
    Node() {}
    Node(int _v, int _e)
        : v(_v)
        , e(_e) {}
};

const int maxn = 1020;
const int maxInt = 0x3fffffff;
//房屋编号1-n，加油站编号n+1-n+m
int n, m, k, range;
vector<Node> edge[maxn];
bool visited[maxn];

int dist[maxn];
//到房屋最小距离的最大值
int maxDist = 0;
//在maxDist前提下到所有房屋平均值的最小值，即总计的最小值
int minTotal = maxInt;
int choose = 0;

void init() {
    fill(visited, visited + maxn, false);
    fill(dist, dist + maxn, maxInt);
}

int getId(char* s) {
    int add = 0;
    if (s[0] == 'G') {
        add = n;
        ++s;
    }
    int ans = 0, i = 0;
    while (s[i]) {
        ans = ans * 10 + s[i] - '0';
        ++i;
    }
    return ans + add;
}

void getDistance(int s) {
    init();
    int closest = maxInt, total = 0;
    dist[s] = 0;
    int u, minD;
    for (int k = 0; k < n + m; ++k) {
        //选择最小值
        u = -1, minD = maxInt;
        for (int i = 1; i <= n + m; ++i) {
            if (!visited[i] && dist[i] < minD) {
                u = i;
                minD = dist[i];
            }
        }
        visited[u] = true;
        if (u == -1)
            break;
        //如果是房屋
        if (u <= n) {
            if (dist[u] > range) {
                u = -1;
                break;
            }
            if (dist[u] < closest)
                closest = dist[u];
            total += dist[u];
        }
        //更新
        for (int i = 0; i < edge[u].size(); ++i) {
            int v = edge[u][i].v;
            int e = edge[u][i].e;
            if (!visited[v] && dist[u] + e < dist[v]) {
                dist[v] = dist[u] + e;
            }
        }
    }
    if (u != -1) {
        if (closest > maxDist) {
            maxDist = closest;
            minTotal = total;
            choose = s;
        } else if (closest == maxDist && total < minTotal) {
            minTotal = total;
            choose = s;
        } else if (closest == maxDist && total == minTotal && s < choose) {
            choose = s;
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d%d%d", &n, &m, &k, &range);
    char s1[10], s2[10];
    int e, v1, v2;
    while (k--) {
        scanf("%s%s%d", s1, s2, &e);
        v1 = getId(s1);
        v2 = getId(s2);
        edge[v1].push_back(Node(v2, e));
        edge[v2].push_back(Node(v1, e));
    }
    for (int i = n + 1; i <= n + m; ++i) {
        getDistance(i);
    }
    if (choose) {
        printf("G%d\n%.1f %.1f\n", choose - n, (double)maxDist, (double)minTotal / n);
    } else {
        printf("No Solution\n");
    }
    return 0;
}