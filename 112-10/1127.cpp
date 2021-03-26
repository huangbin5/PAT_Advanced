#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
// #define DEBUG

struct Node {
    int data;
    Node *left, *right;
    Node(int _data)
        : data(_data)
        , left(NULL)
        , right(NULL) {}
} * root;

const int maxn = 30;
int inOrder[maxn], postOrder[maxn];
stack<Node*> s1, s2;

Node* build(int inL, int inR, int postL, int postR) {
    if (inL > inR) {
        return NULL;
    } else {
        Node* r = new Node(postOrder[postR]);
        int mid = 0;
        while (inOrder[mid] != postOrder[postR])
            ++mid;
        r->left = build(inL, mid - 1, postL, postL + mid - inL - 1);
        r->right = build(mid + 1, inR, postL + mid - inL, postR - 1);
        return r;
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
        scanf("%d", &inOrder[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &postOrder[i]);
    }
    root = build(0, n - 1, 0, n - 1);
    bool rToL = true, first = true;
    s1.push(root);
    while (!(s1.empty() && s2.empty())) {
        // true：s2从右到左入栈
        // false：s1从左到右入栈
        Node* tmp;
        if (rToL) {
            while (!s1.empty()) {
                tmp = s1.top();
                s1.pop();
                if (first) {
                    printf("%d", tmp->data);
                    first = false;
                } else {
                    printf(" %d", tmp->data);
                }
                if (tmp->right)
                    s2.push(tmp->right);
                if (tmp->left)
                    s2.push(tmp->left);
            }
        } else {
            while (!s2.empty()) {
                tmp = s2.top();
                s2.pop();
                printf(" %d", tmp->data);
                if (tmp->left)
                    s1.push(tmp->left);
                if (tmp->right)
                    s1.push(tmp->right);
            }
        }
        rToL = !rToL;
    }
    return 0;
}