#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
// #define DEBUG

int n, k, p;
//保存k个数的数组
vector<int> tmp, ans;
// k个数的总和
int maxSum = 0;

int powp(int a) {
    int ans = 1;
    for (int i = 0; i < p; ++i)
        ans *= a;
    return ans;
}

void bfs(int a, int count, int sum, int powSum) {
    if (count == k && powSum == n) {
        if (sum > maxSum) {
            maxSum = sum;
            ans = tmp;
        }
        return;
    }
    if (count > k || a < 1 || powSum > n)
        return;
    tmp.push_back(a);
    //选择a，下一个应该继续从a开始试探
    bfs(a, count + 1, sum + a, powSum + powp(a));
    tmp.pop_back();
    //不选择a，下一个就一个从a-1开始试探
    bfs(a - 1, count, sum, powSum);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &k, &p);
    int start = pow((double)n, 1.0 / (double)p) + 1;
    bfs(start, 0, 0, 0);
    if (ans.size() > 0) {
        printf("%d = ", n);
        for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
            if (it == ans.begin())
                printf("%d^%d", *it, p);
            else
                printf(" + %d^%d", *it, p);
        }
    } else
        printf("Impossible");
    return 0;
}