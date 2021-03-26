#include <iostream>
using namespace std;
// #define DEBUG

struct Node {
    int data, next;
} node[100005];

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int start, n, k;
    scanf("%d%d%d", &start, &n, &k);
    int pos;
    while (n) {
        scanf("%d", &pos);
        scanf("%d%d", &node[pos].data, &node[pos].next);
        --n;
    }
    int t = start;
    while (t != -1) {
        t = node[t].next;
        ++n;
    }
    int first, pre = -1, cur, next, nnext = start, loop = n / k;
    while (loop--) {
        next = nnext;
        nnext = node[next].next;
        first = next;
        for (int i = 0; i < k - 1 && nnext != -1; ++i) {
            cur = next;
            next = nnext;
            nnext = node[next].next;
            node[next].next = cur;
        }
        if (pre != -1) {
            node[pre].next = next;
        } else {
            start = next;
        }
        pre = first;
    }
    if (pre != -1)
        node[pre].next = nnext;
    while (start != -1) {
        if (node[start].next == -1)
            printf("%05d %d -1\n", start, node[start].data);
        else
            printf("%05d %d %05d\n", start, node[start].data, node[start].next);
        start = node[start].next;
    }
    return 0;
}