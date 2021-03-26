#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// #define DEBUG

struct Node {
    vector<int> child;
    double price;
    int amount;
    bool isRetailer;
} node[100005];

int n;
double p, r;

void bfs(int root) {
    double ans = 0;
    queue<int> q;
    node[root].price = p;
    q.push(root);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (node[now].isRetailer)
            ans += node[now].price * node[now].amount;
        else
            for (int i = 0; i < node[now].child.size(); ++i) {
                node[node[now].child[i]].price = node[now].price * (1.0 + r / 100.0);
                q.push(node[now].child[i]);
            }
    }
    printf("%.1f\n", ans);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%lf%lf", &n, &p, &r);
    int k, child;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        if (k) {
            while (k--) {
                scanf("%d", &child);
                node[i].child.push_back(child);
            }
            node[i].isRetailer = false;
        } else {
            scanf("%d", &node[i].amount);
            node[i].isRetailer = true;
        }
    }
    bfs(0);
    return 0;
}