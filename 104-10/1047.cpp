#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
// #define DEBUG

vector<int> cs[2505];
char name[40010][5];

bool cmp(int a, int b) { return strcmp(name[a], name[b]) < 0; }

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, k, ki, id;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d", name[i], &ki);
        while (ki--) {
            scanf("%d", &id);
            cs[id].push_back(i);
        }
    }
    for (int i = 1; i <= k; ++i) {
        printf("%d %d\n", i, cs[i].size());
        sort(cs[i].begin(), cs[i].end(), cmp);
        for (vector<int>::iterator it = cs[i].begin(); it != cs[i].end(); ++it) {
            printf("%s\n", name[*it]);
        }
    }
    return 0;
}