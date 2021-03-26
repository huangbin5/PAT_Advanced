#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// #define DEBUG

const int maxn = 10005;
struct Node {
    int data;
    Node *left, *right;
    Node() {}
    Node(int _data)
        : data(_data) {}
} * root;
int preOrder[maxn], inOrder[maxn];
vector<int> uPath, vPath;
int n, m;

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

bool findPath(int x, vector<int>& path, Node* r) {
    if (!r) {
        return false;
    }
    if (x == r->data) {
        path.push_back(r->data);
        return true;
    }
    path.push_back(r->data);
    if (findPath(x, path, r->right))
        return true;
    path.pop_back();
    path.push_back(r->data);
    if (findPath(x, path, r->left))
        return true;
    path.pop_back();
    return false;
}

int findLCA() {
    int i = 0;
    while (i < uPath.size() && i < vPath.size() && uPath[i] == vPath[i])
        ++i;
    return uPath[i - 1];
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &inOrder[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &preOrder[i]);
    }
    root = build(0, n - 1, 0, n - 1);
    int u, v;
    while (m--) {
        uPath.clear();
        vPath.clear();
        scanf("%d%d", &u, &v);
        bool uFlag = findPath(u, uPath, root);
        bool vFlag = findPath(v, vPath, root);
        if (!(uFlag && vFlag)) {
            if (!(uFlag || vFlag))
                printf("ERROR: %d and %d are not found.\n", u, v);
            else if (!uFlag)
                printf("ERROR: %d is not found.\n", u);
            else
                printf("ERROR: %d is not found.\n", v);
            continue;
        }
        int lca = findLCA();
        if (lca == u)
            printf("%d is an ancestor of %d.\n", u, v);
        else if (lca == v)
            printf("%d is an ancestor of %d.\n", v, u);
        else
            printf("LCA of %d and %d is %d.\n", u, v, lca);
    }
    return 0;
}