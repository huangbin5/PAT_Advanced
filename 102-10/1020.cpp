#include <iostream>
#include <queue>
using namespace std;
// #define DEBUG

struct Node {
    int data;
    Node *left, *right;
} * root;

int post[30], in[30], n;

Node* initTree(int postL, int postR, int inL, int inR) {
    //递归基
    if (postL > postR) {
        return NULL;
    }
    //找出根节点并划分左右子树
    Node* r = new Node;
    r->data = post[postR];
    int leftNum;
    for (int i = inL; i <= inR; ++i) {
        if (in[i] == r->data) {
            leftNum = i - inL;
            break;
        }
    }
    //递归生成左右子树
    r->left = initTree(postL, postL + leftNum - 1, inL, inL + leftNum - 1);
    r->right = initTree(postL + leftNum, postR - 1, inL + leftNum + 1, inR);
    return r;
}

void levelTrav(Node* r) {
    queue<Node*> q;
    q.push(r);
    bool first = true;
    while (!q.empty()) {
        Node* tmp = q.front();
        q.pop();
        if (first) {
            printf("%d", tmp->data);
            first = false;
        } else
            printf(" %d", tmp->data);
        if (tmp->left)
            q.push(tmp->left);
        if (tmp->right)
            q.push(tmp->right);
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }
    root = initTree(0, n - 1, 0, n - 1);
    levelTrav(root);
    return 0;
}