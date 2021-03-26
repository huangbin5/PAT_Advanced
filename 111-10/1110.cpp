#include <iostream>
#include <queue>
using namespace std;
// #define DEBUG

struct Node {
    int left, right;
} node[20];
bool notRoot[20] = { 0 }, isFind[20] = { 0 }, stop = false;
int n, root, last;

int findRoot() {
    for (int i = 0; i < n; ++i) {
        if (!notRoot[i])
            return i;
    }
}

void levelTrav(int r) {
    queue<int> q;
    q.push(r);
    while (!q.empty()) {
        last = q.front();
        q.pop();
        isFind[last] = true;
        if (!stop) {
            if (node[last].left == -1)
                stop = true;
            else
                q.push(node[last].left);
            if (node[last].right == -1)
                stop = true;
            else if (!stop)
                q.push(node[last].right);
        }
    }
}

bool judge() {
    for (int i = 0; i < n; ++i) {
        if (!isFind[i])
            return false;
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d\n", &n);
    char tmp, c[2] = { ' ', '\n' };
    int digit;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            digit = 0;
            while ((tmp = getchar()) != EOF && tmp != c[j]) {
                if (tmp == '-')
                    digit = -1;
                else
                    digit = digit * 10 + tmp - '0';
            }
            if (digit != -1)
                notRoot[digit] = true;
            (j ? node[i].right : node[i].left) = digit;
        }
    }
    root = findRoot();
    levelTrav(root);
    if (judge())
        printf("YES %d", last);
    else
        printf("NO %d", root);
    return 0;
}