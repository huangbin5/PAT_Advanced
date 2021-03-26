#include <algorithm>
#include <iostream>
using namespace std;
#define DEBUG

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int N, dis[100005];
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &dis[i]);
    }
    sort(dis, dis + N, greater<int>());
    //记录大于当前元素的个数
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (!i || dis[i] != dis[i - 1]) {
            count = i;
        }
        if (dis[i] <= count) {
            if (count < dis[i - 1]) {
                printf("%d", count);
            } else {
                printf("%d", dis[i - 1] - 1);
            }
            return 0;
        }
    }
    printf("%d", min(dis[N - 1] - 1, N));
    return 0;
}