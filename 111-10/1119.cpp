#include <iostream>
using namespace std;
#define DEBUG

int pre[30], post[30], n;
bool first = true, unique = true;

void print(int a, bool isPrint) {
    if (isPrint)
        if (first) {
            printf("%d", a);
            first = false;
        } else
            printf(" %d", a);
}

void inTrav(int preL, int preR, int postL, int postR, bool isPrint) {
    if (preL == preR) {
        print(pre[preL], isPrint);
        return;
    }
    int preLeft = preL + 1, postRight = postR - 1;
    //当只有一个分支时，将它归为左子树
    if (pre[preLeft] == post[postRight]) {
        inTrav(preLeft, preR, postL, postRight, isPrint);
        print(pre[preL], isPrint);
        unique = false;
    } else {
        int preRight, postLeft;
        for (preRight = preLeft + 1; preRight <= preR; ++preRight) {
            if (pre[preRight] == post[postRight])
                break;
        }
        for (postLeft = postRight - 1; postLeft >= postL; --postLeft) {
            if (post[postLeft] == pre[preLeft])
                break;
        }
        inTrav(preLeft, preRight - 1, postL, postLeft, isPrint);
        print(pre[preL], isPrint);
        inTrav(preRight, preR, postLeft + 1, postRight, isPrint);
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &post[i]);
    }
    inTrav(0, n - 1, 0, n - 1, 0);
    printf(unique ? "Yes\n" : "No\n");
    inTrav(0, n - 1, 0, n - 1, 1);
    puts("");
    return 0;
}