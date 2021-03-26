#include <cstring>
#include <iostream>
using namespace std;
// #define DEBUG

struct student {
    char name[15], pswd[15];
} stu[1005];

bool chagePswd(int idx) {
    bool ans = false;
    int len = strlen(stu[idx].pswd);
    for (int i = 0; i < len; ++i) {
        switch (stu[idx].pswd[i]) {
        case '1':
            stu[idx].pswd[i] = '@';
            ans = true;
            break;
        case '0':
            stu[idx].pswd[i] = '%';
            ans = true;
            break;
        case 'l':
            stu[idx].pswd[i] = 'L';
            ans = true;
            break;
        case 'O':
            stu[idx].pswd[i] = 'o';
            ans = true;
            break;
        default:
            break;
        }
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int N, count = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s%s", &stu[count].name, stu[count].pswd);
        if (chagePswd(count)) {
            ++count;
        }
    }
    if (count) {
        printf("%d\n", count);
        for (int i = 0; i < count; ++i) {
            printf("%s %s\n", stu[i].name, stu[i].pswd);
        }
    } else {
        printf("There %s %d %s and no account is modified\n", N > 1 ? "are" : "is", N, N > 1 ? "accounts" : "account");
    }
    return 0;
}