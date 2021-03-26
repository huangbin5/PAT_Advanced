#include <iostream>
using namespace std;
// #define DEBUG

struct currency {
    int galleon, sickles, knuts;
} first, second, ans;

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%d.%d.%d %d.%d.%d", &first.galleon, &first.sickles, &first.knuts, &second.galleon, &second.sickles, &second.knuts);
    int carry = 0, tmp = first.knuts + second.knuts;
    ans.knuts = tmp % 29;
    carry = tmp / 29;
    tmp = first.sickles + second.sickles + carry;
    ans.sickles = tmp % 17;
    carry = tmp / 17;
    ans.galleon = first.galleon + second.galleon + carry;
    printf("%d.%d.%d", ans.galleon, ans.sickles, ans.knuts);
    return 0;
}