#include <iostream>
#include <set>
#include <string>
using namespace std;
// #define DEBUG

int m, n, s;
char name[25];
set<string> vis;

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d%d%d", &m, &n, &s);
    if (s > m)
        printf("Keep going...\n");
    else {
        while (m--) {
            scanf("%s", name);
            --s;
            if (!s) {
                string sname(name);
                if (vis.count(sname)) {
                    ++s;
                } else {
                    printf("%s\n", name);
                    vis.insert(sname);
                    s = n;
                }
            }
        }
    }
    return 0;
}