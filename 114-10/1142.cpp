#include <iostream>
#include <vector>
using namespace std;
// #define DEBUG

const int maxn = 205;
int matrix[maxn][maxn] = { 0 };
vector<int> query;
int nv, ne, m, k;

/**
 * 看每两个顶点是否相邻，如果不是，则不是Clique
 * 看这些顶点的公共邻接点的集合是否为空，如果不为空，则不是最大的Clique
 * 否则为最大的Clique
 */
int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d", &nv, &ne);
    int u, v;
    while (ne--) {
        scanf("%d%d", &u, &v);
        matrix[u][v] = matrix[v][u] = 1;
    }
    scanf("%d", &m);
    while (m--) {
        query.clear();
        bool flag = true;
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &u);
            if (flag)
                for (int i = 0; i < query.size(); ++i) {
                    if (matrix[u][query[i]] == 0) {
                        flag = false;
                        break;
                    }
                }
            query.push_back(u);
        }
        if (!flag) {
            printf("Not a Clique\n");
            continue;
        }
        if (flag) {
            u = query[0];
            for (int i = 1; i <= nv; ++i) {
                if (flag && matrix[u][i] == 1) {
                    bool allOne = true;
                    //判断是否全1
                    for (int j = 1; j < query.size(); ++j) {
                        if (matrix[query[j]][i] == 0) {
                            allOne = false;
                            break;
                        }
                    }
                    //全1
                    if (allOne) {
                        flag = false;
                        printf("Not Maximal\n");
                        break;
                    }
                }
            }
        }
        if (flag)
            printf("Yes\n");
    }
    return 0;
}