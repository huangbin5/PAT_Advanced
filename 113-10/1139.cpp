#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// #define DEBUG

const int maxn = 10000;
int gender[maxn] = { 0 };
int matrix[maxn][maxn] = { 0 };
vector<int> edge[maxn];
vector<pair<int, int>> ans;

void getNum(int& x) {
    char sign, c;
    sign = getchar();
    if (sign == '-')
        c = getchar();
    else
        c = sign;
    for (int i = 0; i < 4; ++i) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    if (sign == '-')
        gender[x] = 1;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, m;
    scanf("%d%d\n", &n, &m);
    int u, v;
    while (m--) {
        u = v = 0;
        getNum(u);
        getNum(v);
        matrix[u][v] = matrix[v][u] = 1;
        if (gender[u] == gender[v]) {
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
    }
    scanf("%d\n", &n);
    while (n--) {
        u = v = 0;
        getNum(u);
        getNum(v);
        ans.clear();
        sort(edge[u].begin(), edge[u].end());
        sort(edge[v].begin(), edge[v].end());
        for (int i = 0; i < edge[u].size(); ++i) {
            for (int j = 0; j < edge[v].size(); ++j) {
                if (edge[u][i] != v && edge[v][j] != u && matrix[edge[u][i]][edge[v][j]])
                    ans.push_back(make_pair(edge[u][i], edge[v][j]));
            }
        }
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); ++i) {
            printf("%04d %04d\n", ans[i].first, ans[i].second);
        }
    }
    return 0;
}