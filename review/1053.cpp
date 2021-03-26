#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define DEBUG

const int maxn = 105;
struct Node {
    int w;
    vector<int> son;
    Node() {}
    Node(int _w)
        : w(_w) {}
} node[maxn];
int n, m, s;
vector<int> path;
vector<vector<int>> ans;

bool cmp(vector<int>& a, vector<int>& b) {
    int i = 0;
    while (i < a.size() && i < b.size()) {
        if (a[i] != b[i])
            return a[i] > b[i];
        //记得i自增
        ++i;
    }
    //不能写true，写true相当于a>=b时返回了true
    /**
     * 比较函数在两个元素相等时必须返回false，否则可能会出现意想不到的错误
     */
    return false;
}

void dfs(int v, int sum) {
    path.push_back(node[v].w);
    if (node[v].son.empty()) {
        if (sum == s)
            ans.push_back(path);
        //这里不能写return
    } else {
        for (int i = 0; i < node[v].son.size(); ++i)
            dfs(node[v].son[i], sum + node[node[v].son[i]].w);
    }
    path.pop_back();
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif // DEBUG
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < n; ++i)
        scanf("%d", &node[i].w);
    int id, num, sid;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &id, &num);
        vector<int> v;
        for (int j = 0; j < num; ++j) {
            scanf("%d", &sid);
            v.push_back(sid);
        }
        node[id].son = v;
    }
    dfs(0, node[0].w);
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            if (j != ans[i].size() - 1)
                printf("%d ", ans[i][j]);
            else
                printf("%d\n", ans[i][j]);
        }
    }
    return 0;
}
