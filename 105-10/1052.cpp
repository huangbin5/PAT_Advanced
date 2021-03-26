#include <algorithm>
#include <iostream>
using namespace std;
#define DEBUG

struct Node {
    int pos, next, data, flag = 0;
} node[100005];

bool cmp(Node a, Node b) {
    if (a.flag != b.flag)
        return a.flag > b.flag;
    return a.data < b.data;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, p, cur, data, next;
    scanf("%d%d", &n, &p);
    while(n--) {
        scanf("%d%d%d", &cur, &data, &next);
        node[cur].pos = cur;
        node[cur].data = data;
        node[cur].next = next;
    }
    int count = 0;
    while (p != -1) {
        node[p].flag = 1;
        ++count;
        p = node[p].next;
    }
    sort(node, node + 100005, cmp);
    if (count)
        printf("%d %05d\n", count, node[0].pos);
    else
        printf("0 -1\n");
    for (int i = 0; i < count; ++i) {
        if (i == count - 1)
            printf("%05d %d -1\n", node[i].pos, node[i].data);
        else
            printf("%05d %d %05d\n", node[i].pos, node[i].data, node[i + 1].pos);
    }
    return 0;
}