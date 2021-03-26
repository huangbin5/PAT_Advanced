#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define DEBUG

struct Node {
    int idx, cnt;
    Node() {
        idx = 0;
        cnt = 0;
    };
    Node(int _idx, int _cnt)
        : idx(_idx)
        , cnt(_cnt) {}
    bool operator<(Node& tmp) {
        if (cnt != tmp.cnt)
            return cnt > tmp.cnt;
        return idx < tmp.idx;
    }
};

const int maxn = 50005;
int node[maxn] = { 0 };
bool exist[maxn] = { false };
Node maxk[15];
int n, k, ks = 0;

void handel(int j) {
    while (j > 0 && maxk[j] < maxk[j - 1]) {
        swap(maxk[j], maxk[j - 1]);
        //记得j-1
        --j;
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    int idx;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &idx);
        if (i) {
            printf("%d:", idx);
            for (int j = 0; j < k; ++j) {
                if (maxk[j].cnt == 0)
                    break;
                printf(" %d", maxk[j].idx);
            }
            puts("");
        }
        //次数加1
        ++node[idx];
        //如果已经是前k位，找到它并更新
        if (exist[idx]) {
            for (int j = 0; j < k; ++j) {
                if (maxk[j].idx == idx) {
                    ++maxk[j].cnt;
                    handel(j);
                    break;
                }
            }
        } else {
            //如果还不是前k位
            maxk[ks] = Node(idx, node[idx]);
            exist[idx] = true;
            handel(ks);
            //不足k个，直接加进去
            if (ks < k) {
                ++ks;
            } else {
                //已经有k个了，看能不能更新
                exist[maxk[k].idx] = false;
            }
        }
    }
    return 0;
}