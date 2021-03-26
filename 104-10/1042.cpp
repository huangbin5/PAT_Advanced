#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
// #define DEBUG

char hs[5] = { 'S', 'H', 'C', 'D', 'J' };
string *ans = new string[54], *tmp = new string[54];
int times, order[54];

void init() {
    for (int i = 0; i < 54; ++i) {
        ans[i] += hs[i / 13] + to_string(i % 13 + 1);
    }
}

void print() {
    for (int i = 0; i < 54; ++i) {
        if (!i)
            cout << ans[i];
        else
            cout << " " << ans[i];
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    init();
    scanf("%d", &times);
    for (int i = 0; i < 54; ++i)
        scanf("%d", &order[i]);
    while (times--) {
        for (int i = 0; i < 54; ++i)
            tmp[order[i] - 1] = ans[i];
        swap(ans, tmp);
    }
    print();
    return 0;
}