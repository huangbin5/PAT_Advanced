#include <algorithm>
#include <iostream>
using namespace std;
// #define DEBUG

enum RB_COLOR { BLACK, RED };
struct Node {
    int data;
    Node *left, *right;
    Node(int _data)
        : data(_data) {}
} * root;
int k, n, preOrder[30], inOrder[30], maxLevel;

bool cmp(int a, int b) { return abs(a) < abs(b); }

Node* build(int preL, int preR, int inL, int inR) {
    if (preL > preR)
        return NULL;
    Node* ans = new Node(preOrder[preL]);
    int mid = inL;
    while (inOrder[mid] != preOrder[preL])
        ++mid;
    ans->left = build(preL + 1, preL + mid - inL, inL, mid - 1);
    ans->right = build(preL + mid - inL + 1, preR, mid + 1, inR);
    return ans;
}

bool dfs(Node* x, RB_COLOR color, int level) {
    if (!x) {
        if (maxLevel != 0)
            return level == maxLevel;
        maxLevel = level;
        return true;
    }
    if (!x->left || x->left->data > 0) {
        if (!dfs(x->left, BLACK, level + 1))
            return false;
    } else if (color == RED)
        return false;
    else if (!dfs(x->left, RED, level))
        return false;
    if (!x->right || x->right->data > 0)
        return dfs(x->right, BLACK, level + 1);
    else if (color == RED)
        return false;
    else
        return dfs(x->right, RED, level);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &preOrder[i]);
            inOrder[i] = preOrder[i];
        }
        //根节点颜色
        if (preOrder[0] < 0) {
            printf("No\n");
            continue;
        }
        sort(inOrder, inOrder + n, cmp);
        root = build(0, n - 1, 0, n - 1);
        maxLevel = 0;
        printf(dfs(root, BLACK, 1) ? "Yes\n" : "No\n");
    }
    return 0;
}