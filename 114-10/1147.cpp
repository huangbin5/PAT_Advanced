#include <iostream>
using namespace std;
// #define DEBUG

int k, n, levelOrder[1005];
// 0-未定，1-大顶堆，2-小顶堆，3-不是堆
int ans;

void judge() {
    for (int i = 1; 2 * i <= n; ++i) {
        if (2 * i + 1 > n)
            levelOrder[2 * i + 1] = levelOrder[2 * i];
        if (levelOrder[i] == levelOrder[2 * i] && levelOrder[i] == levelOrder[2 * i + 1]) {
            continue;
        } else if (levelOrder[i] >= levelOrder[2 * i] && levelOrder[i] >= levelOrder[2 * i + 1]) {
            if (ans == 2) {
                ans = 3;
                return;
            }
            ans = 1;
        } else if (levelOrder[i] <= levelOrder[2 * i] && levelOrder[i] <= levelOrder[2 * i + 1]) {
            if (ans == 1) {
                ans = 3;
                return;
            }
            ans = 2;
        } else {
            ans = 3;
            return;
        }
    }
}

void dfs(int i, bool last) {
    if (2 * i <= n)
        dfs(2 * i, 0);
    if (2 * i + 1 <= n)
        dfs(2 * i + 1, 0);
    if (last)
        printf("%d\n", levelOrder[i]);
    else
        printf("%d ", levelOrder[i]);
}

//左孩子2*i，右孩子2*i+1
int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d", &k, &n);
    while (k--) {
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &levelOrder[i]);
        }
        judge();
        if (ans == 1)
            printf("Max Heap\n");
        else if (ans == 2)
            printf("Min Heap\n");
        else if (ans == 3)
            printf("Not Heap\n");
        dfs(1, 1);
    }
    return 0;
}