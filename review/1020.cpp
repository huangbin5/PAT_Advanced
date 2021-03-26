#include <iostream>
#include <queue>
using namespace std;

const int maxn = 35;
int po[maxn], in[maxn];
struct Node {
    int d;
    Node *le, *ri;
    Node(int _d)
        : d(_d) {
        le = NULL;
        ri = NULL;
    }
} * ro;
int n;

Node* build(int pl, int pr, int il, int ir) {
    if (il > ir)
        return NULL;
    Node* r = new Node(po[pr]);
    int mi = 0;
    for (mi = il; mi <= ir; ++mi)
        if (in[mi] == po[pr])
            break;
    r->le = build(pl, pl + mi - il - 1, il, mi - 1);
    r->ri = build(pl + mi - il, pr - 1, mi + 1, ir);
    return r;
}

void lev() {
    queue<Node*> q;
    q.push(ro);
    while (!q.empty()) {
        Node* nd = q.front();
        q.pop();
        if (nd == ro)
            printf("%d", nd->d);
        else
            printf(" %d", nd->d);
        if (nd->le)
            q.push(nd->le);
        if (nd->ri)
            q.push(nd->ri);
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif // DEBUG
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &po[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &in[i]);
    ro = build(0, n - 1, 0, n - 1);
    lev();
    return 0;
}
