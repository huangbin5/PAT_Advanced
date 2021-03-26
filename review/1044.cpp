#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#define DEBUG

const int maxn = 100005;
int dio[maxn], n, m;
int minM = 0x3fffffff;
vector<pair<int, int>> ans;

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif // DEBUG
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &dio[i]);
    int i = 1, j = 1, sum = dio[1];
    while (j <= n) {
        if (sum < m) {
            ++j;
            if (j <= n)
                sum += dio[j];
        } else {
            if (sum < minM) {
                minM = sum;
                ans.clear();
                ans.push_back(make_pair(i, j));
            } else if (sum == minM) {
                ans.push_back(make_pair(i, j));
            }
            sum -= dio[i];
            ++i;
        }
    }
    for (i = 0; i < ans.size(); ++i) {
        printf("%d-%d\n", ans[i].first, ans[i].second);
    }
    return 0;
}
