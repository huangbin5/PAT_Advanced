#include <iostream>
#include <vector>
using namespace std;
// #define DEBUG

const int maxn = 205;
// 0-没有边；1-有边；2-已访问
int matrix[maxn][maxn] = { 0 };
int n, m, k;
bool vFlag[maxn] = { false }, flag = true;
vector<int> query;

void init() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (matrix[i][j] == 2)
                matrix[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; ++i)
        vFlag[i] = false;
    query.clear();
    flag = true;
}

//注意：顶点是1-n，无向边要设置两个有向边
int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    int v1, v2;
    while (m--) {
        scanf("%d%d", &v1, &v2);
        matrix[v1][v2] = 1;
        matrix[v2][v1] = 1;
    }
    scanf("%d", &m);
    while (m--) {
        init();
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &v1);
            query.push_back(v1);
        }
        if (query[0] != query[query.size() - 1] || query.size() <= n) {
            printf("NO\n");
        } else {
            for (int i = 0; i < query.size() - 1; ++i) {
                v1 = query[i];
                v2 = query[i + 1];
                //点
                vFlag[v1] = true;
                //边
                if (matrix[v1][v2] == 1) {
                    matrix[v1][v2] = 2;
                    matrix[v2][v1] = 2;
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                for (int i = 1; i <= n; ++i) {
                    if (!vFlag[i]) {
                        flag = false;
                        break;
                    }
                }
            }
            printf(flag ? "YES\n" : "NO\n");
        }
    }
    return 0;
}