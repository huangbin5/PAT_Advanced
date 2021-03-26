#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// #define DEBUG

struct Node {
    int data;
    vector<int> child;
} tree[105];

bool cmp(int a, int b) { return tree[a].data > tree[b].data; }

int n, m, s, id, k, ch;
vector<int> path;

void printTree() {
    for (int i = 0; i < path.size(); ++i) {
        if (i == path.size() - 1) {
            printf("%d\n", tree[path[i]].data);
        } else {
            printf("%d ", tree[path[i]].data);
        }
    }
}

void dfs(int id, int sum) {
    path.push_back(id);
    sum += tree[id].data;
    if (sum <= s) {
        if (tree[id].child.empty()) {
            if (sum == s)
                printTree();
        } else {
            for (int i = 0; i < tree[id].child.size(); ++i) {
                dfs(tree[id].child[i], sum);
            }
        }
    }
    path.pop_back();
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tree[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &id, &k);
        while (k--) {
            scanf("%d", &ch);
            tree[id].child.push_back(ch);
        }
        sort(tree[id].child.begin(), tree[id].child.end(), cmp);
    }
    dfs(0, 0);
    return 0;
}