#include <cmath>
#include <iostream>
#include <stack>
using namespace std;
// #define DEBUG

const int maxn = 100005;
const int blockNum = 317;
int block[blockNum] = { 0 }, cnt[maxn] = { 0 };
stack<int> num;

void median() {
    int tar = (num.size() + 1) >> 1;
    int total = 0, bIdx = 0;
    while (total + block[bIdx] < tar) {
        total += block[bIdx];
        ++bIdx;
    }
    int nIdx = bIdx * blockNum;
    while (total + cnt[nIdx] < tar) {
        total += cnt[nIdx];
        ++nIdx;
    }
    printf("%d\n", nIdx);
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int m;
    scanf("%d", &m);
    char s[15];
    int a;
    while (m--) {
        scanf("%s", s);
        if (s[1] == 'u') {
            scanf("%d", &a);
            num.push(a);
            ++cnt[a];
            ++block[a / blockNum];
        } else if (s[1] == 'o') {
            if (num.empty())
                printf("Invalid\n");
            else {
                a = num.top();
                printf("%d\n", a);
                --cnt[a];
                --block[a / blockNum];
                num.pop();
            }
        } else {
            if (num.empty())
                printf("Invalid\n");
            else {
                median();
            }
        }
    }
    return 0;
}