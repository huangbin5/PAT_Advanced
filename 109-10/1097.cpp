#include <algorithm>
#include <iostream>
using namespace std;
// #define DEBUG

struct Node {
    int pos, data, next;
} node[100005];
bool flag[10005] = { 0 };

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, start1;
    scanf("%d%d", &start1, &n);
    while (n--) {
        int tmp;
        scanf("%d", &tmp);
        node[tmp].pos = tmp;
        scanf("%d%d", &node[tmp].data, &node[tmp].next);
    }
    int a = start1, start2 = -1, pre1 = -1, pre2 = -1;
    while (a != -1) {
        if (flag[abs(node[a].data)]) {
            if (pre2 == -1) {
                start2 = a;
            } else {
                node[pre2].next = a;
            }
            pre2 = a;
        } else {
            flag[abs(node[a].data)] = true;
            if (pre1 != -1) {
                node[pre1].next = a;
            }
            pre1 = a;
        }
        a = node[a].next;
    }
    node[pre1].next = -1;
    if (pre2 != -1) {
        node[pre2].next = -1;
    }
    while (start1 != -1) {
        if (node[start1].next == -1)
            printf("%05d %d -1\n", node[start1].pos, node[start1].data);
        else
            printf("%05d %d %05d\n", node[start1].pos, node[start1].data, node[start1].next);
        start1 = node[start1].next;
    }
    while (start2 != -1) {
        if (node[start2].next == -1)
            printf("%05d %d -1\n", node[start2].pos, node[start2].data);
        else
            printf("%05d %d %05d\n", node[start2].pos, node[start2].data, node[start2].next);
        start2 = node[start2].next;
    }
    return 0;
}