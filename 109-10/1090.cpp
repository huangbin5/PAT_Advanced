#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// #define DEBUG

struct Node {
    vector<int> child;
    double price;
    int level;
} node[100005];
int n, root;
double p, r;

void bfs() {
    int level = -1, count;
    double ans;
    queue<int> q;
    node[root].price = p;
    node[root].level = 1;
    q.push(root);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (node[now].level != level) {
            level = node[now].level;
            count = 1;
            ans = node[now].price;
        } else
            ++count;
        for (int i = 0; i < node[now].child.size(); ++i) {
            node[node[now].child[i]].level = node[now].level + 1;
            node[node[now].child[i]].price = node[now].price * (1 + r);
            q.push(node[now].child[i]);
        }
    }
    printf("%.2f %d\n", ans, count);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    int father;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &father);
        if (father == -1) {
            root = i;
        } else {
            node[father].child.push_back(i);
        }
    }
    bfs();
    return 0;
}