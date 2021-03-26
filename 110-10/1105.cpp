#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
// #define DEBUG

const int maxm = 100005;
const int maxn = 317;
int num[maxm];
int matrix[maxm][maxn];

bool cmp(int a, int b) { return a > b; }

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int N, m, n;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &num[i]);
    }
    n = sqrt(N);
    while (N % n) {
        --n;
    }
    m = N / n;
    sort(num, num + N, cmp);
    int idx = 0,i=0;
    //转的圈数是n/2
    for (int i = 0; i < n / 2; ++i) {
        //右
        for (int j = i; j < n - 1 - i; ++j) {
            matrix[i][j] = num[idx++];
        }
        //下
        for (int j = i; j < m - 1 - i; ++j) {
            matrix[j][n - 1 - i] = num[idx++];
        }
        //左
        for (int j = n - 1 - i; j > i; --j) {
            matrix[m - 1 - i][j] = num[idx++];
        }
        //上
        for (int j = m - 1 - i; j > i; --j) {
            matrix[j][i] = num[idx++];
        }
    }
    if (n & 1) {
        for (int i = n / 2; i < m - n / 2; ++i) {
            matrix[i][n / 2] = num[idx++];
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == n - 1) {
                printf("%d\n", matrix[i][j]);
            } else {
                printf("%d ", matrix[i][j]);
            }
        }
    }
    return 0;
}