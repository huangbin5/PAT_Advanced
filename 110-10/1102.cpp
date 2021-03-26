#include <iostream>
#include <queue>
using namespace std;
// #define DEBUG

struct Node {
    int left = -1, right = -1;
} node[10];
bool flag[10] = { 0 }, first = true;

void levelTrav(int r) {
    queue<int> q;
    q.push(r);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now == r)
            printf("%d", now);
        else
            printf(" %d", now);
        if (node[now].right != -1)
            q.push(node[now].right);
        if (node[now].left != -1)
            q.push(node[now].left);
    }
    puts("");
}

void inTrav(int r) {
    if (r == -1)
        return;
    inTrav(node[r].right);
    if (first) {
        printf("%d", r);
        first = false;
    } else
        printf(" %d", r);
    inTrav(node[r].left);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, root;
    scanf("%d\n", &n);
    char left, right;
    for (int i = 0; i < n; ++i) {
        scanf("%c %c\n", &left, &right);
        if (left != '-') {
            node[i].left = left - '0';
            flag[left - '0'] = true;
        }
        if (right != '-') {
            node[i].right = right - '0';
            flag[right - '0'] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!flag[i]) {
            root = i;
            break;
        }
    }
    levelTrav(root);
    inTrav(root);
    return 0;
}