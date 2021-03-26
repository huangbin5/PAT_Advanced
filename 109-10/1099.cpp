#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
// #define DEBUG

struct Node {
    int data;
    int left, right;
} node[105];

int arr[105], cnt = 0;

void inTrav(int r) {
    if (r == -1)
        return;
    inTrav(node[r].left);
    node[r].data = arr[cnt++];
    inTrav(node[r].right);
}

void levelTrav() {
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now)
            printf(" %d", node[now].data);
        else
            printf("%d", node[now].data);
        if (node[now].left != -1)
            q.push(node[now].left);
        if (node[now].right != -1)
            q.push(node[now].right);
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &node[i].left, &node[i].right);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    inTrav(0);
    levelTrav();
    return 0;
}