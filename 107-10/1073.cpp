#include <cstring>
#include <iostream>
using namespace std;
// #define DEBUG

char in[10000], first[10000], second[10000];
int step = 0;

void getStep() {
    int i = 0;
    while (second[i]) {
        step = step * 10 + (second[i] - '0');
        ++i;
    }
}

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif
    scanf("%s", in);
    char* e = strchr(in, 'E');
    strncpy(first, in + 1, e - in - 1);
    strcpy(second, e + 2);
    getStep();
    if (in[0] == '-')
        printf("-");
    if (*(e + 1) == '-') {
        for (int i = 0; i < step; ++i) {
            if (i)
                printf("0");
            else
                printf("0.");
        }
        printf("%c%s", first[0], first + 2);
    } else {
        printf("%c", first[0]);
        if (step < strlen(first) - 2) {
            for (int i = 0; i < step; ++i) {
                printf("%c", *(first + 2 + i));
            }
            printf(".%s", first + 2 + step);
        } else {
            printf("%s", first + 2);
            for (int i = 0; i < step - strlen(first) + 2; ++i) {
                printf("0");
            }
        }
    }
    return 0;
}