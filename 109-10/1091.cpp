#include <iostream>
#include <queue>
using namespace std;
// #define DEBUG

const int maxa = 1286, maxb = 128, maxc = 60;
int a, b, c, t, ans = 0;
// pixel存放脑信息、flag标明是否访问过
int pixel[maxa][maxb][maxc], flag[maxa][maxb][maxc] = { 0 };
int x[6] = { 1, -1, 0, 0, 0, 0 }, y[6] = { 0, 0, 1, -1, 0, 0 }, z[6] = { 0, 0, 0, 0, 1, -1 };

struct Node {
    int i, j, k;
} node, tmpNode;

bool test(int i, int j, int k) {
    if (i < 0 || i >= a || j < 0 || j >= b || k < 0 || k >= c)
        return false;
    if (!pixel[i][j][k])
        return false;
    if (flag[i][j][k])
        return false;
    return true;
}

void bfs(int i, int j, int k) {
    int tmpAns = 0;
    queue<Node> q;
    node.i = i, node.j = j, node.k = k;
    q.push(node);
    flag[i][j][k] = 1;
    while (!q.empty()) {
        tmpNode = q.front();
        q.pop();
        ++tmpAns;
        for (int m = 0; m < 6; ++m) {
            i = tmpNode.i + x[m];
            j = tmpNode.j + y[m];
            k = tmpNode.k + z[m];
            if (test(i, j, k)) {
                node.i = i, node.j = j, node.k = k;
                q.push(node);
                flag[node.i][node.j][node.k] = 1;
            }
        }
    }
    if (tmpAns >= t)
        ans += tmpAns;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d%d%d", &a, &b, &c, &t);
    for (int k = 0; k < c; ++k) {
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                scanf("%d", &pixel[i][j][k]);
            }
        }
    }
    for (int k = 0; k < c; ++k) {
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                if (test(i, j, k)) {
                    bfs(i, j, k);
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}