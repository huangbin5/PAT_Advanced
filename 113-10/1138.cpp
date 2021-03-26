#include <iostream>
using namespace std;
// #define DEBUG

const int maxn = 50005;
int preOrder[maxn], inOrder[maxn];
int n;

int getPostFirst(int preL, int preR, int inL, int inR) {
    if (preL > preR)
        return 0;
    int mid = inL;
    while (inOrder[mid] != preOrder[preL])
        ++mid;
    int tmp = getPostFirst(preL + 1, preL + mid - inL, inL, mid - 1);
    if (tmp)
        return tmp;
    tmp = getPostFirst(preL + mid - inL + 1, preR, mid + 1, inR);
    if (tmp)
        return tmp;
    return preOrder[preL];
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &preOrder[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &inOrder[i]);
    }
    printf("%d", getPostFirst(0, n - 1, 0, n - 1));
    return 0;
}