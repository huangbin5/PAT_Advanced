#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define DEBUG

const int maxn = 105;
vector<int> son[maxn];
struct Node {
    int id, lev;
    Node(int _id, int _lev)
        : id(_id)
        , lev(_lev) {}
};
int n, m;

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif // DEBUG
    scanf("%d%d", &n, &m);
    int a, b, cnt;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &cnt);
        for (int j = 0; j < cnt; ++j) {
            scanf("%d", &b);
            son[a].push_back(b);
        }
    }
    queue<Node> q;
    q.push(Node(1, 0));
    int lev = 0;
    cnt = 0;
    while (!q.empty()) {
        Node nd = q.front();
        q.pop();
        if (nd.lev != lev) {
            printf("%d ", cnt);
            lev = nd.lev;
            cnt = 0;
        }
        if (son[nd.id].empty())
            ++cnt;
        else
            for (int i = 0; i < son[nd.id].size(); ++i) {
                q.push(Node(son[nd.id][i], nd.lev + 1));
            }
    }
    printf("%d", cnt);
    return 0;
}
