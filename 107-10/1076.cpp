#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// #define DEBUG

struct Node {
    int id;
    int level;
    Node(int _id, int _level)
        : id(_id)
        , level(_level) {}
};

const int maxn = 1005;
vector<int> edge[maxn];
bool visited[maxn] = { false };
int n, l;

void resetVisited() {
    for (int i = 1; i <= n; ++i)
        visited[i] = false;
}

void bfs(int query) {
    int ans = -1, next;
    queue<Node> q;
    q.push(Node(query, 0));
    visited[query] = true;
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        ++ans;
        if (now.level < l)
            for (int i = 0; i < edge[now.id].size(); ++i) {
                next = edge[now.id][i];
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(Node(next, now.level + 1));
                }
            }
    }
    printf("%d\n", ans);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &l);
    int m, p;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &p);
            edge[p].push_back(i);
        }
    }
    int k, query;
    scanf("%d", &k);
    while (k--) {
        resetVisited();
        scanf("%d", &query);
        bfs(query);
    }
    return 0;
}