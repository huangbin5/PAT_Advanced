#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define DEBUG

int arr[10000] = { 0 };

bool cmp(int a, int b) { return a > b; }

int main() {
#ifdef DEBUG
    freopen("d:\\input.txt", "r", stdin);
    freopen("d:\\output.txt", "w", stdout);
#endif // DEBUG
    for (int i = 0; i < 10000; ++i)
        arr[i] = 0;
    arr[0] = 1;
    sort(arr, arr + 10000, cmp);
    for (int i = 0; i < 10000; ++i)
        printf("%d ", arr[i]);
    return 0;
}
