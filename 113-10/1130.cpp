#include <cstring>
#include <iostream>
using namespace std;
// #define DEBUG

const int maxn = 25;
struct Node {
    char data[15];
    int left, right;
    Node() {}
    Node(char* _data, int _left, int _right)
        : left(_left)
        , right(_right) {
        strcpy(data, _data);
    }
} node[maxn];
bool notRoot[maxn] = { false };
int n, root;

void inTrav(int r) {
    if (node[r].left == -1 && node[r].right == -1) {
        printf("%s", node[r].data);
        return;
    }
    if (r != root)
        printf("(");
    if (node[r].left != -1)
        inTrav(node[r].left);
    printf("%s", node[r].data);
    if (node[r].right != -1)
        inTrav(node[r].right);
    if (r != root)
        printf(")");
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    char data[15];
    int left, right;
    for (int i = 1; i <= n; ++i) {
        scanf("%s%d%d", data, &left, &right);
        node[i] = Node(data, left, right);
        if (left != -1)
            notRoot[left] = true;
        if (right != -1)
            notRoot[right] = true;
    }
    for (int i = 1; i <= n; ++i) {
        if (!notRoot[i]) {
            root = i;
            break;
        }
    }
    inTrav(root);
    return 0;
}