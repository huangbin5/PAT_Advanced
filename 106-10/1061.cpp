#include <cstring>
#include <iostream>
using namespace std;
// #define DEBUG

char week[][4] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    char s1[60], s2[60], s3[60], s4[60];
    scanf("%s%s%s%s", s1, s2, s3, s4);
    int len1 = strlen(s1), len2 = strlen(s2), len3 = strlen(s3), len4 = strlen(s4);
    int pos = 1;
    for (int i = 0; i < len1 && i < len2; ++i) {
        if (s1[i] == s2[i]) {
            if (pos == 1 && s1[i] >= 'A' && s1[i] <= 'G') {
                printf("%s ", week[s1[i] - 'A']);
                ++pos;
            } else if (pos == 2) {
                if (s1[i] >= '0' && s1[i] <= '9') {
                    printf("0%c:", s1[i]);
                    break;
                } else if (s1[i] >= 'A' && s1[i] <= 'N') {
                    printf("%d:", s1[i] - 'A' + 10);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < len3 && i < len4; ++i) {
        if (s3[i] == s4[i] && ((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z'))) {
            printf("%02d", i);
        }
    }
    return 0;
}