#include <iostream>
using namespace std;
// #define DEBUG

struct Node {
    char data;
    int next;
    bool flag;
} node[100005];

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int p1, p2, n, cur, next;
    char data;
    scanf("%d%d%d", &p1, &p2, &n);
    while (n--) {
        scanf("%d %c %d", &cur, &data, &next);
        node[cur].data = data;
        node[cur].next = next;
        node[cur].flag = 0;
    }
    while (p1 != -1) {
        node[p1].flag = 1;
        p1 = node[p1].next;
    }
    while (p2 != -1) {
        if (node[p2].flag)
            break;
        node[p2].flag = 1;
        p2 = node[p2].next;
    }
    if (p2 == -1)
        printf("-1");
    else
        printf("%05d", p2);
    return 0;
}