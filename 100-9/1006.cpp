#include <iostream>
using namespace std;
// #define DEBUG

struct times {
    int hh, mm, ss;
    bool operator<(const times t) {
        if (hh != t.hh)
            return hh < t.hh;
        else if (mm != t.mm)
            return mm < t.mm;
        else
            return ss < t.ss;
    }
};

struct person {
    char id[20];
    times in, out;
} stu[1005];

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    int M, unlock = 0, lock = 0;
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        // getchar();
        scanf("%s %d:%d:%d %d:%d:%d", stu[i].id, &stu[i].in.hh, &stu[i].in.mm, &stu[i].in.ss, &stu[i].out.hh, &stu[i].out.mm,
            &stu[i].out.ss);
        if (stu[i].in < stu[unlock].in)
            unlock = i;
        if (!(stu[i].out < stu[lock].out))
            lock = i;
    }
    printf("%s %s", stu[unlock].id, stu[lock].id);
    return 0;
}