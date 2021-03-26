#include <iostream>
#include <vector>
using namespace std;
// #define DEBUG

const int maxn = 1005;
int heap[maxn];
vector<int> path;
// 0-未定，1-小顶堆，2-大顶堆，3-不是堆
int n, ans = 0;

void dfs(int i) {
    path.push_back(heap[i]);
    if (2 * i > n) {
        printf("%d", path[0]);
        for (int i = 1; i < path.size(); ++i) {
            printf(" %d", path[i]);
            if (ans != 3) {
                if (path[i - 1] > path[i]) {
                    if (ans == 1)
                        ans = 3;
                    else
                        ans = 2;
                } else if (path[i - 1] < path[i]) {
                    if (ans == 2)
                        ans = 3;
                    else
                        ans = 1;
                }
            }
        }
        puts("");
    }
    if (2 * i + 1 <= n) {
        dfs(2 * i + 1);
    }
    if (2 * i <= n) {
        dfs(2 * i);
    }
    path.pop_back();
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &heap[i]);
    }
    dfs(1);
    if (ans == 1)
        printf("Min Heap\n");
    if (ans == 2)
        printf("Max Heap\n");
    if (ans == 3)
        printf("Not Heap\n");
    return 0;
}