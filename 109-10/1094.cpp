#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// #define DEBUG

struct Node {
    vector<int> child;
    int level;
} node[100];

/**
 * 最后bfs结束的时候还要再更新一次
 */
void bfs() {
    int maxLevel = 0, maxCount = 0;
    int level = 0, count = 0;
    node[1].level = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (node[now].level == level) {
            ++count;
        } else {
            if (count > maxCount) {
                maxLevel = level;
                maxCount = count;
            }
            level = node[now].level;
            count = 1;
        }
        for (int i = 0; i < node[now].child.size(); ++i) {
            node[node[now].child[i]].level = node[now].level + 1;
            q.push(node[now].child[i]);
        }
    }
    if (count > maxCount) {
        maxLevel = level;
        maxCount = count;
    }
    printf("%d %d\n", maxCount, maxLevel);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, m, id, k, child;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &id, &k);
        while (k--) {
            scanf("%d", &child);
            node[id].child.push_back(child);
        }
    }
    bfs();
    return 0;
}