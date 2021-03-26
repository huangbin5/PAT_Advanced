#include <iostream>
using namespace std;
// #define DEBUG

int num[100005];

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
    }
    int count = 0, lastPos = 0;
    for (;;) {
        if (num[0] == 0) {
            for (; lastPos < n; ++lastPos) {
                if (num[lastPos] != lastPos)
                    break;
            }
            if (lastPos == n)
                break;
            swap(num[0], num[lastPos]);
            ++count;
        }
        int i = 0;
        while (num[i] != 0) {
            int tmp = i;
            i = num[i];
            num[tmp] = tmp;
            ++count;
        }
        num[i] = i;
    }
    printf("%d", count);
    return 0;
}