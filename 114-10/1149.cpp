#include <iostream>
#include <map>
#include <vector>
using namespace std;
// #define DEBUG

map<int, int> intToId;
vector<int> edge[20005];
int query[1005];
int n, m, k, id;

int getId(int& x) {
    if (intToId.count(x))
        x = intToId[x];
    else
        x = intToId[x] = id++;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    int v1, v2;
    while (n--) {
        scanf("%d%d", &v1, &v2);
        getId(v1);
        getId(v2);
        edge[v1].push_back(v2);
        edge[v2].push_back(v1);
    }
    while (m--) {
        bool safe = true;
        scanf("%d", &k);
        for (int i = 0; i < k; ++i) {
            scanf("%d", &query[i]);
            getId(query[i]);
        }
        if (safe) {
            for (int i = 0; i < k; ++i) {
                for (int j = i + 1; j < k; ++j) {
                    for (int t = 0; t < edge[query[i]].size(); ++t) {
                        if (edge[query[i]][t] == query[j]) {
                            safe = false;
                            break;
                        }
                    }
                }
            }
        }
        if (safe)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}