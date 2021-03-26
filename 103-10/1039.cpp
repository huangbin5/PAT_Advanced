#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
// #define DEBUG

map<string, set<int>> stu_cou;

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    int cou_id, cou_num;
    char stu[5];
    while (k--) {
        scanf("%d%d", &cou_id, &cou_num);
        while (cou_num--) {
            scanf("%s", stu);
            string str(stu);
            if (!stu_cou.count(str)) {
                stu_cou[str] = set<int>();
            }
            stu_cou[str].insert(cou_id);
        }
    }
    while (n--) {
        scanf("%s", stu);
        string str(stu);
        printf("%s %d", stu, stu_cou[str].size());
        for (set<int>::iterator it = stu_cou[str].begin(); it != stu_cou[str].end(); ++it) {
            printf(" %d", *it);
        }
        printf("\n");
    }
    return 0;
}