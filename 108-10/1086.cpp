#include <iostream>
#include <stack>
#include <string>
using namespace std;
// #define DEBUG

struct Node {
    int data;
    Node *left, *right;
} * root;

int pre[30], in[30], post[30], n;

Node* create(int preL, int preR, int inL, int inR) {
    if (preL > preR)
        return NULL;
    Node* node = new Node;
    node->data = pre[preL];
    int boder;
    for (boder = inL; boder <= inR; ++boder) {
        if (in[boder] == pre[preL])
            break;
    }
    node->left = create(preL + 1, preL + boder - inL, inL, boder - 1);
    node->right = create(preL + boder - inL + 1, preR, boder + 1, inR);
    return node;
}

void postTraverse(Node* r) {
    if (!r)
        return;
    postTraverse(r->left);
    postTraverse(r->right);
    if (r == root)
        printf("%d", r->data);
    else
        printf("%d ", r->data);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    cin >> n;
    string op;
    int digit, preSize = 0, inSize = 0;
    stack<int> s;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> op;
        if (op[1] == 'u') {
            cin >> digit;
            s.push(digit);
            pre[preSize++] = digit;
        } else {
            in[inSize++] = s.top();
            s.pop();
        }
    }
    root = create(0, n - 1, 0, n - 1);
    postTraverse(root);
    return 0;
}