#include <algorithm>
#include <iostream>
using namespace std;
// #define DEBUG

//先记录每个爱好的人群，再依次合并每个爱好中的人，最后统计以每个人为根的人数
int n, parent[1005], hobby[1005], cnt[1005];

void init() {
    for (int id = 0; id < 1005; ++id) {
        //并查集的初始化
        parent[id] = id;
        //某个爱好的代表人
        hobby[id] = -1;
        //以某个人为根的人数
        cnt[id] = 0;
    }
}

int findRoot(int a) {
    if (a == parent[a])
        return a;
    int root = findRoot(parent[a]);
    parent[a] = root;
    return root;
}

int merge(int a, int b) {
    int ans = findRoot(b);
    parent[findRoot(a)] = ans;
    return ans;
}

bool cmp(int a, int b) { return a > b; }

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    init();
    scanf("%d", &n);
    int k, ho;
    for (int id = 0; id < n; ++id) {
        scanf("%d: ", &k);
        while (k--) {
            scanf("%d", &ho);
            if (hobby[ho] == -1)
                hobby[ho] = id;
            else
                hobby[ho] = merge(hobby[ho], id);
        }
    }
    for (int id = 0; id < n; ++id) {
        ++cnt[findRoot(id)];
    }
    sort(cnt, cnt + n, cmp);
    int count = 0;
    for (int id = 0; id < n; ++id) {
        if (cnt[id] > 0)
            ++count;
        else
            break;
    }
    printf("%d\n", count);
    for (int i = 0; i < count; ++i) {
        if (i)
            printf(" %d", cnt[i]);
        else
            printf("%d", cnt[i]);
    }
    return 0;
}