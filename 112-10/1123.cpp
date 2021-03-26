#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
// #define DEBUG

struct Node {
    int data;
    Node *left, *right;
    int height;
}* root = NULL;

void updateHeight(Node*& r);

int getHeight(Node* r) {
    if (r)
        return r->height;
    return 0;
}

Node* connect34(Node* c1, Node* a, Node* c2, Node* r, Node* c3, Node* b, Node* c4) {
    a->left = c1;
    a->right = c2;
    updateHeight(a);
    b->left = c3;
    b->right = c4;
    updateHeight(b);
    r->left = a;
    r->right = b;
    updateHeight(r);
    return r;
}

void adjust(Node*& r) {
    // r更高的孩子为a，a更高的孩子为b，以rab做3+4重构
    Node* a = getHeight(r->left) > getHeight(r->right) ? r->left : r->right;
    Node* b = getHeight(a->left) > getHeight(a->right) ? a->left : a->right;
    if (a == r->left) {
        if (b == a->left)
            //将父亲的孩子更新为调整之后的根节点
            r = connect34(b->left, b, b->right, a, a->right, r, r->right);
        else
            r = connect34(a->left, a, b->left, b, b->right, r, r->right);
    } else {
        if (b == a->left)
            r = connect34(r->left, r, b->left, b, b->right, a, a->right);
        else
            r = connect34(r->left, r, a->left, a, b->left, b, b->right);
    }
}

void updateHeight(Node*& r) {
    int lHeight = getHeight(r->left);
    int rHeight = getHeight(r->right);
    r->height = max(lHeight, rHeight) + 1;
    if (lHeight - rHeight < -1 || lHeight - rHeight > 1) {
        adjust(r);
    }
}

void insert(Node*& r, int a) {
    if (!r) {
        r = new Node;
        r->data = a;
        r->left = NULL;
        r->right = NULL;
        r->height = 1;
    } else {
        if (a > r->data)
            insert(r->right, a);
        else
            insert(r->left, a);
        updateHeight(r);
    }
}

void levelTrav() {
    bool isEnd = false, isCbt = true;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* now = q.front();
        q.pop();
        if (now == root)
            printf("%d", now->data);
        else
            printf(" %d", now->data);
        if (now->left) {
            q.push(now->left);
            if (isEnd)
                isCbt = false;
        } else
            isEnd = true;
        if (now->right) {
            q.push(now->right);
            if (isEnd)
                isCbt = false;
        } else
            isEnd = true;
    }
    printf("\n%s\n", isCbt ? "YES" : "NO");
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, m;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &m);
        insert(root, m);
    }
    levelTrav();
    return 0;
}