#include <iostream>
using namespace std;
// #define DEBUG

const int maxn = 1005;
int board[maxn][maxn] = { 0 };
int row[maxn] = { 0 };
int n = 0, k;

void initBoard() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            board[i][j] = 0;
        row[i] = 0;
    }
}

bool rightAbove(int row, int col) {
    while (++row <= n && ++col <= n)
        if (board[row][col])
            return false;
    return true;
}

bool right(int row, int col) {
    while (++col <= n)
        if (board[row][col])
            return false;
    return true;
}

bool rightDown(int row, int col) {
    while (--row >= 1 && ++col <= n)
        if (board[row][col])
            return false;
    return true;
}

bool check() {
    //循环每一列
    for (int i = 1; i <= n; ++i) {
        if (!(right(row[i], i) && rightAbove(row[i], i) && rightDown(row[i], i)))
            return false;
    }
    return true;
}

// 右上：x+1, y+1
// 右下：x-1, y+1
// 右：  x,   y+1
int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d", &k);
    int r;
    while (k--) {
        initBoard();
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &r);
            board[r][i] = 1;
            row[i] = r;
        }
        printf(check() ? "YES\n" : "NO\n");
    }
    return 0;
}