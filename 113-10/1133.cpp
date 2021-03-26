#include <iostream>
using namespace std;
// #define DEBUG

const int maxn = 100005;
struct Node {
    int data, next;
    Node() { next = -2; }
    Node(int _data, int _next)
        : data(_data)
        , next(_next) {}
} list[maxn];
int start, n, k, idx;
bool hasPrint = false;

void printRange(int left, int right) {
    idx = start;
    while (idx != -1) {
        if (list[idx].data >= left && list[idx].data <= right) {
            if (hasPrint)
                printf("%05d\n%05d %d ", idx, idx, list[idx].data);
            else {
                printf("%05d %d ", idx, list[idx].data);
                hasPrint = true;
            }
        }
        idx = list[idx].next;
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d%d", &start, &n, &k);
    int id, data, next;
    while (n--) {
        scanf("%d%d%d", &id, &data, &next);
        list[id] = Node(data, next);
    }
    printRange(-maxn, -1);
    printRange(0, k);
    printRange(k + 1, maxn);
    printf("-1\n");
    return 0;
}