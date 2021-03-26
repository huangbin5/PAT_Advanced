#include <iostream>
using namespace std;
// #define DEBUG

struct Node {
    int data;
    Node *left, *right;
}* root = NULL;

int cnt[1005] = { 0 }, maxLevel = 0;

void insert(Node*& r, int a) {
    if (!r) {
        r = new Node;
        r->data = a;
        r->left = NULL;
        r->right = NULL;
    } else {
        if (a > r->data)
            insert(r->right, a);
        else
            insert(r->left, a);
    }
}

void trav(Node* r, int level) {
    if (!r)
        return;
    ++cnt[level];
    if (level > maxLevel)
        maxLevel = level;
    trav(r->left, level + 1);
    trav(r->right, level + 1);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, a;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        insert(root, a);
    }
    trav(root, 0);
    printf("%d + %d = %d\n", cnt[maxLevel], cnt[maxLevel - 1], cnt[maxLevel] + cnt[maxLevel - 1]);
    return 0;
}