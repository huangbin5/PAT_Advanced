#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
// #define DEBUG

const int maxn = 10005;
int n;
int level[maxn];
vector<int> edge[maxn];
bool inq[maxn] = { false };

//寻找可能的root
vector<int> candidate;
//所有root以及从其得到最底层的并集
set<int> ans;
int maxLevel = 0;

void init() { fill(inq, inq + maxn, false); }

void bfs(int u) {
    queue<int> q;
    q.push(u);
    inq[u] = true;
    level[u] = 1;
    maxLevel = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < edge[now].size(); ++i) {
            int v = edge[now][i];
            if (!inq[v]) {
                q.push(v);
                inq[v] = true;
                level[v] = level[now] + 1;
                if (maxLevel < level[v]) {
                    maxLevel = level[v];
                    candidate.clear();
                }
                candidate.push_back(v);
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    if (n <= 1) {
        printf("1\n");
        return 0;
    }
    int v1, v2;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &v1, &v2);
        edge[v1].push_back(v2);
        edge[v2].push_back(v1);
    }
    int block = 0;
    for (int i = 1; i <= n; ++i) {
        if (!inq[i]) {
            bfs(i);
            ++block;
        }
    }
    if (block > 1) {
        printf("Error: %d components\n", block);
    } else {
        init();
        for (int i = 0; i < candidate.size(); ++i) {
            ans.insert(candidate[i]);
        }
        bfs(candidate[0]);
        for (int i = 0; i < candidate.size(); ++i) {
            ans.insert(candidate[i]);
        }
    }
    for (set<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
        printf("%d\n", *it);
    }
    return 0;
}